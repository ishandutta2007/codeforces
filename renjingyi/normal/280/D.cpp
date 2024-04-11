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
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 1e5 + 5;
typedef struct Node
{
	int st, ed;
	int s, lmx, lmxp, rmx, rmxp, mx, mxl, mxr, lmn, lmnp, rmn, rmnp, mn, mnl, mnr;
	bool rev;
	Node *lch, *rch;
	Node(const int &st = 0, const int &ed = 0, const int &x = 0, const int &v = 0) : st(st), ed(ed), s(v), lmx(v), lmxp(x), rmx(v), rmxp(x), mx(v), mxl(x), mxr(x), lmn(v), lmnp(x), rmn(v), rmnp(x), mn(v), mnl(x), mnr(x), rev(0), lch(0), rch(0) {}
}*pnode;
Node node[maxn << 2], tmp[maxn];
int cnt = 0, tmpcnt = 0;
pnode nNode(const int &x = 0, const int &v = 0, const pnode &l = 0, const pnode &r = 0, const int &st = 0, const int &ed = 0)
{
	cnt ++;
	node[cnt] = Node(st, ed, x, v);
	node[cnt].lch = l;
	node[cnt].rch = r;
	return &node[cnt];
}
pnode gettmp()
{
	tmpcnt ++;
	return &tmp[tmpcnt];
}
pnode root = 0;
void rev(const pnode &r)
{
	if(!r)
		return;
	r->s = -r->s;
	r->lmx = -r->lmx;
	r->rmx = -r->rmx;
	r->mx = -r->mx;
	r->lmn = -r->lmn;
	r->rmn = -r->rmn;
	r->mn = -r->mn;
	swap(r->lmx, r->lmn);
	swap(r->lmxp, r->lmnp);
	swap(r->rmx, r->rmn);
	swap(r->rmxp, r->rmnp);
	swap(r->mx, r->mn);
	swap(r->mxl, r->mnl);
	swap(r->mxr, r->mnr);
	r->rev ^= 1;
}
void down(const pnode &r)
{
	if(!r)
	{
		cout << "boom" << endl;
		return;
	}
	if(r->rev)
	{
		rev(r->lch);
		rev(r->rch);
		r->rev = 0;
	}
}
pnode ret;
void merge(const pnode &l, const pnode &r)
{
	down(l);
	down(r);
	ret->s = l->s + r->s;
	ret->lmx = l->s + r->lmx;
	ret->lmxp = r->lmxp;
	if(l->lmx > ret->lmx)
	{
		ret->lmx = l->lmx;
		ret->lmxp = l->lmxp;
	}
	ret->rmx = r->s + l->rmx;
	ret->rmxp = l->rmxp;
	if(r->rmx > ret->rmx)
	{
		ret->rmx = r->rmx;
		ret->rmxp = r->rmxp;
	}
	ret->mx = l->rmx + r->lmx;
	ret->mxl = l->rmxp;
	ret->mxr = r->lmxp;
	if(l->mx > ret->mx)
	{
		ret->mx = l->mx;
		ret->mxl = l->mxl;
		ret->mxr = l->mxr;
	}
	if(r->mx > ret->mx)
	{
		ret->mx = r->mx;
		ret->mxl = r->mxl;
		ret->mxr = r->mxr;
	}
	ret->lmn = l->s + r->lmn;
	ret->lmnp = r->lmnp;
	if(l->lmn < ret->lmn)
	{
		ret->lmn = l->lmn;
		ret->lmnp = l->lmnp;
	}
	ret->rmn = r->s + l->rmn;
	ret->rmnp = l->rmnp;
	if(r->rmn < ret->rmn)
	{
		ret->rmn = r->rmn;
		ret->rmnp = r->rmnp;
	}
	ret->mn = l->rmn + r->lmn;
	ret->mnl = l->rmnp;
	ret->mnr = r->lmnp;
	if(l->mn < ret->mn)
	{
		ret->mn = l->mn;
		ret->mnl = l->mnl;
		ret->mnr = l->mnr;
	}
	if(r->mn < ret->mn)
	{
		ret->mn = r->mn;
		ret->mnl = r->mnl;
		ret->mnr = r->mnr;
	}
	ret->st = l->st;
	ret->ed = r->ed;
	ret->lch = l;
	ret->rch = r;
}
int a[maxn];
pnode set_tree(const int &st, const int &ed)
{
	if(st == ed)
		return nNode(st, a[st], 0, 0, st, ed);
	int mid = st + ed >> 1;
	pnode r = nNode(0, 0, set_tree(st, mid), set_tree(mid + 1, ed), st, ed);
	merge(r->lch, r->rch);
	*r = *ret;
	return r;
}
pnode work(const pnode &r, const int &x, const int &y)
{
	//cout << "work : " << r->st << " " << r->ed << " " << x << " " << y << endl;
	if(x <= r->st && y >= r->ed)
	{
		pnode ans = gettmp();
		*ans = *r;
		return ans;
	}
	down(r);
	pnode ans = gettmp();
	bool mark = 0;
	if(x <= r->lch->ed)
	{
		ans = work(r->lch, x, y);
		mark = 1;
	}
	if(y >= r->rch->st)
	{
		if(!mark)
			ans = work(r->rch, x, y);
		else
		{
			merge(ans, work(r->rch, x, y));
			ans = gettmp();
			*ans = *ret;
		}
	}
	//cout << "finish : " << ans->st << " " << ans->ed << endl;
	return ans;
}
void change(const pnode &r, const int &x, const int &v)
{
	if(r->st == r->ed)
	{
		*r = Node(r->st, r->ed, x, v);
		return;
	}
	down(r);
	if(x <= r->lch->ed)
		change(r->lch, x, v);
	else
		change(r->rch, x, v);
	merge(r->lch, r->rch);
	*r = *ret;
}
void rev(const pnode &r, const int &x, const int &y)
{
	//cout << "rev : " << r->st << " " << r->ed << " " << x << " " << y << endl;
	if(x <= r->st && y >= r->ed)
	{
		rev(r);
		return;
	}
	down(r);
	if(x <= r->lch->ed)
		rev(r->lch, x, y);
	if(y >= r->rch->st)
		rev(r->rch, x, y);
	merge(r->lch, r->rch);
	*r = *ret;
}
///*
void out(const pnode &r)
{
	cout << "out : " << r->st << " " << r->ed << " " << r->s << " " << r->mx << " " << r->mxl << " " << r->mxr << " " << r->lmx << " " << r->lmxp << " " << r->rmx << " " << r->rmxp << endl;
	//cout << r << " " << r->lch << " " << r->rch << endl;
	if(r->st == r->ed)
		return;
	down(r);
	merge(r->lch, r->rch);
	*r = *ret;
	//int a;
	//cin >> a;
	//cout << "outl" << endl;
	out(r->lch);
	//cout << "outr" << endl;
	out(r->rch);
}
//*/
vector<int> tmpl, tmpr;
int main()
{
	std::ios::sync_with_stdio(false);
	ret = nNode();
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	root = set_tree(1, n);
	//out(root);
	int m;
	cin >> m;
	for(int i = 1; i <= m; i ++)
	{
		int op;
		cin >> op;
		if(op == 0)
		{
			int x, v;
			cin >> x >> v;
			change(root, x, v);
		}
		else if(op == 1)
		{
			int l, r, k;
			cin >> l >> r >> k;
			//cout << "query : " << l << " " << r << " " << k << endl;
			tmpcnt = 0;
			pnode now = work(root, l, r);
			//out(now);
			//cout << "--------------------" << endl;
			int ans = 0;
			//cout << "here1" << endl;
			tmpl.clear();
			tmpr.clear();
			for(int j = 1; j <= k; j ++)
			{
				//cout << "aaa : " << j << endl;
				if(now->mx <= 0)
					break;
				ans += now->mx;
				int ll = now->mxl, rr = now->mxr;
				//cout << "now : " << j << " " << ll << " " << rr << " " << now->mx << endl;
				rev(now, ll, rr);
				tmpl.push_back(ll);
				tmpr.push_back(rr);
				//cout << "-------------------------------------" << endl;
				//out(now);
				//cout << "-------------------------------------" << endl;
			}
			cout << ans << endl;
			for(int i = 0; i < tmpl.size(); i ++)
				rev(now, tmpl[i], tmpr[i]);
			for(int i = tmpcnt; i >= 1; i --)
				down(&tmp[i]);
		}
	}
	
	return 0;
}