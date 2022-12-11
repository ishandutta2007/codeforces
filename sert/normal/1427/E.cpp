#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, pair<ll, ll>> T_PREV;

const int N = 4000;

vector<string> ans;

ll mult2(ll x, int dif) {
    for (int i = 0; i < dif; i++) {
        ans.push_back(to_string(x) + " + " + to_string(x));
        x *= 2;
    }
    return x;
}

ll xxor(ll a, ll b) {
    ans.push_back(to_string(a) + " ^ " + to_string(b));
    return (a ^ b);
}

ll add(ll a, ll b) {
    ans.push_back(to_string(a) + " + " + to_string(b));
    return a + b;
}

int lel(int x, int y) {
    //cout << x << " " << y << "\n";
    if (y % 2) return y;
    while (y <= x * 2) {
        if ((x ^ y) < x) return xxor(x, y);
        y = add(y, y);
    }
    exit(13);
}

int kek(int x) {
    //cout << x << "\n";
    int b1 = 31 - __builtin_clz(x);
    int b2 = 31 - __builtin_clz(x ^ (1 << b1));
    int dif = b1 - b2;
    ll x2 = mult2(x, dif);
    ll x2_ = xxor(x2, x);
    //cout << "b12: " << b1 << " " << b2 << "\n";
    //cout << x2_ << " " << x2 << "\n";
    for (int i = 0; i < 3; i++) {
        x2_ = add(x2_, x);
        if ((x2_ ^ x2) < x) return lel(x, xxor(x2_, x2));
        x2 = add(x2, x);
        if ((x2_ ^ x2) < x) return lel(x, xxor(x2_, x2));
    }
    cout << "bad " << x << "\n";
    exit(12);
}

void solve() {
    int x;
    cin >> x;
    while (x != 1) {
        x = kek(x);
    }
    cout << ans.size() << "\n";
    for (const string &s : ans) cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 1;
#endif
    while (t--) {
        solve();
    }
}