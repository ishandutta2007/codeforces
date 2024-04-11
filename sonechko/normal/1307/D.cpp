#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int d[N];
int dist[2][N];
int n;
vector<int> v[N];
bool use[N];

void up(int x, int c)
{
    vector<int> vv;
    for (int j=1; j<=n; j++)
        dist[c][j]=2e9;
    dist[c][x]=0;
    vv.pb(x);
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j];
        for (int i=0; i<v[l].size(); i++)
            if (dist[c][v[l][i]]==2e9)
        {
            dist[c][v[l][i]]=dist[c][l]+1;
            vv.pb(v[l][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        cin>>d[i];
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    up(1,0);
    up(n,1);
    vector<pair<int,pair<int, int> > > vv;
    for (int i=1; i<=k; i++)
        vv.pb(mp(dist[0][d[i]],mp(-dist[1][d[i]],d[i])));
    sort(vv.begin(),vv.end());
    int x=0,ans=0;
    for (int i=vv.size()-1; i>=0; i--)
    {
        int l=vv[i].ss.ss;
        if (x!=0) ans=max(ans,dist[0][l]+1+dist[1][x]);
        if (x==0||dist[1][l]>dist[1][x]) x=l;
    }
    ans=min(ans,dist[0][n]);
    cout<<ans;

}