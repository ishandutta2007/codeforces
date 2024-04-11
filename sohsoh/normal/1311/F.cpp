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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9

struct BIT {
    ll sz, *tree;
    BIT(ll n) {
        sz = n + 3;
        tree = new ll[sz];
        fill(tree, tree + sz, 0);
    }

    ll update(ll i, ll val) {
        i++;
        while (i < sz) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    ll sum(ll i) {
        i++;
        ll res = 0;
        while (i > 0) {
            res += tree[i];
            i -= (i & -i);
        }

        return res;
    }
};

ll n;
pll a[MAXN];

bool comp(pll a, pll b) {
    return a.Y < b.Y;
}

void this_is_a_long_function_name() {
    sort(a, a + n, comp);
    ll prv = INF, val = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].Y != prv) val++;
        prv = a[i].Y;
        a[i].Y = val;
    }
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].X;
    for (int i = 0; i < n; i++) cin >> a[i].Y;
    this_is_a_long_function_name();
    sort(a, a + n);

    BIT b = BIT(n), pos_sum = BIT(n);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll x = a[i].X, y = a[i].Y;
        ans += b.sum(y) * x - pos_sum.sum(y);
        b.update(y, 1);
        pos_sum.update(y, x);
    }

    cout << ans << endl;
    return 0;
}