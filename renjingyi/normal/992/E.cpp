#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, long long> pp;
const int maxn = 2e5 + 5;
typedef struct Node
{
	int st, ed;
	long long s;
	Node *lch, *rch;
}*pnode;
Node node[maxn << 2];
int cnt = 0;
pnode nNode(const int &st, const int &ed, const long long &s, const pnode &lch, const pnode &rch)
{
	cnt ++;
	node[cnt].st = st;
	node[cnt].ed = ed;
	node[cnt].s = s;
	node[cnt].lch = lch;
	node[cnt].rch = rch;
	return &node[cnt];
}
pnode root = 0;
long long a[maxn];
void update(const pnode &r)
{
	r->s = r->lch->s + r->rch->s;
}
pnode set_tree(const int &st, const int &ed)
{
	if(st == ed)
		return nNode(st, ed, a[st], 0, 0);
	int mid = st + ed >> 1;
	pnode r = nNode(st, ed, 0, set_tree(st, mid), set_tree(mid + 1, ed));
	update(r);
	return r;
}
void change(const pnode &r, const int &x, const long long &v)
{
	if(r->st == r->ed)
	{
		r->s = v;
		return;
	}
	if(x <= r->lch->ed)
		change(r->lch, x, v);
	else
		change(r->rch, x, v);
	update(r);
}
pp query(const pnode &r, const long long &s)
{
	if(r->st == r->ed)
		return mp(r->st, r->s);
	if(s <= r->lch->s)
		return query(r->lch, s);
	else
	{
		pp now = query(r->rch, s - r->lch->s);
		return mp(now.first, now.second + r->lch->s);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	root = set_tree(1, n);
	while(q --)
	{
		int p;
		long long x;
		cin >> p >> x;
		a[p] = x;
		change(root, p, x);
		if(a[1] == 0)
		{
			cout << 1 << '\n';
			continue;
		}
		long long sum = a[1];
		while(1)
		{
			pp next = query(root, sum << 1);
			if(next.second < (sum << 1))
			{
				cout << -1 << '\n';
				break;
			}
			sum = next.second;
			if((a[next.first] << 1) == sum)
			{
				cout << next.first << '\n';
				break;
			}
		}
	}
	
	return 0;
}