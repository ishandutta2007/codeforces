#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 100 + 11;
char a[N][N];
string b[N];
int ans,n,m;
string s;
vector<pair<int,int> > v,w;
void add(string t)
{
    w.clear();
    for (int i=0; i<v.size(); i++)
    {
        int l=v[i].ff;
        int r=v[i].ss;
        for (int j=l+1; j<=r; j++)
        if (t[j]<t[j-1]) {ans++; return;}
        int l1=l;
        for (int j=l+1; j<=r; j++)
        if (t[j]!=t[j-1])
        {
            if (j!=l1+1) w.pb(mp(l1,j-1));
            l1=j;
        }
        if (l1!=r) w.pb(mp(l1,r));
    }
    v=w;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
    v.pb(mp(1,n));
    for (int j=1; j<=m; j++)
    {
        string t=".";
        for (int i=1; i<=n; i++)
        {
            string d="";
            d+=a[i][j];
            t+=d;
        }
        t+=".";
        add(t);
    }
    cout<<ans<<endl;
}