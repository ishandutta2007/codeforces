#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt {
    ll x, y;

    pt() = default;
    pt(ll x, ll y) : x(x), y(y) {}
};

pt operator-(pt a, pt b) {
    return {a.x - b.x, a.y - b.y};
}
pt operator+(pt a, pt b) {
    return {a.x + b.x, a.y + b.y};
}
ll operator%(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
ll operator*(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

bool good(pt a, pt b, pt c) {
    return (a - b) * (c - b) > 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
    while (true) {
        bool was = false;
        for (int i = 2; i < n; i++) {
            if (!good(a[p[i - 2]], a[p[i - 1]], a[p[i]])) {
                swap(p[i], p[i - 1]);
                was = true;
                break;
            }
        }
        if (!was)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " ";
    return 0;
}