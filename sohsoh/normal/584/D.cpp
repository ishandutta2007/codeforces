/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[MAXN] = {0};
vector<ll> p;

bool is_prime(ll n) {
    if (n < MAXN) return (G[n] == 0);
    ll sq = sqrt(n);
    for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
    return true;
}

int main() {
    G[1] = 1;
    G[0] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (G[i]) continue;
        p.push_back(i);
        for (int j = 2; j * i < MAXN; j++) G[i * j] = 1;
    }

    ll n;
    cin >> n;
    if (is_prime(n)) return cout << 1 << endl << n << endl, 0;
    if (n % 2 == 0) for (ll e : p) if (is_prime(n - e)) return cout << 2 << endl << e << sep << n - e << endl, 0;
    n -= 3;
    cout << 3 << endl << 3 << sep;
    for (ll e : p) if (is_prime(n - e)) return cout << e << sep << n - e << endl, 0;
    return 0;
}