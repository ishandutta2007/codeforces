#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

vector<pair<int,ll> > v[N];
ll a[N];
int prr[N];
vector<int> vv;
ll deep[N];
int ans[N];

int up_ans(int x)
{
    int l=0,r=vv.size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (deep[x]-deep[vv[mid]]<=a[x]) r=mid; else l=mid;
    }
    if (deep[x]-deep[vv[l]]<=a[x]) return vv[l];
    return vv[r];
}

void dfs(int l)
{
    vv.pb(l);
    int p=up_ans(l);
    ans[prr[l]]++;
    ans[prr[p]]--;
    for (int j=0; j<v[l].size(); j++)
    {
        int to=v[l][j].ff;
        deep[to]=deep[l]+v[l][j].ss;
        dfs(to);
        ans[l]+=ans[to];
    }
    vv.pop_back();
}

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    {
        int pr,w;
        cin>>pr>>w;
        v[pr].pb(mp(i,w));
        prr[i]=pr;
    }
    dfs(1);
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}