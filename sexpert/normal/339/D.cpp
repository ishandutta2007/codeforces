#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

struct node
{
	int l;
	int r;
	int val;
	node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val){}
};

node st[4*MAXN + 5];
int pos[4*MAXN + 5];

void build(int l, int r, int id)
{
	st[id] = node(l, r);
	if(l == r)
		pos[l] = id;
	else
	{
		build(l, (l + r)/2, 2*id);
		build((l + r)/2 + 1, r, 2*id + 1);
	}
}

void update(int lf, int val)
{
	int layer = 0;
	int id = pos[lf];
	st[id].val = val;
	while(id > 0)
	{
		layer++;
		id /= 2;
		if(layer % 2) st[id].val = (st[2*id].val | st[2*id + 1].val);
		else st[id].val = (st[2*id].val ^ st[2*id + 1].val);
	}	
}

int main()
{
	int n, m;
	cin >> n >> m;
	int N = 1 << n;
	build(1, N, 1);
	for(int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		update(i, a);
	}
	for(int i = 0; i < m; i++)
	{
		int p, b;
		cin >> p >> b;
		update(p, b);
		cout << st[1].val << endl;
	}
}