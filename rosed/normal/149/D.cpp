#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
#define mid ((l+r)>>1)
#define eps (1e-8)
    const int N=3e5+10,inf=2e9,mod=1e9+7;
    int n,m;
    char s[N];
    vector<int> eg[1010];
    int dp[710][710][3][3];
    bool vis[710][710];
    inline void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        cin>>(s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;++i)
        {
            int sum=0;
            for(int j=i;j>=1;--j)
            {
                if(s[j]==')') ++sum;
                else --sum;
                if(sum<0) break;
                if(!sum) {eg[j].push_back(i);vis[j][i]=1;}
            }
            if(s[i]==')'&&s[i-1]=='(')
            {
                for(int j=1;j<3;++j)
                {
                    dp[i-1][i][0][j]=dp[i-1][i][j][0]=1;
                }
            }
        }
        for(int len=4;len<=n;len+=2)
        {
            for(int l=1,r=l+len-1;r<=n;++l,++r)
            {
                if(!vis[l][r]) continue;
                if(s[l]=='('&&s[r]==')'&&vis[l+1][r-1])
                {
                    for(int j=0;j<3;++j)
                    {
                        for(int k=0;k<3;++k)
                        {
                            if(j>0&&k>0) continue;
                            if(j==0&&k==0) continue;
                            for(int p1=0;p1<3;++p1)
                            {
                                if(j==p1&&j>0) continue;
                                for(int p2=0;p2<3;++p2)
                                {
                                    if(k==p2&&k>0) continue;
                                    dp[l][r][j][k]=(dp[l][r][j][k]+dp[l+1][r-1][p1][p2])%mod;
                                }
                            }
                        }
                    }
                }
                for(int t:eg[l])
                {
                    if(t>=r) break;

                    for(int j=0;j<3;++j)
                    {
                        for(int k=0;k<3;++k)
                        {
                            for(int p1=0;p1<3;++p1)
                            {
                                for(int p2=0;p2<3;++p2)
                                {
                                    if((p1==p2&&p1>0)) continue;
                                    //if(l==1&&r==6) cout<<j<<' '<<p1<<' '<<p2<<' '<<k<<"!!!!"<<endl;
                                    dp[l][r][j][k]=(dp[l][r][j][k]+dp[l][t][j][p1]*dp[t+1][r][p2][k]%mod)%mod;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
        int ans=0;
        for(int j=0;j<3;++j)
            for(int k=0;k<3;++k)
            {
                //cout<<j<<' '<<k<<' '<<dp[1][n][j][k]<<"!!!"<<endl;
                ans=(ans+dp[1][n][j][k])%mod;
            }
                
            cout<<(ans%mod+mod)%mod<<'\n';
    }
}
signed main()
{
    red::main();
    return 0;   
}