#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, k;
vector <ll> p;

vector <ll> a, b;

void gen(ll now, ll pos) {
    if (pos >= n) {
        return;
    }
    gen(now, pos + 2);
    while (INF / p[pos] > now) {
        now *= p[pos];
        if (pos % 2 == 0) {
            a.push_back(now);
        } else {
            b.push_back(now);
        }
        gen(now, pos + 2);
    }
}

ll calc(ll x, bool print = false) {
    ll pos = upper_bound(b.begin(), b.end(), x) - b.begin() - 1;
    ll res = pos + 1;
    if (print) {
        cerr << pos + 1 << "\n";
    }
    for (ll i = 1; i < (ll) a.size(); i++) {
        if (a[i] > x) break;
        while (x / a[i] < b[pos]) {
            pos--;
        }
        res += pos + 1;
        if (print) {
            cerr << a[i] << " " << pos + 1 << "\n";
        }
    }
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cin >> k;
    a.push_back(1);
    b.push_back(1);
    gen(1, 0);
    gen(1, 1);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        //cout << mid << " " << calc(mid) << "\n";
        if (calc(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}