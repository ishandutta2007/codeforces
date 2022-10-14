#include <bits/stdc++.h>

#define int long long
#define double long double
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

const double e = 1e-8;
const double pi = acos(-1);

double polar_ang(pair<int, int> vec) {
    double ang = atan2(vec.second, vec.first);
    if (ang < 0) {
        ang += 2 * pi;
    }
    return ang;
}

double dist(pair<int, int> lol) {
    return hypot(lol.first, lol.second);
}

bool check(double rad, vector<pair<int, int>> &a, int k) {
    vector<pair<double, double>> lol;
    int cnt = 0;
    for (auto el : a) {
        if (el.first == 0 && el.second == 0) {
            cnt++;
            continue;
        }
        double d = dist(el);
        if (d + e > 2 * rad) {
            continue;
        }
        double ang = acos(d / (2 * rad));
        double pol = polar_ang(el);
        double a1 = pol - ang, a2 = pol + ang;
        if (a1 < 0) {
            a1 += 2 * pi;
        }
        if (a2 > 2 * pi) {
            a2 -= 2 * pi;
        }
        if (a1 < a2) {
            lol.emplace_back(a1 - e, a2 + e);
        } else {
            lol.emplace_back(a1 - e, 2 * pi + e);
            lol.emplace_back(0 - e, a2 + e);
        }
    }
    vector<pair<double, int>> evs;
    for (auto el : lol) {
        evs.emplace_back(el.first, 0);
        evs.emplace_back(el.second, 1);
    }
    sort(all(evs));
    if (cnt >= k) {
        return true;
    }
    for (auto el : evs) {
        if (el.second == 0) {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt >= k) {
            return true;
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pts(n);
    for (auto &el : pts) {
        cin >> el.first >> el.second;
    }
    double L = 0.0, R = 2.3e5, eps = 1e-5;
    while (R - L > eps) {
        double r = (L + R) / 2;
        if (check(r, pts, k)) {
            R = r;
        } else {
            L = r;
        }
    }
    cout << fixed << setprecision(20) << L << '\n';
}