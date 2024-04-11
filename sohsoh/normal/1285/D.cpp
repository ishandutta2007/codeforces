/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
//#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 30 + 1;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<bitset<LOG>> v;

ll ans(vector<bitset<LOG>> a, ll pos) {
    if (pos < 0) return 0;

    vector<bitset<LOG>> v0, v1;

    for (auto e : a) {
        if (e[pos]) v1.push_back(e);
        else v0.push_back(e);
    }

    if (v0.empty()) return ans(v1, pos - 1);
    if (v1.empty()) return ans(v0, pos - 1);

    ll a0 = ans(v0, pos - 1);
    ll a1 = ans(v1, pos - 1);

    return pow(2, pos) + min(a0, a1);
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bitset<LOG> t;
        ll k;
        cin >> k;
        t = k;
        v.push_back(t);
    }

    cout << ans(v, LOG - 1) << endl;
    return 0;
}