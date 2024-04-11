#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 9e5 + 11;
const int MOD = 1e9 + 7;

int a[N];
int m;
vector<int> vv[2];

void up(vector<int> v, int x)
{
    int n=v.size();
    for (int i=0; i<(1<<n); i++)
    {
        ll t=0;
        for (int j=0; j<v.size(); j++)
            if (i&(1<<j)) t+=v[j];
        t%=m;
        vv[x].pb(t);
    }
    sort(vv[x].begin(),vv[x].end());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
         cin>>a[i];
    int t=n/2;
    vector<int> v;
    for (int i=1; i<=t; i++)
        v.pb(a[i]);
    up(v,0);
    v.clear();
    for (int i=t+1; i<=n; i++)
        v.pb(a[i]);
    up(v,1);
    t=vv[1].size()-1;
    int ans=0;
    for (int j=0; j<vv[0].size(); j++)
    {
        ans=max(ans,(vv[1].back()+vv[0][j])%m);
        while (t>0&&vv[1][t]>=m-vv[0][j])
            t--;
        ans=max(ans,(vv[0][j]+vv[1][t])%m);
    }
    cout<<ans<<endl;
}