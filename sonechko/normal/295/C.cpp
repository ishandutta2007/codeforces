#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define int long long
#define mod %MOD

const int N = 50 + 11;
const int MOD = 1e9 + 7;

ll dp[N][N][2],dist[N][N][2];
bool use[N][N][2];
vector<int> v1,v2,v3;
ll cc[N*2][N*2];

inline ll c(int n, int k)
{
    return cc[n][k];
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    cc[0][0]=1;
    for (int i=1; i<=n*2; i++)
    for (int j=0; j<=n*2; j++)
    if (j==0) cc[i][j]=cc[i-1][j]; else
        cc[i][j]=(cc[i-1][j]+cc[i-1][j-1])mod;

    int kol1=0,kol2=0;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if (t==50) kol1++; else kol2++;
    }
    dp[kol1][kol2][0]=1;
    v1.pb(kol1);
    v2.pb(kol2);
    v3.pb(0);
    use[kol1][kol2][0]=1;
    for (int jj=0; jj<v1.size(); jj++)
    {
        int k1=v1[jj],k2=v2[jj],p=v3[jj];
        if (p==0)
        {
            for (int i1=0; i1<=k1; i1++)
            for (int i2=0; i2<=k2; i2++)
                if (i1+i2>0&&i1*50+i2*100<=k)
            {
                ll p=(c(k1,i1)*c(k2,i2))mod;
                if (use[k1-i1][k2-i2][1]==0)
                {
                    use[k1-i1][k2-i2][1]=1;
                    dp[k1-i1][k2-i2][1]=(dp[k1][k2][0]*1ll*p)mod;
                    dist[k1-i1][k2-i2][1]=dist[k1][k2][0]+1;
                    v1.pb(k1-i1);
                    v2.pb(k2-i2);
                    v3.pb(1);
                } else
                if (dist[k1-i1][k2-i2][1]==dist[k1][k2][0]+1)
                    dp[k1-i1][k2-i2][1]=(dp[k1-i1][k2-i2][1]+dp[k1][k2][0]*1ll*p)mod;
            }
        } else
        {
            for (int i1=0; i1<=(kol1-k1); i1++)
            for (int i2=0; i2<=(kol2-k2); i2++)
                if (i1+i2>0&&i1*50+i2*100<=k)
            {
                ll p=(c(kol1-k1,i1)*c(kol2-k2,i2))mod;
                if (use[k1+i1][k2+i2][0]==0)
                {
                    use[k1+i1][k2+i2][0]=1;
                    dp[k1+i1][k2+i2][0]=(dp[k1][k2][1]*1ll*p)mod;
                    dist[k1+i1][k2+i2][0]=dist[k1][k2][1]+1;
                    v1.pb(k1+i1);
                    v2.pb(k2+i2);
                    v3.pb(0);
                } else
                if (dist[k1+i1][k2+i2][0]==dist[k1][k2][1]+1)
                    dp[k1+i1][k2+i2][0]=(dp[k1+i1][k2+i2][0]+dp[k1][k2][1]*1ll*p)mod;
            }
        }
    }
    if (use[0][0][1]==0) cout<<-1<<endl; else
        cout<<dist[0][0][1]<<endl;
    cout<<dp[0][0][1]<<endl;
}
/**
49 290
100 100 100 100 100 100 100 100 50 100 50 100 100 100 50 50 100 50 50 100 100 100 100 100 100 50 100 100 50 100 50 50 100 100 100 50 50 50 50 50 100 100 100 50 100 50 100 50 50

**/