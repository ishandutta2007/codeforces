#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll sq(ll x) {
    return x * x;
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<ll, ll>> pts(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &pts[i].first, &pts[i].second);
    }
    auto ptdist = [&] (int i, int j) { // squared
        return sq(pts[i].first - pts[j].first) + sq(pts[i].second - pts[j].second);
    };
    /*
    auto pwede = [&] (int i, int j, int k) {
        // can your path go i -> j -> k?
    };
    */
    vector<bool> picked(n);
    vector<int> ans;
    int firstPoint = distance(begin(pts), min_element(begin(pts), end(pts)));
    ans.push_back(firstPoint);
    picked[firstPoint] = true;
    while (ans.size() < n) {
        int nextPoint = -1;
        for (int i = 0; i < n; ++i) {
            if (picked[i]) continue;
            if (nextPoint == -1 || ptdist(ans.back(), i) > ptdist(ans.back(), nextPoint)) {
                nextPoint = i; 
            }
        }
        ans.push_back(nextPoint);
        picked[nextPoint] = true;
    }
    for (int v : ans) printf("%d ", v + 1);
    printf("\n");
    return 0;
}