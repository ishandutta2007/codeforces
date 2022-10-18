#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const ll N = 1e6 + 11;

vector<pair<int,ll> > v[N];
int sz[N];
ll d[N];
int pr[N];
map<pair<int,int>,int> mt;
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].pb(mp(y,z));
        mt[mp(x,y)]=i;
        mt[mp(y,x)]=i;
        v[y].pb(mp(x,z));
    }
    set<pair<ll,int> > st;
    for (int i=1; i<=n; i++)
    {
        d[i]=2e18;
        if (i==1) d[i]=0;
    }
    st.insert(mp(0,1));
    for (int j=1; j<=n; j++)
    {
        pair<ll,int> p=*st.begin();
        st.erase(p);
        int l=p.ss;
        for (int j=0; j<v[l].size(); j++)
        {
            int to=v[l][j].ff;
            if (d[to]>d[l]+v[l][j].ss)
            {
                st.erase(mp(d[to],to));
                d[to]=d[l]+v[l][j].ss;
                st.insert(mp(d[to],to));
                pr[to]=l;
            }
        }
    }
    for (int i=2; i<=n; i++)
    {
        sz[pr[i]]++;
        use[mt[mp(pr[i],i)]]=1;
    }
    vector<int> vv;
    for (int i=1; i<=n; i++)
        if (sz[i]==0) vv.pb(i);
    int t=n-1;
    while (t>k)
    {
        t--;
        int l=vv.back();
        vv.pop_back();
        use[mt[mp(pr[l],l)]]=0;
        sz[pr[l]]--;
        if (sz[pr[l]]==0) vv.pb(pr[l]);
    }
    vector<int> tt;
    for (int i=1; i<=m; i++)
        if (use[i]==1) tt.pb(i);
    cout<<tt.size()<<endl;
    for (int j=0; j<tt.size(); j++)
        cout<<tt[j]<<" ";
    cout<<endl;
}