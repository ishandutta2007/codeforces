#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v[N],ps;
int use[N],us[N],n,m,gg,L,R;

void dfs2(int l)
{
    if (gg==1) return;
    us[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (us[v[l][j]]==0&&(l!=L||v[l][j]!=R)) dfs2(v[l][j]); else
        if (us[v[l][j]]==1&&(l!=L||v[l][j]!=R)) {gg=1; return;}
    us[l]=2;
}

void up(int l, int r)
{
    L=l;
    R=r;
    for (int i=1; i<=n; i++)
        us[i]=0;
    gg=0;
    for (int i=1; i<=n; i++)
        if (us[i]==0) dfs2(i);
    if (gg==0) {cout<<"YES"<<endl; exit(0);}
}

void rec(int l)
{
    int tr=0;
    for (int j=0; j<ps.size(); j++)
    {
        if (ps[j]==l) tr=1;
        if (tr==1&&j!=ps.size()-1) up(ps[j],ps[j+1]);
    }
    up(ps.back(),l);
}

void dfs(int l)
{
    use[l]=1;
    ps.pb(l);
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j]); else
        if (use[v[l][j]]==1)
    {
        rec(v[l][j]);
        cout<<"NO"<<endl;
        exit(0);
    }
    use[l]=2;
    ps.pop_back();
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
    }
    up(0,0);
    for (int i=1; i<=n; i++)
        if (use[i]==0) dfs(i);
    cout<<"NO"<<endl;
}