#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=1e5+5;
const int inf=0x3f3f3f3f3f3f3f3f;
int dp[N];
int last[N];
int diff[N];
int vis[N];
int n,q,a,b;
int v[N],col[N];
signed main()
{
    rd(n);rd(q);
    for (int i=1;i<=n;i++) rd(v[i]);
    for (int i=1;i<=n;i++) rd(col[i]);
    while (q--)
    {
        rd(a);rd(b);
        for (int i=1;i<=n;i++) dp[i]=-inf;
        for (int i=1;i<=n;i++) vis[i]=0;
        int MAX=0,SEC=0,ans=0;
        for (int i=1;i<=n;i++)
        {
            int tmp=max(b*v[i],dp[col[i]]+a*v[i]);
            if(col[i]!=MAX) tmp=max(tmp,dp[MAX]+b*v[i]);
			else tmp=max(tmp,dp[SEC]+b*v[i]);
            if(tmp>dp[MAX])
			{
				if(col[i]!=MAX) SEC=MAX,MAX=col[i];
				else MAX=col[i];
			}
			else if(tmp>dp[SEC] && col[i]!=MAX) SEC=col[i];
			dp[col[i]]=max(dp[col[i]],tmp);
            ans=max(ans,dp[col[i]]);
        }
        cout<<ans<<endl;
    }
}