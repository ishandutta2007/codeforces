#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

set<int> v[N];
int a[N][3];
vector<int> vv[N];
map<int,int> mt[N];
map<int,bool> can[N];
map<pair<int,pair<int,int> >,int> mtt;
bool use[N];

void dfs(int l)
{
    cout<<l<<" ";
    use[l]=1;
    for (int j=0; j<vv[l].size(); j++)
        if (use[vv[l][j]]==0) dfs(vv[l][j]);
}

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        v[i].clear();
        vv[i].clear();
        mt[i].clear();
        can[i].clear();
        use[i]=0;
    }
    mtt.clear();
    for (int i=1; i<=n-2; i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        for (int x=0; x<=2; x++)
        for (int y=0; y<=2; y++)
            if (x!=y)
        {
            int l=a[i][x];
            int r=a[i][y];
            if (mt[l][r]==0) {mt[l][r]=1; v[l].insert(r);}
        }
        for (int x=0; x<=2; x++)
        for (int y=0; y<=2; y++)
        for (int z=0; z<=2; z++)
            if (x!=y&&x!=z&&y!=z) mtt[mp(a[i][x],mp(a[i][y],a[i][z]))]=i;
    }
    set<int> st;
    for (int i=1; i<=n; i++)
        if ((int)v[i].size()==2) st.insert(i);
    vector<int> ans;
    for (int j=1; j<=n-2; j++)
    {
        int x=*st.begin();
        st.erase(x);
        int y=*v[x].begin();
        v[x].erase(y);
        int z=*v[x].begin();
        v[x].erase(z);
        int num=mtt[mp(x,mp(y,z))];
        ///cout<<"! "<<num<<"\n";
        ///cout<<"! "<<x<<" "<<y<<" "<<z<<"\n";
        ans.pb(num);
        if (can[x][y]==0) {vv[x].pb(y); vv[y].pb(x);}
        if (can[x][z]==0) {vv[x].pb(z); vv[z].pb(x);}
        if (j==n-2)
        {
            if (can[y][z]==0) {vv[y].pb(z); vv[z].pb(y);}
        }
        can[y][z]=1;
        can[z][y]=1;
        v[y].erase(x);
        v[z].erase(x);
        if ((int)v[y].size()==2) st.insert(y);
        if ((int)v[z].size()==2) st.insert(z);
    }
    /**
    for (int i=1; i<=n; i++)
    {
        cout<<i<<": ";
        for (int j=0; j<vv[i].size(); j++)
            cout<<vv[i][j]<<" ";
        cout<<"\n";
    }
    **/
    dfs(1);
    cout<<"\n";
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**
a
n - 0|1
b
n - 0|1

a b max(n1,n2)=n

aaaaaaaaaaaaa  =  k
+
abaaaaaaaaaaa  = k


aabba
**/