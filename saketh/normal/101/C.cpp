#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void rot(pair<int, int> &p) {
    swap(p.first, p.second);
    p.first *= -1;
}

double norm(pair<int, int> p) {
    double x = p.first, y = p.second;
    return sqrt(x * x + y * y);
}

ll qua(double siz, pair<int, int> b) {
    double bs = norm(b);
    return round(siz / bs);
}

bool make(pair<int, int> t, pair<int, int> b) {
    if (t.first == 0 && t.second == 0) return true;
    if (b.first == 0 && b.second == 0) return t == b;

    double bm = norm(b);
    double dp = (t.first * 1.0 * b.first + t.second * 1.0 * b.second);

    double sz = dp / bm;

    ll v1 = qua(sz, b);

    double rs = sqrt(max(pow(norm(t), 2) - sz * sz, 1e-9));
    ll v2 = qua(rs, b);

    ll x = b.first * v1;
    ll y = b.second * v1;

    for (int i = 0; i < 4; i++) {
        if (x + b.first * v2 == t.first && y + b.second * v2 == t.second) {
            return true;
        }
        rot(b);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    pair<int, int> a, b, c;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    for (int i = 0; i < 4; i++) {
        pair<int, int> d = { b.first - a.first, b.second - a.second };

        if (make(d, c)) {
            cout << "YES\n";
            return 0;
        }

        rot(a);
    }
    
    cout << "NO\n";
}