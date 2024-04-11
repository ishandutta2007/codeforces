#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=5005;
const int mod=998244353;
const int inf=1e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
 
int n[5],m[5];
int a[5][N];
struct DP{int id,x;};
bool cmp(DP x,DP y){return x.x<y.x;}
DP dp[5][N];
map< pair<int,int> ,bool > Map;
signed main()
{
	for (int i=1;i<=4;i++) rd(n[i]);
	for (int k=1;k<=4;k++)
	{
		for (int i=1;i<=n[k];i++) rd(a[k][i]);
	}
	for (int k=1;k<=4;k++) for (int i=1;i<=n[k];i++) dp[k][i].x=a[k][i],dp[k][i].id=i;
	for (int k=1;k<=4;k++) sort(dp[k]+1,dp[k]+n[k]+1,cmp);
	for (int k=2;k<=4;k++)
	{
		rd(m[k]);Map.clear();
		for (int i=1;i<=m[k];i++)
		{
			int x,y;rd(x);rd(y);
			Map[make_pair(x,y)]=1;
		}
		for (int i=1;i<=n[k];i++)
		{
			int minn=inf;
			for (int j=1;j<=n[k-1];j++)
				if (Map.find(make_pair(dp[k-1][j].id,dp[k][i].id))==Map.end())
				{
					minn=dp[k-1][j].x;
					break;
				}
			//cout<<"k="<<k<<" i="<<i<<",minn="<<minn<<endl;
			dp[k][i].x+=minn;
		}
			
		sort(dp[k]+1,dp[k]+n[k]+1,cmp);
	}
	if (dp[4][1].x>=inf) cout<<"-1"<<endl;else
	cout<<dp[4][1].x<<endl;
}