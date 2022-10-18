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
    ll n,m;
    cin>>n>>m;
    string a[n+1];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll k=0,p=0;
    for (int i=n; i>=1; i--)
    {
        if (a[i]=="half") {p+=k*m; k*=2;} else
            {
                p+=(k*m)+m/2;
                k=k*2+1;
            }
    }
    cout<<p<<endl;
}