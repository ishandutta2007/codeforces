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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<double, double> pp;
const int maxn = 1e5 + 5;
const double eps = 1e-10;
typedef struct Node
{
	double v;
	int t, h;
	Node *lch, *rch;
	Node() : v(0), t(1), h(rand()), lch(0), rch(0) {};
}*pnode;
Node node[maxn];
int cnt = 0;
pnode nNode(const double &v)
{
	cnt ++;
	node[cnt].v = v;
	return &node[cnt];
}
pnode root = 0;
int gett(const pnode &r)
{
	return r ? r->t : 0;
}
void update(const pnode &r)
{
	r->t = gett(r->lch) + 1 + gett(r->rch);
}
void insert(pnode &r, const double &v)
{
	if(!r)
	{
		r = nNode(v);
		return;
	}
	if(v < r->v)
	{
		insert(r->lch, v);
		if(r->lch->h < r->h)
		{
			pnode tmp = r->lch;
			r->lch = tmp->rch;
			tmp->rch = r;
			update(r);
			r = tmp;
		}
	}
	else
	{
		insert(r->rch, v);
		if(r->rch->h < r->h)
		{
			pnode tmp = r->rch;
			r->rch = tmp->lch;
			tmp->lch = r;
			update(r);
			r = tmp;
		}
	}
	update(r);
}
int findpos(const pnode &r, const double &v)
{
	if(!r)
		return 0;
	if(v < r->v - eps)
		return findpos(r->lch, v);
	else
		return gett(r->lch) + 1 + findpos(r->rch, v);
}
pp s[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	srand(time(0));
	int n, w;
	cin >> n >> w;
	for(int i = 1; i <= n; i ++)
	{
		int x, v;
		cin >> x >> v;
		s[i] = mp((double)(v - w) / x, (double)(v + w) / x);
	}
	sort(s + 1, s + n + 1);
	long long now = 0, ans = 0;
	for(int i = n; i >= 1; i --)
	{
		if(s[i].first < s[i + 1].first - eps)
		{
			ans += now * (now - 1) / 2;
			for(int j = i + now; j > i; j --)
				insert(root, s[j].second);
			now = 0;
		}
		ans += findpos(root, s[i].second);
		now ++;
	}
	ans += now * (now - 1) / 2;
	cout << ans << endl;
	
	return 0;
}