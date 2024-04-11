#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

long double pi = 3.141592653589793;

struct Pt {
    int x, y;

    Pt(int x, int y) : x(x), y(y) {}

    Pt operator+(Pt other) {
        return {x + other.x, y + other.y};
    }

    Pt operator-(Pt other) {
        return {x - other.x, y - other.y};
    }

    long double polar_angle() {
        long double ang = atan2((long double) y, (long double) x);
        if (ang < 0) {
            ang += 2 * pi;
        }
        return ang;
    }
};

long double e = 1e-11;

struct rofl {
    long double kek;

    rofl(long double lol) : kek(lol) {}

    bool operator<(const rofl &other) const {
        return other.kek - kek > e;
    }
};

void sol() {
    int n;
    cin >> n;
    map<rofl, int> kek;
    for (int i = 0; i < n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        Pt pt(x - u, y - v);
        kek[pt.polar_angle()]++;
    }
    int ans = 0;
    for (auto el : kek) {
        long double a1 = el.first.kek;
        if (a1 < pi) {
            if (kek.find(a1 + pi) != kek.end()) {
                ans += el.second * kek[a1 + pi];
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}