#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e5 + 11;

vector<int> p[N];
int l1[N],r1[N],k1[N];
vector<int> v[N];
int use[N],szz[N],szp[N];
int sz[N],gl[N];
ll res[N];
int ks;
map<int,int> mt;

int glava(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=glava(gl[l]);
}

void dfs(int l)
{
    use[l]=ks;
    szp[l]=sz[l];
    szz[ks]+=sz[l];
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) {dfs(v[l][j]); szp[l]+=szp[v[l][j]];}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> vv;
    for (int i=1; i<n; i++)
    {
        cin>>l1[i]>>r1[i]>>k1[i];
        vv.pb(k1[i]);
    }
    sort(vv.begin(),vv.end());
    int kk=0;
    for (int j=0; j<vv.size(); j++)
        if (mt[vv[j]]==0) {kk++; mt[vv[j]]=kk;}
    for (int i=1; i<n; i++)
    {
        k1[i]=mt[k1[i]];
        p[k1[i]].pb(i);
    }
    for (int i=1; i<=n; i++)
    {
        gl[i]=i;
        sz[i]=1;
    }
    for (int i=1; i<=kk; i++)
    {
        vector<int> vv;
        for (int j=0; j<p[i].size(); j++)
        {
            int num=p[i][j];
            int x=glava(l1[num]),y=glava(r1[num]);
            vv.pb(x);
            vv.pb(y);
            v[x].pb(y);
            v[y].pb(x);
            ///cout<<x<<" - "<<y<<endl;
        }
        ks=0;
        for (int j=0; j<vv.size(); j++)
            if (use[vv[j]]==0) {ks++; szz[ks]=0; dfs(vv[j]);}
        for (int j=0; j<p[i].size(); j++)
        {
            int num=p[i][j];
            int x=glava(l1[num]),y=glava(r1[num]);
            if (szp[x]>szp[y]) swap(x,y);
            ///cout<<x<<" - "<<y<<" - "<<szp[x]<<" "<<szz[use[x]]<<endl;
            res[num]=szp[x]*1ll*(szz[use[x]]-szp[x]);
        }
        for (int j=0; j<vv.size(); j++)
        {
            use[vv[j]]=0;
            v[vv[j]].clear();
        }
        for (int j=0; j<p[i].size(); j++)
        {
            int num=p[i][j];
            int x=glava(l1[num]),y=glava(r1[num]);
            gl[x]=y;
            sz[y]+=sz[x];
        }
    }
    vector<int> v;
    ll ans=0;
    for (int i=1; i<n; i++)
        if (res[i]>ans) {ans=res[i]; v.clear(); v.pb(i);} else
        if (res[i]==ans) {v.pb(i);}
    cout<<ans*2<<" "<<v.size()<<"\n";
    for (int j=0; j<v.size(); j++)
        cout<<v[j]<<" ";
    cout<<"\n";
}