#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int INF = 1500000000;
constexpr ll LLINF = 1000000000000000000;
 
 struct rurm {
    int al, ar;
    ll rmin;
    rurm *_left, *_right;
    rurm(int i, int j) : al(i), ar(j), rmin(LLINF), _left(nullptr), _right(nullptr) { }
    rurm *left() {
        if (_left != nullptr) return _left;
        else return _left = new rurm(al, (al + ar) / 2);
    }
    rurm *right() {
        if (_right != nullptr) return _right;
        else return _right = new rurm((al + ar) / 2 + 1, ar);
    }
    ll rangeMin(int i, int j) {
        i = max(i, 0); j = min(j, INF);
        if (i > j || ar < i || j < al) return LLINF;
        else if (i <= al && ar <= j) return rmin;
        else return min(left()->rangeMin(i, j), right()->rangeMin(i, j));
    }
    void pointSet(int i, ll v) {
        if (i < al || ar < i) return;
        else if (al == ar) rmin = v;
        else { 
            left()->pointSet(i, v); right()->pointSet(i, v);
            rmin = min(left()->rmin, right()->rmin);
        }
    }
};
 
int main() {
    int n; scanf("%d", &n);
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; ++i) scanf("%lld %lld", &a[i], &c[i]);
    map<ll, ll> compFloors;
    for (int i = 0; i < n; ++i) compFloors[a[i]] = max(compFloors[a[i]], c[i]);
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += c[i];
    // compute the extra
    int k = compFloors.size();
    vector<ll> compA, compC;
    for (auto [x, y] : compFloors) {
        compA.push_back(x);
        compC.push_back(y);
    }
    vector<int> farthestReach(k);
    for (int i = 0; i < k; ++i) {
        int firstUnreach = distance(begin(compA), upper_bound(begin(compA), end(compA), compA[i] + compC[i]));
        farthestReach[i] = firstUnreach - 1;
    }
    rurm normal(0, k), shifted(0, k);
    normal.pointSet(k - 1, 0);
    shifted.pointSet(k - 1, compA.back());
    for (int i = k - 2; i >= 0; --i) {
        ll inFloor = normal.rangeMin(0, farthestReach[i]);
        ll outFloor = shifted.rangeMin(farthestReach[i] + 1, k) - compA[i] - compC[i];
        ll val = min(inFloor, outFloor);
        normal.pointSet(i, val);
        shifted.pointSet(i, val + compA[i]);
    }
    printf("%lld\n", ans + normal.rangeMin(0, 0));
    return 0;
}