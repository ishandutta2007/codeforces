#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define ins insert
#define mp make_pair
#define ff first
#define ss second
#define out(l) cout.precision(l); cout<<fixed
const int N = 2000 + 10;
vector<int> v[N],w;
int ans;
void dfs(int l, int pred, int deep)
{
    ans=max(ans,deep);
    for (int i=0; i<v[l].size(); i++)
        if (v[l][i]!=pred) dfs(v[l][i],l,deep+1);
}
int main()
{
    int n;
    cin>>n;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        if (k==-1) w.pb(i); else v[k].pb(i);
    }
    for (int i=0; i<w.size(); i++)
        dfs(w[i],0,1);
    cout<<ans<<endl;
}