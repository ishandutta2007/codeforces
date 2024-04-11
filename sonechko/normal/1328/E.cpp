#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 5e5 + 11;

int tin[N],tout[N],deep[N],timee;
vector<int> v[N];
int t[N];
int prr[N];

void dfs(int l, int pr)
{
    prr[l]=pr;
    deep[l]=deep[pr]+1;
    timee++;
    tin[l]=timee;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    tout[l]=timee;
}

bool pred(int l, int r)
{
    return (tin[l]<=tin[r]&&tout[r]<=tout[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    for (int ii=1; ii<=m; ii++)
    {
        int k;
        cin>>k;
        int px=0;
        for (int j=1; j<=k; j++)
        {
            cin>>t[j];
            if (px==0||deep[t[j]]>deep[px]) px=t[j];
        }
        int ans=1;
        for (int j=1; j<=k; j++)
            if (pred(t[j],px)==0&&pred(prr[t[j]],px)==0) ans=0;
        if (ans==1) cout<<"YES\n"; else cout<<"NO\n";
    }
}