#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long int int64;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif



const int maxn = (int) 2e5 + 100;

int e[maxn][2];
double ed[maxn];
bool restr[maxn];

vector <int> g[maxn];
double w[maxn];

int getOth(int id, int v)
{
	return e[id][0] + e[id][1] - v;
}

double getDer(int v, double len = 0., int par = -1)
{
	double ans = pow(len, 0.5) * w[v];
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int eid = g[v][i];
		int nv = getOth(eid, v);
		if (nv == par)
			continue;
		ans += getDer(nv, len + ed[eid], v);
	}
	return ans;
}

double getSum(int v, double len = 0., int par = -1)
{
	double ans =len * sqrt(len) * w[v];
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int eid = g[v][i];
		int nv = getOth(eid, v);
		if (nv == par)
			continue;
		ans += getSum(nv, len + ed[eid], v);
	}
	return ans;
}

int cnt[maxn];

int getSize(int v, int par = -1)
{
	cnt[v] = 1;

	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int eid = g[v][i];
		int nv = getOth(eid, v);
		if (nv == par)
			continue;
		if (restr[eid] )
			continue;
		cnt[v] += getSize(nv, v);
	}

	return cnt[v];
}

int getCentr(int v, int gcnt, int par = -1)
{
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int eid = g[v][i];
		int nv = getOth(eid, v);
		if (nv == par)
			continue;
		if (restr[eid] )
			continue;
		if (cnt[nv] * 2 > gcnt)
			return getCentr(nv, gcnt, v);
	}
	return v;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &w[i] );
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		double l;
		scanf("%d%d%lf", &a, &b, &l);
		a--;
		b--;
		e[i][0] = a;
		e[i][1] = b;
		ed[i] = l;
		g[a].push_back(i);
		g[b].push_back(i);
	}

	int root = 0;

	while (true)
	{
		int gcnt = getSize(root);
		if (gcnt == 1)
			break;
		root = getCentr(root, gcnt);
		double mx = 0;
		int mxid = -1;
		for (int i = 0; i < (int) g[root].size(); i++)
		{
			int eid = g[root][i];
			int nv = getOth(eid, root);
			if (restr[eid] )
				continue;
			double cur = getDer(nv, ed[eid], root);
			if (cur > mx)
			{
				mx = cur;
				mxid = eid;
			}
		}

		if (mxid == -1)
			break;
		
		eprintf("mxid = %d\n", mxid);
		
		int new_root = getOth(mxid, root);
		
		if (getSum(root) <= getSum(new_root))
			break;

		root = new_root;
		restr[mxid] = true;
	}

	printf("%d %.10lf\n", root + 1, getSum(root) );
	//printf("%.10lf %d\n", getSum(root) , root + 1);

	return 0;
}