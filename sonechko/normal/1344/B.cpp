#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 1000 + 11;
const int MOD = 1e9 + 7;

char a[N][N];
bool use[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int ks1=0,ks2=0;
    for (int i=1; i<=n; i++)
    {
        int p1=0,p2=0,kk=0;
        for (int j=1; j<=m; j++)
        {
            if (a[i][j]=='#'&&p1==0) p1=j;
            if (a[i][j]=='#') {p2=j; kk++;}
        }
        if (p1==0) ks1++; else
        if (p2-p1+1!=kk) return cout<<"-1", 0;
    }
    for (int j=1; j<=m; j++)
    {
        int p1=0,p2=0,kk=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i][j]=='#'&&p1==0) p1=i;
            if (a[i][j]=='#') {p2=i; kk++;}
        }
        if (p1==0) ks2++; else
        if (p2-p1+1!=kk) return cout<<"-1", 0;
    }
    if (ks1>0&&ks2==0) return cout<<-1, 0;
    if (ks2>0&&ks1==0) return cout<<-1, 0;
    int ans=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if (a[i][j]=='#'&&use[i][j]==0)
    {
        vector<pair<int,int> > vv;
        vv.pb(mp(i,j));
        use[i][j]=1;
        for (int p=0; p<vv.size(); p++)
        {
            int l=vv[p].ff;
            int r=vv[p].ss;
            if (a[l-1][r]=='#'&&use[l-1][r]==0)
            {
                vv.pb(mp(l-1,r));
                use[l-1][r]=1;
            }
            if (a[l+1][r]=='#'&&use[l+1][r]==0)
            {
                vv.pb(mp(l+1,r));
                use[l+1][r]=1;
            }
            if (a[l][r+1]=='#'&&use[l][r+1]==0)
            {
                vv.pb(mp(l,r+1));
                use[l][r+1]=1;
            }
            if (a[l][r-1]=='#'&&use[l][r-1]==0)
            {
                vv.pb(mp(l,r-1));
                use[l][r-1]=1;
            }
        }
        ans++;
    }
    cout<<ans;
}