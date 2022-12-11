#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
    ll x, y;
    int n;
    explicit pt(ll x = 0, ll y = 0, int n = 0): x(x), y(y), n(n) {};
    ll operator*(const pt &a) const { return x * a.y - y * a.x; }
    ll operator%(const pt &a) const { return x * a.x + y * a.y; }
    [[nodiscard]] double len() const { return sqrt(x * x + y * y); }
    bool operator<(const pt &a) const { return a * (*this) > 0; }
};

void solve() {
    int n;
    cin >> n;
    vector<pt> a, b;
    pt p;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        p.n = i;
        if (p.x < 0 || (p.x == 0 && p.y < 0)) a.push_back(p);
        else b.push_back(p);
    }
    int i1 = 0, i2 = 1;
    double ang = 10;
    auto upd = [&](const pt &a, const pt &b) {
        ll kk = abs(a * b);
        if (kk == 0) return;
        double k = static_cast<double>(kk) / a.len() / b.len();
        if (a % b < 0) k = 3 - k;
        //cout << k << " " << kk << " " << a.n + 1 << " " << b.n + 1 << "\n";
        if (k < ang) {
            ang = k;
            i1 = a.n;
            i2 = b.n;
        }
    };

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (!a.empty() && !b.empty()) {
        upd(a[0], b.back());
        upd(a.back(), b[0]);
    }

    for (int i = 1; i < (int)a.size(); i++) {
        upd(a[i - 1], a[i]);
    }

    for (int i = 1; i < (int)b.size(); i++) {
        upd(b[i - 1], b[i]);
    }

    cout << i1 + 1 << " " << i2 + 1 << "\n";
}

int main() {
    int t = 1;
#ifdef SERT
    freopen("../a.in", "r", stdin);
    t += 1;
#endif
    // cin >> t;
    while (t--) {
        solve();
    }
}