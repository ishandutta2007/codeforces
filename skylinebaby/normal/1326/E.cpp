#include<bits/stdc++.h>
using namespace std;
struct P{
	int mnw;
	int mn;
	int tg;
};
P st[1234567];
int p[323456];
int q[323456];
int rep[323456];
void update(int k)
{
	pair<int, int> a = make_pair(st[k<<1].mn, st[k<<1].mnw);
	pair<int, int> b = make_pair(st[k<<1|1].mn, st[k<<1|1].mnw);
	if(a < b) 
	{
		st[k].mn = st[k<<1].mn;
		st[k].mnw = st[k<<1].mnw;
	}
	else 
	{
		st[k].mn = st[k<<1|1].mn;
		st[k].mnw = st[k<<1|1].mnw;		
	}
}
void build(int L, int R, int k)
{
	if(L == R)
	{
		st[k].mn = 0;
		st[k].mnw = L;
		return;
	}
	int mid = L + R >> 1;
	build(mid + 1, R, k<<1|1);
	build(L, mid, k<<1);
	update(k);
}
void push(int L, int R, int k)
{
	if(st[k].tg == 0) return;
	st[k<<1].tg += st[k].tg;
	st[k<<1|1].tg += st[k].tg;
	st[k<<1].mn += st[k].tg;
	st[k<<1|1].mn += st[k].tg;
	st[k].tg = 0;	
}
void modify(int k, int L, int R,int x, int y, int z)
{
	if(x <= L && y >= R)
	{
		st[k].mn += z;
		st[k].tg += z;
		return;
	}
	push(L, R, k);
	int mid = L + R >> 1;
	if(x <= mid) modify(k<<1, L, mid, x, y, z);
	if(y >  mid) modify(k<<1|1, mid + 1, R, x, y, z);
	update(k);
}
pair<int, int> query(int k, int L, int R, int x, int y)
{
	if(x <= L && y >= R)
	{
		return make_pair(st[k].mn, st[k].mnw);
	}
	push(L, R, k);
	pair<int, int> ans = make_pair(312345, 100);
	int mid = L + R >> 1;
	if(x <= mid) ans = min(ans, query(k<<1, L, mid, x, y));
	if(y >  mid) ans = min(ans, query(k<<1|1, mid + 1, R, x, y));
	return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		rep[p[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &q[i]);
		
	}
	build(1, n, 1);
	int nw = n;
	printf("%d ", nw);
	for(int i = 1; i < n; i++)
	{
		modify(1, 1, n, q[i], n, -1);
		/*for(int j = 1; j <= n; j++)
		{
			printf("%d ", query(1, 1, n, j, j).first);
			
		}*/
		printf("\n");
		while(true)
		{
			pair<int, int> ans = query(1, 1, n, 1, n);
			if(ans.first < 0 && ans.second >= rep[nw]) 
			{
				//printf("nw = %d\n", nw);
				modify(1, 1, n, rep[nw], n, 1);
				nw--;
			}
			else break;
		}
		printf("%d ", nw);
	}
	printf("\n");
	return 0;
}