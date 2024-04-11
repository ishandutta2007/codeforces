#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,l;
LL s;
vector<int> g[MAXN];
int w[MAXN];
int p;
LL sum[MAXN];
int mx[MAXN];
int dp[MAXN];
int cnt=0;
void dfs(int pos,int d)
{
	dp[pos]=d+1;
	sum[d]=sum[d-1]+w[pos];
	mx[pos]=lower_bound(sum,sum+1+d,sum[d]-s)-sum+1;
	if (mx[pos]<=d-l)
		mx[pos]=d-l+1;
	//WRT(pos);
	//WRT(mx[pos]); 
	for (auto p:g[pos])
	{
		dfs(p,d+1);
		dp[pos]=min(dp[pos],dp[p]);
	}
	if (dp[pos]==d+1)
	{
		cnt++;
		dp[pos]=mx[pos];
	}
}

int main()
{
	cin>>n>>l>>s;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		if (w[i]>s)
		{
			cout<<-1;
			return 0;
		}
	}
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		g[p].push_back(i);
	}
	dfs(1,1);
	cout<<cnt;
	return ~~(0^_^0);
}