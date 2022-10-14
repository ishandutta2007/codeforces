#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 5100
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN],b[MAXN],c[MAXN];
int n,m,k;
int from[MAXN];
int dp[MAXN];
vector<int> to[MAXN];
int d[MAXN];

int main()
{
	int x,y;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		from[i]=i;
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		from[y]=max(from[y],x);
	}
	for (int i=1;i<=n;i++)
		to[from[i]].push_back(i);
	int tmp=k;
	for (int i=1;i<=n;i++)
	{
		if (tmp<a[i])
		{
			cout<<-1;
			return 0;
		}
		tmp+=b[i];
		d[i]=tmp-a[i+1];
	}
	for (int i=n-1;i;i--)
		d[i]=min(d[i+1],d[i]);
	/*
	for (int i=1;i<=n;i++)
	{
		cout<<i<<' '<<d[i]<<"    ";
		for (auto p:to[i])
			cout<<p<<' ';
		cout<<endl;
	}
	*/
	for (int i=1;i<=n;i++)
	{
		for (auto p:to[i])
		{
			for (int j=d[i]-1;j>=0;j--)
				dp[j+1]=max(dp[j+1],dp[j]+c[p]);
		}
	}
	int ans=0;
	for (int i=0;i<=d[n];i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return ~~(0^_^0);
}