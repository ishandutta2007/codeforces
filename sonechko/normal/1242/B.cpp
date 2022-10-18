#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e5 + 11;

vector<int> v[N];
int gl[N];
vector<int> v1,v2;
int use[N],a[N];

void dfs(int l)
{
    use[l]=1;
    v2.clear();
    for (int j=0; j<v[l].size(); j++)
        a[v[l][j]]=1;
    vector<int> v3;
    for (int j=0; j<v1.size(); j++)
        if (a[v1[j]]==0) v3.pb(v1[j]); else v2.pb(v1[j]);
    v1=v2;
    for (int j=0; j<v[l].size(); j++)
        a[v[l][j]]=0;
    for (int j=0; j<v3.size(); j++)
        dfs(v3[j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int i=1; i<=n; i++)
        v1.pb(i);
    int kk=0;
    for (int i=1; i<=n; i++)
    if (use[i]==0) {kk++; dfs(i);}
    cout<<kk-1;
}