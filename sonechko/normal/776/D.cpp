#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 3e5 + 11;

vector<int> v[N],w[N];
int use[N];
vector<int> ord;
int comp[N];
int k;
int aa[N],p1[N],p2[N];

void dfs1(int l)
{
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs1(v[l][j]);
    ord.pb(l);
}

void dfs2(int l)
{
    use[l]=2;
    comp[l]=k;
    for (int j=0; j<w[l].size(); j++)
        if (use[w[l][j]]==1) dfs2(w[l][j]);
}

void up(int l, int r)
{
    v[l].pb(r);
    w[r].pb(l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>aa[i];
    for (int i=1; i<=m; i++)
    {
        int k;
        cin>>k;
        for (int j=1; j<=k; j++)
        {
            int x;
            cin>>x;
            if (p1[x]==0) p1[x]=i; else p2[x]=i;
        }
    }
    for (int i=1; i<=n; i++)
    {
        int l=p1[i],r=p2[i];
        if (aa[i]==1)
        {
            up(l,r);
            up(r,l);
            up(l+m,r+m);
            up(r+m,l+m);
        } else
        {
            up(l,r+m);
            up(r,l+m);
            up(l+m,r);
            up(r+m,l);
        }
    }

    n=m*2;
    for (int i=1; i<=n; i++)
        if (use[i]==0) dfs1(i);
    for (int i=ord.size()-1; i>=0; i--)
    if (use[ord[i]]==1)
    {
        k++;
        dfs2(ord[i]);
    }
    for (int i=1; i<=m; i++)
    if (comp[i]==comp[i+m]) {cout<<"NO"; return 0;}
    cout<<"YES";
}