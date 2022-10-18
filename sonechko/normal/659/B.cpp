#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N = 1e5;
vector<pair<int,string> > v[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        int l,r;
        cin>>s>>l>>r;
        v[l].pb(mp(-r,s));
    }
    for (int i=1; i<=m; i++)
    {
        sort(v[i].begin(),v[i].end());
        if (v[i].size()>2&&v[i][2].first==v[i][1].first) cout<<"?\n";
        else
        cout<<v[i][0].second<<" "<<v[i][1].second<<"\n";
    }
}