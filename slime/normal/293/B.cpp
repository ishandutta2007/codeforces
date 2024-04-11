#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 11
#define ll long long
using namespace std;
int mp[maxn][maxn];
int n, m, k;
int npl[maxn];
ll ans;
bool fl[maxn];
int jc[maxn];
bool fls[maxn][maxn][maxn];
void dfs(int a, int b, int tt)
{
	if(b == m + 1)
	{
		dfs(a + 1, 1, tt);
		return;
	}
	if(a == n + 1)
	{
		ans += jc[tt];
//		cout<<"PLS"<<tt<<endl;
		return;
	}
	int ns[maxn];
	for(int i = 1; i <= k; i++)
		ns[i] = npl[i];
	int nf = 0;
	for(int t = 1; t <= k; t++)
	{
		if(mp[a][b] && mp[a][b] != t) continue;
		if(fl[t] && fls[t][a][b]) 
		{
		//	cout<<"CON"<<t<<" "<<a<<" "<<b<<" "<<endl;
		//	while(1);
			continue;
		}
		if(ns[t] <= b) continue;
		int nt = tt;
		if(ns[t] == m + 1 && !fl[t])
		{
			if(nf) continue;
			else nf = 1, nt++;
		}
		for(int i = 1; i <= k; i++)
			npl[i] = ns[i];
		npl[t] = b;
		dfs(a, b + 1, nt);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);	
	if(n + m - 1 > k)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &mp[i][j]), fl[mp[i][j]] = 1;
			for(int k = 1; k <= n; k++)
				for(int l = 1; l <= m; l++)
				{
					if(k == i && l == j) continue;
					if((k - i) * (l - j) >= 0) fls[mp[i][j]][k][l] = 1;
				}
		}

	int cnt = 0;
	for(int i = 1; i <= k; i++)
		if(!fl[i]) cnt++;
	for(int i = 1; i <= k; i++)
		npl[i] = m + 1;
	jc[0] = 1;
	for(int i = 1; i <= cnt; i++)
		jc[i] = jc[i - 1] * (cnt - i + 1);
//	cout<<jc[k]<<endl;
	dfs(1, 1, 0);
	ans %= 1000000007;
	printf("%d\n", ans);
	return 0;
}