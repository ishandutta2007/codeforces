#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int a[N],b[N];
int use[N];
vector<pair<int,int> > vv[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        vv[b[i]].pb(mp(-a[i],i));
    }
    for (int i=1; i<=m; i++)
        sort(vv[i].begin(),vv[i].end());
    for (int i=1; i<=k; i++)
    {
        int l;
        cin>>l;
        use[l]=1;
    }
    int ans=0;
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<vv[i].size(); j++)
            if (use[vv[i][j].ss]==1)
        {
            if (j!=0) ans++;
        }
    }
    cout<<ans<<endl;
}