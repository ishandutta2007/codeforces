#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1000 + 11;
const int MOD = 1e9 + 7;

char a[N][N];
int dp1[N][N],dp2[N][N],num[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    int t=n+m-1;
    vector<pair<int,int> > vv1,vv2;
    if (a[1][1]!=a[n][m]) {cout<<0<<endl; return 0;}
    vv1.pb(mp(1,1));
    vv2.pb(mp(n,m));
    dp1[0][0]=1;
    for (int d=2; d<=(t+1)/2; d++)
    {
        vector<pair<int,int> > v1,v2;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (i+j-1==d) {num[i][j]=v1.size(); v1.pb(mp(i,j));}
            if (n-i+m-j+1==d) {num[i][j]=v2.size(); v2.pb(mp(i,j));}
        }
        /**
        for (int i=0; i<v1.size(); i++)
            cout<<v1[i].ff<<" "<<v1[i].ss<<" : ";
        cout<<endl;
        for (int i=0; i<v2.size(); i++)
            cout<<v2[i].ff<<" "<<v2[i].ss<<" : ";
        cout<<endl;
        cout<<endl;
        **/
        for (int i=0; i<v1.size(); i++)
        for (int j=0; j<v2.size(); j++)
        {
            int l1=v1[i].ff,r1=v1[i].ss,l2=v2[j].ff,r2=v2[j].ss;
            //cout<<a[l1][r1]<<" "<<a[l2][r2]<<endl;
            if (a[l1][r1]!=a[l2][r2]) continue;
            if (l1>1&&l2<n)
                dp2[i][j]=(dp2[i][j]+dp1[num[l1-1][r1]][num[l2+1][r2]])%MOD;
            if (l1>1&&r2<m)
                dp2[i][j]=(dp2[i][j]+dp1[num[l1-1][r1]][num[l2][r2+1]])%MOD;
            if (r1>1&&l2<n)
                dp2[i][j]=(dp2[i][j]+dp1[num[l1][r1-1]][num[l2+1][r2]])%MOD;
            if (r1>1&&r2<m)
                dp2[i][j]=(dp2[i][j]+dp1[num[l1][r1-1]][num[l2][r2+1]])%MOD;
            ///cout<<i<<" "<<j<<" - "<<dp2[i][j]<<endl;
        }
        vv1=v1;
        vv2=v2;
        for (int i=0; i<n+m; i++)
        for (int j=0; j<n+m; j++)
        {
            dp1[i][j]=dp2[i][j];
            dp2[i][j]=0;
        }
    }
    int ans=0;
    if ((n+m-1)%2==1)
    {
        for (int i=0; i<vv1.size(); i++)
            ans=(ans+dp1[i][i])%MOD;
    } else
    {
        for (int i=0; i<vv1.size(); i++)
        {
            int l1=vv1[i].ff,r1=vv1[i].ss;
            if (l1<n) ans=(ans+dp1[i][num[l1+1][r1]])%MOD;
            if (r1<m) ans=(ans+dp1[i][num[l1][r1+1]])%MOD;
        }
    }
    cout<<ans<<"\n";
}