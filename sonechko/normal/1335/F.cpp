#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 1e6 + 11;

int n,m;
int use[N];
char a[N],d[N];
vector<int> v[N];
vector<int> vv,pp;
int k[N];
int ans1,ans2;
int nx[N];

int num(int l, int r)
{
    return (l-1)*m+r;
}

void dfss(int l, int dist)
{
    use[l]=1;
    ///cout<<l<<" - "<<dist<<" - "<<d[l]<<endl;
    if (k[dist]==0&&d[l]=='1') k[dist]=1; else
    if (d[l]=='0') k[dist]=2;
    for (int j=0; j<v[l].size(); j++)
    {
        int to=v[l][j];
        if (use[to]==0) dfss(to,(dist+1)%((int)pp.size()));
    }
}

void ups()
{
    reverse(pp.begin(),pp.end());
    /**for (int j=0; j<pp.size(); j++)
        cout<<pp[j]<<" ";
    cout<<"\n";**/
    int l=pp[0];
    for (int j=0; j<pp.size(); j++)
        k[j]=0;
    dfss(l,0);
    for (int j=0; j<pp.size(); j++)
        if (k[j]==1) ans1++; else
        if (k[j]==2) {ans1++; ans2++;}
}

void dfs(int l)
{
    use[l]=1;
    vv.pb(l);
    int to=nx[l];
    if (use[to]==1)
    {
        pp.clear();
        for (int i=0; i<vv.size(); i++)
            use[vv[i]]=0;
        for (int i=vv.size()-1; i>=0; i--)
        {
            pp.pb(vv[i]);
            if (vv[i]==to) break;
        }
        ups();
        return;
    } else dfs(to);
}

void up()
{
    cin>>n>>m;
    ans1=0;
    ans2=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>d[num(i,j)];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[num(i,j)];
    for (int i=1; i<=n*m; i++)
    {
        use[i]=0;
        v[i].clear();
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        if (a[num(i,j)]=='U')
            nx[num(i,j)]=num(i-1,j); else
        if (a[num(i,j)]=='R')
            nx[num(i,j)]=num(i,j+1); else
        if (a[num(i,j)]=='D')
            nx[num(i,j)]=num(i+1,j); else
            nx[num(i,j)]=num(i,j-1);
        v[nx[num(i,j)]].pb(num(i,j));
    }
    for (int i=1; i<=n*m; i++)
        if (use[i]==0)
    {
        vv.clear();
        dfs(i);
    }
    cout<<ans1<<" "<<ans2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}