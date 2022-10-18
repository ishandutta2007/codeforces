#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD
int use[N],a[N],ans;
vector<int> v[N],w;
void dfs(int l)
{
    use[l]=1;
    if (ans==-1) return;
    for (int j=0; j<v[l].size(); j++)
    {
        int to=v[l][j];
        if (use[to]==1) {ans=-1; return;}
        if (use[to]==0) dfs(to);
    }
    use[l]=2;
    w.push_back(l);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        for (int j=1; j<=l; j++)
        {
            int k;
            cin>>k;
            v[i].push_back(k);
        }
    }
    for (int i=1; i<=m; i++)
        if (use[a[i]]==0) dfs(a[i]);
    if (ans==-1) cout<<-1<<endl; else
    {
        cout<<w.size()<<endl;
        for (int i=0; i<w.size(); i++)
            cout<<w[i]<<" ";
        cout<<endl;
    }
}