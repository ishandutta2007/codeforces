/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 30;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int tree[MAXN] = {0};
int n, q, N;

void update(ll i, ll x) {
    i++;
    while (i <= N) {
        tree[i] += x;
        i += i & (-i);
    }
}

ll sum(ll i) {
    i++;
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= i & (-i);
    }

    return ans;
}

void bit_insert(ll x) {
    update(x, 1);
}

void bit_remove(ll x) {
    update(x, -1);
}

ll query(ll x) {
//    debug(x);
    ll l = 0, h = n;
    while (l < h) {
        ll mid = (l + h) / 2;
        if (x <= sum(mid)) h = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    fast_io;
    cin >> n >> q;
    N = n + 10;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bit_insert(x);
    }

    while (q--) {
        ll x;
        cin >> x;
        if (x > 0) bit_insert(x);
        else {
            ll p = query(-1 * x);
            bit_remove(p);
        }
    }

    if (sum(n) == 0) kill(0);
    for (int i = 0; i <= n; i++) {
        if (sum(i) > 0) kill(i);
    }
    return 0;
}