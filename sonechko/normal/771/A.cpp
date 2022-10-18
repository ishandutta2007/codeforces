#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v[N];
int use[N];
ll p,kol1=0,kol2=0;

void dfs(int l)
{
    use[l]=p;
    kol1++;
    for (int j=0; j<v[l].size(); j++)
    if (use[v[l][j]]==0) dfs(v[l][j]);
    kol2+=1ll*v[l].size();
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
        if (use[i]==0)
    {
        p++;
        kol1=0;
        kol2=0;
        dfs(i);
        kol2/=2;
        if (kol1*(kol1-1)/2!=kol2) {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
}