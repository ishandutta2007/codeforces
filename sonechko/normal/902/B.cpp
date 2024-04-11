#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 1e6 + 11;

int c[N],ans;
vector<int> v[N];

void dfs(int l, int color)
{
    if (c[l]!=color) {ans++; color=c[l];}
    for (int i=0; i<v[l].size(); i++)
    dfs(v[l][i],color);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ans=0;
    for (int i=2; i<=n; i++)
    {
        int x;
        cin>>x;
        v[x].pb(i);
    }
    for (int i=1; i<=n; i++)
        cin>>c[i];
    dfs(1,0);
    cout<<ans<<endl;
}