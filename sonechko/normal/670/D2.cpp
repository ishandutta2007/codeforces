#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 100002;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
ll a[N],b[N],n,m;
bool tet(ll p)
{
    ll k=m;
    for (int i=1; i<=n; i++)
    {
        ll c=a[i]*p-b[i];
        if (c<0) c=0;
        if (c>k) return false;
        k-=c;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int j=1; j<=n; j++)
        cin>>b[j];
    ll l=0, r=2000000000;
    while (r-l>1)
    {
        ll k=(l+r)/2;
        if (tet(k)) l=k; else r=k;
    }
    if (tet(r)) cout<<r<<endl; else cout<<l<<endl;
}