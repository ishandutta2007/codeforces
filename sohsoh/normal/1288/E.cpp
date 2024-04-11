/*
    Soheil Mohammadkhani
    Div3. Contest :|
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

const ll MAXN = 3e5 + 6;
const ll sz = 2 * MAXN;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, tree[sz] = {0}, a[sz] = {0}, mx[sz] = {0}, mn[sz] = {0}, ind[sz] = {0};

ll sum(ll i) {
    ll s = 0;
    i++;
    while (i > 0) {
        s += tree[i];
        i -= i & (-i);
    }

    return s;
}

void update(ll i, ll x) {
    i++;
    while (i <= sz) {
        tree[i] += x;
        i += i & -(i);
    }
}

void build(ll arr[]) {
    for (int i = 0; i < sz; i++) {
        update(i, arr[i]);
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mn[i] = i;
        mx[i] = i;
        ind[i] = n - i + 1;
        a[i] = 1;
    }

    build(a);
    ll pos = n + 1;
    while (m--) {
        ll i;
        cin >> i;
        mn[i] = 1;
        update(ind[i], -1);
        ll tmp_mx = n - sum(ind[i]);
        mx[i] = max(mx[i], tmp_mx);
        update(pos, 1);
        ind[i] = pos;
        pos++;
    }

//    alog(ind, n + 1);


//    for (int i = 1; i <= n; i++) {
//        cout << mn[i] << sep << mx[i] << endl;
//    }

    for (int i = 1; i <= n; i++) {
        ll tmp_mx = n - sum(ind[i]) + 1;
        mx[i] = max(mx[i], tmp_mx);
    }

    for (int i = 1; i <= n; i++) {
        cout << mn[i] << sep << mx[i] << endl;
    }
    return 0;
}