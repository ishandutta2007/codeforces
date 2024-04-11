#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int T,n,m;
int a[105][2005],b[105][105];
int dp[13][13][13][(1<<12)];
int save[(1<<12)];
void upd(int &a,int b) {a=max(a,b);}
vector<P> v;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<m;i++)
        {
            int maxi=0;
            for(int j=0;j<n;j++) maxi=max(maxi,a[j][i]);
            v.push_back(P(maxi,i));
        }
        sort(v.begin(),v.end(),greater<P>());
        for(int i=0;i<min(n,m);i++)
        {
            int pos=v[i].S;
            for(int j=0;j<n;j++) b[j][i]=a[j][pos];
        }
        for(int i=0;i<min(n,m);i++)
        {
            int pos=v[i].S;
            for(int j=0;j<n;j++) a[j][i]=b[j][i];
        }
        m=min(n,m);
        memset(dp,-1,sizeof(dp));
        for(int shift=0;shift<n;shift++) dp[0][0][shift][0]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int shift=0;shift<n;shift++)
                {
                    for(int mask=0;mask<(1<<n);mask++)
                    {
                        if(dp[i][j][shift][mask]==-1) continue;
                        int pos=(j+shift)%n;
                        if(!(mask&(1<<j))) upd(dp[i][j+1][shift][mask^(1<<j)],dp[i][j][shift][mask]+a[pos][i]);
                        upd(dp[i][j+1][shift][mask],dp[i][j][shift][mask]);
                    }
                }
            }
            memset(save,-1,sizeof(save));
            for(int shift=0;shift<n;shift++)
                for(int mask=0;mask<(1<<n);mask++)
                    upd(save[mask],dp[i][n][shift][mask]);
            for(int shift=0;shift<n;shift++)
                for(int mask=0;mask<(1<<n);mask++)
                    upd(dp[i+1][0][shift][mask],save[mask]);
        }
        printf("%d\n",save[(1<<n)-1]);
    }
    return 0;
}