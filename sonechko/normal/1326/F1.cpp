#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 20000 + 11;

bool a[15][15];
ll dp[130][16400][15];
int ks[16400];
ll ans[16400];
ll res[130][130];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;


    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        char c;
        cin>>c;
        if (c=='1') a[i][j]=1; else a[i][j]=0;
    }
    int kol=n/2;
    for (int i=1; i<=n; i++)
        dp[0][(1<<(i-1))][i]=1;
    int r=0;
    for (int mask1=0; mask1<(1<<n); mask1++)
    {
        ks[mask1]=0;
        for (int i=1; i<=n; i++)
            if (mask1&(1<<(i-1))) ks[mask1]++;
    }
    for (int mask1=0; mask1<(1<<kol); mask1++)
    for (int mask2=0; mask2<(1<<n); mask2++)
        if ((mask1&(1<<(kol-1)))==0)
    {
        for (int p=1; p<=n; p++)
        if (dp[mask1][mask2][p]>0)
    {
        ///cout<<mask1<<" "<<mask2<<" "<<p<<": "<<dp[mask1][mask2][p]<<endl;
        for (int t=1; t<=n; t++)
            if ((mask2&(1<<(t-1)))==0)
        {
            int c=a[p][t];
            int mask11=mask1*2+c;
            int mask22=(mask2|(1<<(t-1)));
            dp[mask11][mask22][t]+=dp[mask1][mask2][p];
        }
    }
    }

    kol=n-1;
    int t1=kol/2;
    int t2=kol-t1;

    for (int msk1=0; msk1<(1<<n); msk1++)
        if (ks[msk1]==t1+1)
    {
        int msk2_=(1<<n)-1-msk1;
        for (int p=1; p<=n; p++)
            if (msk1&(1<<(p-1)))
        {
            int msk2=(msk2_|(1<<(p-1)));
            for (int mask1=0; mask1<(1<<t1); mask1++)
            for (int mask2=0; mask2<(1<<t2); mask2++)
            {
                ll kol=dp[mask1][msk1][p];
                kol*=dp[mask2][msk2][p];
                res[mask1][mask2]+=kol;
            }
        }
    }
    for (int mask1=0; mask1<(1<<t1); mask1++)
    for (int mask2=0; mask2<(1<<t2); mask2++)
    {
        ll p=0;
        ll k=0;
        for (int j=t1-1; j>=0; j--)
        {
            if (mask1&(1<<j)) p+=(1<<k);
            k++;
        }
        for (int j=0; j<=t2-1; j++)
        {
            if (mask2&(1<<j)) p+=(1<<k);
            k++;
        }
        ans[p]=res[mask1][mask2];
    }
    for (int i=0; i<(1<<(n-1)); i++)
        cout<<ans[i]<<" ";

}
/**

**/