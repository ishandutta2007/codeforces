#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int gl[N];
vector<int> v[N];
int use[2][N];
int k[2];
vector<int> vs;
int sz[N];


int gll(int x)
{
    if (x==gl[x]) return x;
    return gl[x]=gll(gl[x]);
}


bool dfss(int l, int xx, int pr)
{
    sz[l]=1;
    int gg=0;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        int to=v[l][j];
        int g=dfss(to,xx,l);
        if (g==0) sz[l]+=sz[to]; else gg=1;
    }
    if (l==xx) gg=1;
    if (gg==1) vs.pb(l);
    return gg;
}

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        gl[i]=i;
        v[i].clear();
        use[0][i]=0;
        use[1][i]=0;
        sz[i]=0;
    }
    vs.clear();
    int aa,bb;
    for (int i=1; i<=n; i++)
    {
        int x,y;
        cin>>x>>y;
        int xx=gll(x);
        int yy=gll(y);
        if (xx!=yy)
        {
            v[x].pb(y);
            v[y].pb(x);
            gl[xx]=yy;
        } else
        {
            aa=x;
            bb=y;
        }
    }
    ll ans=n*1ll*(n-1);
    int g=dfss(aa,bb,0);
    ans+=n*1ll*(n-1);
    for (int i=0; i<vs.size(); i++)
        ans-=sz[vs[i]]*1ll*(sz[vs[i]]-1);
    cout<<ans/2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}