#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

int gl[N],sz[N];

int glava(int l)
{
    if (gl[l]==0) return l;
    return gl[l]=glava(gl[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int l;
        cin>>l;
        sz[l]=1;
    }
    for (int i=1; i<=n; i++)
        gl[i]=0;
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        vv.pb(mp(k,mp(l,r)));
    }
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    {
        int xx=vv[j].ff,l=vv[j].ss.ff,r=vv[j].ss.ss;
        int x=glava(l);
        int y=glava(r);
        if (x==y) continue;
        sz[x]+=sz[y];
        gl[y]=x;
        if (sz[x]==k)
        {
            for (int i=1; i<=k; i++)
                cout<<xx<<" ";
            cout<<"\n";
            return 0;
        }
    }
}