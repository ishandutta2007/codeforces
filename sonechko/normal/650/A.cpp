#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 1000005;
const int M = 10;
const string charA = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string chara = ".abcdefghijklmnopqrstuvwxyz";
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
#define next ljjdfienf
map<pair<int,int>, ll> m1m2;
map<int,ll> m1,m2;
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        ans+=m1[l]+m2[r]-m1m2[mp(l,r)];
        m1[l]++;
        m2[r]++;
        m1m2[mp(l,r)]++;
    }
    cout<<ans<<endl;
}