#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const long long L = 300000;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
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
    ll n,m;
    cin>>n>>m;
    ll ans=0, k=n;
    for (int i=1; i<=min(m,n/2); i++)
    {
        ans+=k-1+k-2;
        k-=2;
    }
    cout<<ans<<endl;
}
//1 2 3 4 5 6
//6 2 3 4 5 1
//6 5 3 4 2 1