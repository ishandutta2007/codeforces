#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

ll a[N];
int pr[N];
vector<int> v[N];
int d[20][N];
ll sum[N];
int dep[N];
int up[N];

void dfs(int l)
{
    sum[l]=sum[pr[l]]+a[l];
    dep[l]=dep[pr[l]]+1;
    for (int j=0; j<v[l].size(); j++)
        dfs(v[l][j]);
}

int get(int l)
{
    int res=0;
    int t=-1;
    for (int j=0; j<v[l].size(); j++)
    {
        res+=get(v[l][j]);
        int p=up[v[l][j]];
        if (p!=v[l][j]&&(t==-1||dep[t]>dep[p])) t=p;
    }
    if (t==-1)
    {
        res++;
        t=up[l];
    }
    up[l]=t;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l;
    ll s;
    cin>>n>>l>>s;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        pr[i]=l;
        v[l].pb(i);
    }
    for (int i=1; i<=n; i++)
        d[0][i]=pr[i];
    for (int j=1; j<=19; j++)
    for (int i=1; i<=n; i++)
        d[j][i]=d[j-1][d[j-1][i]];
    dfs(1);
    for (int i=1; i<=n; i++)
    {
        if (a[i]>s) {cout<<-1<<endl; return 0;}
        int p=i;
        for (int j=19; j>=0; j--)
            if (d[j][p]!=0&&sum[i]-sum[pr[d[j][p]]]<=s&&dep[i]-dep[pr[d[j][p]]]<=l) p=d[j][p];
        up[i]=p;
        //cout<<i<<" - "<<p<<endl;
    }
    cout<<get(1)<<endl;
}