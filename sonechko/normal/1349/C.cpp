#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define tm tmm

const int N = 1000 + 11;

char a[N][N];
bool c[N][N];
int tm[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,ks;
    cin>>n>>m>>ks;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int kol=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        if (a[i][j]==a[i-1][j]||a[i][j]==a[i+1][j]||a[i][j]==a[i][j-1]||
            a[i][j]==a[i][j+1]) c[i][j]=1;
        kol+=c[i][j];
    }
    if (kol==0)
    {
        for (int j=1; j<=ks; j++)
        {
            int l,r;
            ll p;
            cin>>l>>r>>p;
            cout<<a[l][r]<<"\n";
        }
        return 0;
    }
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if (c[i][j]==1) {vv.pb(mp(i,j)); tm[i][j]=1;}
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j].ff;
        int r=vv[j].ss;
        if (l>1&&tm[l-1][r]==0)
        {
            tm[l-1][r]=tm[l][r]+1;
            vv.pb(mp(l-1,r));
        }
        if (l<n&&tm[l+1][r]==0)
        {
            tm[l+1][r]=tm[l][r]+1;
            vv.pb(mp(l+1,r));
        }
        if (r>1&&tm[l][r-1]==0)
        {
            tm[l][r-1]=tm[l][r]+1;
            vv.pb(mp(l,r-1));
        }
        if (r<m&&tm[l][r+1]==0)
        {
            tm[l][r+1]=tm[l][r]+1;
            vv.pb(mp(l,r+1));
        }
    }
    for (int j=1; j<=ks; j++)
    {
        int l,r;
        ll p;
        cin>>l>>r>>p;
        int c=0;
        if (p>=tm[l][r]&&(p-tm[l][r])%2==0) c=1;
        if (c==0) cout<<a[l][r]<<"\n"; else
        {
            if (a[l][r]=='1') cout<<"0\n"; else cout<<"1\n";
        }
    }

}