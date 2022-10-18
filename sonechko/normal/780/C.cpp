#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 11;


vector<int> v[N];
int use[N];


void dfs(int l, int d)
{
    use[l]=d;
    int r1=d,r2=0;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]!=0) r2=use[v[l][i]];
    int p=0;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0)
    {
        p++;
        if (p==d) p++;
        if (p==r2) p++;
        if (p==d) p++;
        if (p==r2) p++;
        dfs(v[l][i],p);
    }
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
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int p=v[i].size();
        ans=max(ans,p+1);
    }
    for (int i=1; i<=n; i++)
    if (v[i].size()==ans-1)
    {
        dfs(i,1);
        break;
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        cout<<use[i]<<" ";
    cout<<endl;
}