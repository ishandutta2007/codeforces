#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int sz[N];
vector<int> v[N];

void dfs(int l)
{
    if (v[l].size()==0) sz[l]=1;
    for (int j=0; j<v[l].size(); j++)
    {
        dfs(v[l][j]);
        sz[l]+=sz[v[l][j]];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l].pb(i);
    }
    dfs(1);
    sort(sz+1,sz+n+1);
    for (int i=1; i<=n; i++)
        cout<<sz[i]<<" ";
    cout<<endl;

}