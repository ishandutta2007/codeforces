#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;
vector<int> v[N];
vector<ll> sum[N];
ll k[N];
int n;
void dfs(int i)
{
    v[i].pb(0);
    if (i*2>n) { return;}
    if (i*2==n)
    {
        dfs(i*2);
        for (int j=0; j<v[i*2].size(); j++)
            v[i].pb(v[i*2][j]+k[i*2]);
        return;
    }
    dfs(i*2);
    dfs(i*2+1);
    vector<int> vv1=v[i*2],vv2=v[i*2+1];
    int k1=0,k2=0;
    while (k1<vv1.size()||k2<vv2.size())
    {
        if (k2!=vv2.size()&&(k1==vv1.size()||vv1[k1]+k[i*2]>vv2[k2]+k[i*2+1]))
        {
            v[i].pb(vv2[k2]+k[i*2+1]);
            k2++;
        } else
        {
            v[i].pb(vv1[k1]+k[i*2]);
            k1++;
        }
    }
}
ll res(int i, ll kk)
{
    if (i>n) return 0;
    if (kk<0) return 0;
    int l=0,r=v[i].size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (v[i][mid]>kk) r=mid; else l=mid;
    }
    if (v[i][r]<=kk) return 1LL*(r+1)*kk-sum[i][r];
    if (v[i][l]<=kk) return 1LL*(l+1)*kk-sum[i][l];
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1; i<=n-1; i++)
    {
        cin>>k[i+1];
    }
    dfs(1);
    for (int i=1; i<=n; i++)
    {
        ll ss=0;
        for (int j=0; j<v[i].size(); j++)
        {
            ss+=v[i][j];
            sum[i].pb(ss);
        }
    }
    for (int j=1; j<=m; j++)
    {
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        ans+=res(l,r);
        while (l>1)
        {
            r-=k[l];
            if (r<0) break;
            ans+=r;
            ll pr=l;
            l/=2;
            if (pr%2==0) ans+=res(l*2+1,r-k[l*2+1]); else
                ans+=res(l*2,r-k[l*2]);
        }
        cout<<ans<<"\n";
    }
}

/**
     1
   2(2)     3(1)
 4(1) 5(3)  6(2)
**/