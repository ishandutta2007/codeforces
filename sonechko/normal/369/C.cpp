#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back

const int N = 1e5 + 11;
vector<int> v[N],w[N];
int use[N];
int dfs(int l, int pr, int x)
{
    int kol=0;
    for (int i=0; i<v[l].size(); i++)
        if (v[l][i]!=pr)
    {
        if (w[l][i]==2) kol+=dfs(v[l][i],l,w[l][i]); else
            kol+=dfs(v[l][i],l,w[l][i]);
    }
    if (x==2&&kol==0)
    {
        use[l]=1;
        return 1;
    }
    if (kol>0) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        v[l].pb(r);
        v[r].pb(l);
        w[l].pb(x);
        w[r].pb(x);
    }
    dfs(1,1,0);
    int ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==1) ans++;
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        if (use[i]==1) cout<<i<<" ";
    cout<<endl;
}