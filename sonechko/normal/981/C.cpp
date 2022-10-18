#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N];
vector<int> gg;

bool dfs(int l, int pr)
{
    int ts=0;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        ts++;
        if (dfs(v[l][j],l)==0) return 0;
    }
    if (ts==0) gg.pb(l);
    if (ts>1) return false;
    return true;
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
    int p=1;
    for (int j=1; j<=n; j++)
        if (v[j].size()>v[p].size()) p=j;
    for (int j=0; j<v[p].size(); j++)
        if (dfs(v[p][j],p)==0) {cout<<"No"<<endl; return 0;}
    cout<<"Yes"<<endl;
    cout<<gg.size()<<endl;
    for (int j=0; j<gg.size(); j++)
        cout<<p<<" "<<gg[j]<<"\n";
    cout<<endl;
}