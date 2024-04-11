#include<bits/stdc++.h>

using namespace std;

const long long MOD = 4294967296;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll unsigned long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair

ll c(ll n, ll m)
{
    int a[n+1];
    for (int i=1; i<=n; i++)
        a[i]=0;
    for (int i=2; i<=n; i++)
    {
        int k = i;
        int r = 2;
        while (r*r<=k)
        {
            if (k%r!=0) r++; else {a[r]++; k/=r;}
        }
        a[k]++;
    }
    for (int i=2; i<=m; i++)
    {
        ll k = i;
        ll r = 2;
        while (r*r<=k)
        {
            if (k%r!=0) r++; else {a[r]--; k/=r; }
        }
        a[k]--;
    }
    for (int i=2; i<=(n-m); i++)
    {
        ll k = i;
        ll r = 2;
        while (r*r<=k)
        {
            if (k%r!=0) r++; else {a[r]--; k/=r; }
        }
        a[k]--;
    }
    ll ans=1;
    for (ll i=2; i<=n; i++)
        for (int j=1; j<=a[i]; j++)
        ans*=i;
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    cout<<c(n,5)+c(n,6)+c(n,7)<<endl;
}