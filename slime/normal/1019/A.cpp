#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 3005
using namespace std;
int cnt[maxn];
vector<int> c[maxn]; 
int pl[maxn];
ll ans = 0;
int r[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int p, cs;
		scanf("%d%d", &p, &cs);
		c[p].push_back(cs);
	}
	for(int i = 1; i <= m; i++)
		if(c[i].size())
			sort(c[i].begin(), c[i].end());
	int ns = 0;
	ll ans = 1000000000;
	ans *= ans;
	for(int j = 1; j <= n; j++)
	{
		ll nans = 0;
		int tot = c[1].size();
		for(int k = 2; k <= m; k++)
		{
			pl[k] = 0;
			while(c[k].size() - pl[k] >= j)
				tot++, nans += c[k][pl[k]], pl[k]++;
		}
		int ncnt = 0;
		for(int k = 2; k <= m; k++)
			for(int j = pl[k]; j < c[k].size(); j++)
				r[ncnt++] = c[k][j];
		sort(r, r + ncnt);
		for(int l = 0; l < ncnt && tot < j; l++)
			tot++, nans += r[l];
		if(tot < j) continue;
		ans = min(ans, nans);
	}
	printf("%lld\n", ans);
	return 0;
}