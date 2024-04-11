#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <iomanip>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 2e5 + 5;
typedef struct Node
{
	int st, ed;
	double s, add, mul;
	Node *lch, *rch;
	Node() : st(0), ed(0), s(0), add(0), mul(1), lch(0), rch(0) {}
}*pnode;
Node node[maxn << 1];
int cnt = 0;
pnode nNode(const int &stt, const int &edd, const double &vv, const pnode &lchh, const pnode &rchh)
{
	cnt ++;
	node[cnt].st = stt;
	node[cnt].ed = edd;
	node[cnt].s = vv;
	node[cnt].lch = lchh;
	node[cnt].rch = rchh;
	return &node[cnt];
}
pnode root = 0;
double a[maxn];
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
void add(const pnode &r, const double &add)
{
	r->s += (r->ed - r->st + 1) * add;
	r->add += add;
}
void mul(const pnode &r, const double &mul)
{
	r->s *= mul;
	r->add *= mul;
	r->mul *= mul;
}
void down(const pnode &r)
{
	if(r->mul != 1)
	{
		mul(r->lch, r->mul);
		mul(r->rch, r->mul);
		r->mul = 1;
	}
	if(r->add != 0)
	{
		add(r->lch, r->add);
		add(r->rch, r->add);
		r->add = 0;
	}
}
void add(const pnode &r, const int &x, const int &y, const double &v)
{
	if(x <= r->st && y >= r->ed)
	{
		add(r, v);
		return;
	}
	down(r);
	if(x <= r->lch->ed)
		add(r->lch, x, y, v);
	if(y >= r->rch->st)
		add(r->rch, x, y, v);
	update(r);
}
void mul(const pnode &r, const int &x, const int &y, const double &v)
{
	if(x <= r->st && y >= r->ed)
	{
		mul(r, v);
		return;
	}
	down(r);
	if(x <= r->lch->ed)
		mul(r->lch, x, y, v);
	if(y >= r->rch->st)
		mul(r->rch, x, y, v);
	update(r);
}
double query(const pnode &r, const int &x, const int &y)
{
	if(x <= r->st && y >= r->ed)
		return r->s;
	down(r);
	double ans = 0;
	if(x <= r->lch->ed)
		ans += query(r->lch, x, y);
	if(y >= r->rch->st)
		ans += query(r->rch, x, y);
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	root = set_tree(1, n);
	for(int i = 1; i <= q; i ++)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
			double now1 = query(root, l1, r1) / len1, now2 = query(root, l2, r2) / len2;
			mul(root, l1, r1, (double)(len1 - 1) / len1);
			mul(root, l2, r2, (double)(len2 - 1) / len2);
			add(root, l1, r1, now2 / len1);
			add(root, l2, r2, now1 / len2);
		}
		else if(op == 2)
		{
			int l, r;
			cin >> l >> r;
			cout << fixed << setprecision(7) << query(root, l, r) << endl;
		}
	}
	
	return 0;
}