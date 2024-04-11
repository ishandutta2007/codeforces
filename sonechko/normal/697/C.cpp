#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 3000000+5;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
map<ll,ll> m1,m2;
bool get(ll v, ll pre)
{
    while (v>=1)
    {
        if (v==pre) return true;
        v/=2;
    }
    return false;
}
ll pred(ll l, ll r)
{
    ll k=l;
    while (k>=1)
    {
        if (get(r,k)) return k;
        k/=2;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    filestxt;
#endif
sync;
int n;
cin>>n;
for (int i=1; i<=n; i++)
{
    int k;
    cin>>k;
    ll l,r;
    cin>>l>>r;
    ll h=pred(l,r);
    if (k==1)
    {
        ll g;
        cin>>g;
        while (l>h)
        {
            if (l%2==0) m1[l/2]+=g; else m2[l/2]+=g;
            l/=2;
        }
        while (r>h)
        {
            if (r%2==0) m1[r/2]+=g; else m2[r/2]+=g;
            r/=2;
        }

    } else
    {
        ll ans=0;
        while (l>h)
        {
            if (l%2==0) ans+=m1[l/2]; else ans+=m2[l/2];
            l/=2;
        }
        while (r>h)
        {
            if (r%2==0) ans+=m1[r/2]; else ans+=m2[r/2];
            r/=2;
        }
cout<<ans<<endl;
    }
}
}