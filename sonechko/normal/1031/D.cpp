#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod %MOD

const int MOD = 1e9 + 7;
const int N = 2000 + 11;

char a[N][N];
int kol[N][N];
bool use[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    if (a[1][1]=='a') kol[1][1]=0; else kol[1][1]=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (i==1&&j!=1)
    {
        kol[i][j]=kol[i][j-1];
        if (a[i][j]!='a') kol[i][j]++;
    } else
    if (j==1&&i!=1)
    {
        kol[i][j]=kol[i-1][j];
        if (a[i][j]!='a') kol[i][j]++;
    } else
    if (i>1&&j>1)
    {
        kol[i][j]=min(kol[i-1][j],kol[i][j-1]);
        if (a[i][j]!='a') kol[i][j]++;
    }
    if (kol[n][n]<=k)
    {
        for (int i=1; i<=n*2-1; i++)
            cout<<"a";
        cout<<endl;
        return 0;
    }
    if (kol[n][n]==k+1)
    {
        for (int i=1; i<n*2-1; i++)
            cout<<"a";
        cout<<a[n][n];
        cout<<endl;
        return 0;
    }
    string ans="";
    if (k==0) ans+=a[1][1]; else ans+="a";
    vector<pair<int,int> > c;
    for (int i=2; i<=n; i++)
        c.pb(mp(1,i));
    for (int j=2; j<=n; j++)
        c.pb(mp(j,n));
    use[1][1]=1;
    for (int jj=0; jj<c.size(); jj++)
    {
        int l=c[jj].ff,r=c[jj].ss;
        vector<pair<char,pair<int,int> > > vv;
        int t=0;
        while (l<=n&&r>=1)
        {
            if (kol[l][r]<=k) {t=1; use[l][r]=1;} else
            if (use[l-1][r]||use[l][r-1]) vv.pb(mp(a[l][r],mp(l,r)));
            l++;
            r--;
        }
        sort(vv.begin(),vv.end());
        if (t==1)
        {
            ans+="a";
            for (int j=0; j<vv.size(); j++)
                if (vv[j].ff=='a') use[vv[j].ss.ff][vv[j].ss.ss]=1;
        } else
        {
            ans+=vv[0].ff;
            for (int j=0; j<vv.size(); j++)
                if (vv[j].ff==vv[0].ff) use[vv[j].ss.ff][vv[j].ss.ss]=1;
        }
    }
    cout<<ans<<endl;
}