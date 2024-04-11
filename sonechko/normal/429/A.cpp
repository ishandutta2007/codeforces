#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define ld long double
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
int use[N],init[N],goal[N],ans;
vector<int> v[N],res;
void dfs(int l, int x1, int x2)
{
    use[l]=1;
    init[l]=(init[l]+x1)%2;
    swap(x1,x2);
    if (init[l]!=goal[l]) {ans++; x2++; res.pb(l);}
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0) dfs(v[l][i],x1,x2);
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
    for (int i=1; i<=n; i++)
        cin>>init[i];
    for (int i=1; i<=n; i++)
        cin>>goal[i];
    dfs(1,0,0);
    cout<<ans<<"\n";
    for (int i=0; i<ans; i++)
        cout<<res[i]<<"\n";
}