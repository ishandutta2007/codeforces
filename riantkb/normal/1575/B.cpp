#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

using ld = double;
using P = complex<ld>;

const ld EPS = 1e-11;

const ld PI = acos(-1);

ld get_theta(ld dist, ld radius) {
    ld theta = acos(dist / 2 / radius);
    return theta;
}


bool check(const vector<P>& points, int k, ld radius) {
    int n = points.size();
    vector<pair<ld, int>> v;
    for (int i = 0; i < n; ++i) {
        ld p_abs = abs(points[i]);
        ld p_arg = arg(points[i]);
        if (p_abs < EPS) {
            --k;
            continue;
        }
        if (p_abs > radius * 2 - EPS) continue;
        ld theta = get_theta(p_abs, radius);
        v.emplace_back(p_arg - theta, 1);
        v.emplace_back(p_arg + theta, -1);
        v.emplace_back(PI * 2 + p_arg - theta, 1);
        v.emplace_back(PI * 2 + p_arg + theta, -1);
    }
    if (k <= 0) {
        return true;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (auto& i : v) {
        cnt += i.second;
        if (cnt >= k) return true;
    }
    return false;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<P> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = P(x, y);
    }
    ld ok = 3e5, ng = 0;
    for (int _ = 0; _ < 50; ++_) {
        ld mid = (ok + ng) / 2;
        if (check(points, k, mid)) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    cout << setprecision(16) << ok << '\n';

    return 0;
}