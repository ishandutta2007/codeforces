#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> v[N];
int deep[N],sz[N];

void dfs(int l, int pr)
{
    deep[l]=deep[pr]+1;
    sz[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) {dfs(v[l][j],l); sz[l]+=sz[v[l][j]];}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    vector<int> vv;
    for (int i=1; i<=n; i++)
        vv.pb(deep[i]-1-(sz[i]-1));
    sort(vv.begin(),vv.end());
    ll sum=0;
    for (int i=vv.size()-1; i>=vv.size()-k; i--)
    {
        sum+=vv[i];
    }
    cout<<sum;
}