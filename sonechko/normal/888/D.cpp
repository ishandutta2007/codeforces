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

ll c(int n, int k)
{
    ll res=1;
    for (int i=n-k+1; i<=n; i++)
        res*=1LL*i;
    for (int i=1; i<=k; i++)
        res/=1LL*i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=1;
    if (m>=2)
    {
        ans+=c(n,2);
    }
    if (m>=3)
    {
        ans+=c(n,3)*2;
    }
    if (m>=4)
    {
        ans+=c(n,4)*9;
    }
    cout<<ans<<endl;
}