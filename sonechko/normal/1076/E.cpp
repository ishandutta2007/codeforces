#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const ll N = 1e6 + 11;

vector<int> v[N];
vector<int> d[N];
vector<ll> sum[N];
int tin[N],tout[N],tim;
int deep[N],num[N];
int max_deep;
ll ans[N];

pair<int,int> get(int x, int dp)
{
    if (dp>max_deep) return mp(-1,-1);
    if (d[dp].size()==0) return mp(-1,-1);
    int l=0,r=d[dp].size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (tin[d[dp][mid]]<tin[x]) l=mid; else r=mid;
    }
    int l1,r1;
    if (tin[d[dp][l]]>=tin[x]) l1=l; else
    if (tin[d[dp][r]]>=tin[x]) l1=r; else return mp(-1,-1);
    l=0;
    r=d[dp].size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (tout[d[dp][mid]]>tout[x]) r=mid; else l=mid;
    }
    if (tout[d[dp][r]]<=tout[x]) r1=r; else
    if (tout[d[dp][l]]<=tout[x]) r1=l; else return mp(-1,-1);
    if (l1>r1) return mp(-1,-1);
    return mp(l1,r1);
}

void dfs(int l, int pr)
{
    deep[l]=deep[pr]+1;
    max_deep=max(max_deep,deep[l]);
    num[l]=d[deep[l]].size();
    d[deep[l]].pb(l);
    sum[deep[l]].pb(0);
    tim++;
    tin[l]=tim;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    tout[l]=tim;
}

void dfss(int l, int pr)
{
    ans[l]+=ans[pr];
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfss(v[l][j],l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        ll d;
        cin>>l>>r>>d;
        sum[deep[l]][num[l]]+=d;
        //cout<<deep[l]<<" "<<num[l]<<" += "<<d<<endl;
        if (sum[deep[l]].size()!=num[l]+1) sum[deep[l]][num[l]+1]-=d;
        pair<int,int> p=get(l,deep[l]+r+1);
        //cout<<deep[l]+r+1<<" "<<p.ff<<".."<<p.ss<< "-=d"<<endl;
        if (p.ff==-1) {} else
        {
            sum[deep[l]+r+1][p.ff]-=d;
            if (sum[deep[l]+r+1].size()!=p.ss+1)
            sum[deep[l]+r+1][p.ss+1]+=d;
        }
    }
    for (int i=1; i<=max_deep; i++)
    {
        for (int j=1; j<d[i].size(); j++)
        {
            sum[i][j]+=sum[i][j-1];
        }
        for (int j=0; j<d[i].size(); j++)
            ans[d[i][j]]=sum[i][j];
    }
    dfss(1,0);
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
            cout<<endl;
}