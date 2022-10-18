#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N];
vector<int> vv[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        vv[i].pb(i);
    }
    int p=n;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        p++;
        vv[l].pb(p);
        vv[r].pb(p);
    }
    for (int i=1; i<=n; i++)
    {
        cout<<vv[i].size()<<endl;
        for (int j=0; j<vv[i].size(); j++)
            cout<<i<<" "<<vv[i][j]<<endl;
    }
}