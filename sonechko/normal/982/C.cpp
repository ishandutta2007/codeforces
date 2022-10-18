#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

const int N = 1e5 + 11;

vector<int> v[N];

int ans=0;

int dfs(int l, int pr)
{
    int sz=1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) sz+=dfs(v[l][j],l);
    if (sz%2==0) ans++;
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n%2==1) {cout<<"-1"<<endl; return 0;}
    for (int j=1; j<n; j++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int p=dfs(1,0);
    cout<<ans-1<<endl;
}