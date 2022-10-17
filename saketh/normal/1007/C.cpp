#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

map<ll, ll> xm; // entry x->y indicates that if a >= x then b < y
map<ll, ll> ym; // entry y->x indicates that if b >= y then a < x

void update(map<ll, ll> &m, ll k, ll v) {
    auto it = m.upper_bound(k);
    if (it != m.begin() && prev(it)->second <= v)
        return;
    while (it != m.end() && it->second >= v)
        m.erase(it++);
    m[k] = v;
}

ld count(map<ll, ll> &m, ll l, ll r, ll lv) {
    ld res = 0;
    for (auto it = m.begin(); it != m.end() && next(it) != m.end(); it++) {
        if (it->first > r) break;
        auto it2 = next(it);
        ll kr = max(0ll, min(it2->first, r + 1) - max(it->first, l));
        ll vr = max(0ll, it->second - lv);
        res += ld(kr) * ld(vr);
    }
    return res;
}

ll f3(map<ll, ll> &m, ll lk, ll lv, ll N) {
    ld tot = count(m, lk, N, lv);
    ll lo = lk, hi = N;
    while (lo != hi) {
        ll mi = (lo + hi) / 2;
        if (count(m, lk, mi, lv) * 3 > tot) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N;
    cin >> N;

    ll X = 0;
    xm[1] = N + 1;
    xm[N + 1] = 1;

    ll Y = 0;
    ym[1] = N + 1;
    ym[N + 1] = 1;

    while (true) {
        ll x = f3(xm, X + 1, Y + 1, N);
        ll y = f3(ym, Y + 1, X + 1, N);

        cout << x << " " << y << endl;
        int res;
        cin >> res;
        if (!res) {
            break;
        }

        if (res == 1) {
            X = max(X, x);
        } else if (res == 2) {
            Y = max(Y, y);
        } else {
            update(xm, x, y);
            update(ym, y, x);
        }
    }

    return 0;
}