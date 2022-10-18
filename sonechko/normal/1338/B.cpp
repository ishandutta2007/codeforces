#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

vector<int> v[N];

int p[N][2];
int ks[N];

void dfs(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        int to=v[l][j];
        dfs(to,l);
        if (p[to][1]) p[l][0]=1;
        if (p[to][0]) p[l][1]=1;
    }
    if ((int)v[l].size()==1) p[l][0]=1;
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
    int gl=0;
    for (int i=1; i<=n; i++)
        if ((int)v[i].size()>1) gl=i;
    dfs(gl,0);
    if (p[gl][0]+p[gl][1]==1)
        cout<<1<<" "; else cout<<3<<" ";
    for (int i=1; i<=n; i++)
        if ((int)v[i].size()==1) ks[v[i][0]]++;
    int res=n-1;
    for (int i=1; i<=n; i++)
        if (ks[i]>1) res-=ks[i]-1;
    cout<<res<<"\n";
}