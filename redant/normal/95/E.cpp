#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define SI ({int x;scanf("%d",&x);x;})
#define REP(i,n) for(int i=1;i<=n;i++)
#define FORE(i,v) for(__typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)
#define PB(x) push_back(x)
#define MX 100005

int N, M;
bool lucky[MX], vis[MX];
int dp[MX], cnt[MX];
vector<int> g[MX];

int dfs(int u)
{
	vis[u]=true;
	int r = 0;
	FORE(i,g[u]) if(!vis[*i]) r+=dfs(*i);
	return 1+r;
}

void solve()
{
	REP(i,N) dp[i] = MX;
	REP(i,N) for(int j=1,s=0;j<=cnt[i];s+=j,j<<=1) 
		{
			int k = j;
			if(s+j>cnt[i]) k = cnt[i] - (j-1);
			int w = i*k, c = k;
			for(int i=N;i>=w;i--) dp[i] = min(dp[i],dp[i-w]+c);
		}
}

int main()
{
	N = SI; M = SI;
	while(M--){ int a = SI, b = SI; g[a].PB(b); g[b].PB(a); }	
	REP(i,N) if(!vis[i]){ int s = dfs(i); cnt[s]++; }
	lucky[0]=true;
	REP(i,N) if(i%10==4 || i%10==7) lucky[i] = lucky[i/10];
	solve();
	int r = MX;
	REP(i,N) if(lucky[i]) r = min(r,dp[i]);
	printf("%d\n",r==MX?-1:r-1);
	return 0;
}