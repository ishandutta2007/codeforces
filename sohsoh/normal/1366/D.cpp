/*
    Soheil Mohammadkhani
    3 points remained to candidate master bro :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e7 + 10; //Change this pls :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> ans1, ans2, prime_vec;

bool is_prime[MAXN];

ll solve() {
    ll n;
    cin >> n;
    ll sq = sqrt(n);
    ll x = 0;
    for (ll i : prime_vec) {
        if (i > sq) break;
        if (n % i == 0) {
            x = i;
            break;
        }
    }

    if (x < 2) {
        ans1.push_back(-1);
        ans2.push_back(-1);
        return 0;
    }

    ll a2 = n;
    while (a2 % x == 0) a2 /= x;
    if (a2 == 1 || __gcd(a2 + x, n) != 1) {
        ans1.push_back(-1);
        ans2.push_back(-1);
        return 0;
    }

    ans1.push_back(a2);
    ans2.push_back(x);
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    fill(is_prime, is_prime + MAXN, true);
    for (int i = 2; i < MAXN; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j < MAXN; j += i) is_prime[j] = false;
    }

    for (int i = 2; i < MAXN; i++) if (is_prime[i]) prime_vec.push_back(i);
//    debug(prime_vec.size())
    while (t--) {
        solve();
    }

    for (ll e : ans1) cout << e << sep;
    cout << endl;

    for (ll e : ans2) cout << e << sep;
    cout << endl;
    return 0;
}