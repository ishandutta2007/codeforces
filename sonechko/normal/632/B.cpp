#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ll long long
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define f first
#define mp make_pair

int main()
{
    int n;
    cin>>n;
    ll a[n];
    for (int i=0; i<n; i++)
        cin>>a[i];
    string s;
    cin>>s;
    ll l=0, r=0;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='A') l+=a[i]; else r+=a[i];
    }
    ll l1=l, r1=r;
    ll ans=r;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='A') {l-=a[i]; r+=a[i];} else {l+=a[i]; r-=a[i];}
        ans=max(ans,r);
    }
    l=l1;
    r=r1;
    for (int i=n-1; i>=0; i--)
    {
        if (s[i]=='A') {l-=a[i]; r+=a[i];} else {l+=a[i]; r-=a[i];}
        ans=max(ans,r);
    }
    cout<<ans<<endl;
}