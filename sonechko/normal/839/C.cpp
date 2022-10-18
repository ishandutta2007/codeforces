#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;
vector<int> v[N];
bool use[N];
ld ans;
void dfs(int l, ld x, int dist)
{
    use[l]=1;
    int kol=0;
    for (int i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==0) {kol++;}
    if (kol==0) ans+=dist*x;
    for (int i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==0) {dfs(v[l][i],x/(ld)kol,dist+1);}
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
    cout.precision(10);
    cout<<fixed;
    dfs(1,1,0);
    cout<<ans<<endl;
}