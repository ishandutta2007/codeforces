#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
#define sqr(a) ((a)*(a))

const int N = 1e6 + 11;
int use[N];
vector<int> v[N],v1,v2;
void dfs(int l, int r)
{
    use[l]=r;
    if (r==1) v1.pb(l); else v2.pb(l);
    for (int i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==r) {cout<<"0"<<endl; exit(0);} else
    if (use[v[l][i]]==0) dfs(v[l][i],3-r);
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
    dfs(1,1);
    ll ans=0;
    for (int i=0; i<v1.size(); i++)
        ans+=(ll)v2.size()-(ll)v[v1[i]].size();
    cout<<ans<<endl;
}