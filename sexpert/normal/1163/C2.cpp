#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

struct line {
    int v1, v2, k;
    bool operator<(const line &o) const { return tie(v1, v2, k) < tie(o.v1, o.v2, o.k); }
};

set<line> pairwise;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ii> points;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int dx = points[j].first - points[i].first, dy = points[j].second - points[i].second;
            if(dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            if(dx == 0 && dy < 0)
                dy = -dy;
            int g = __gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            pairwise.insert({dx, dy, points[i].first * dy - points[i].second * dx});
        }
    }
    map<pair<int, int>, int> cnt;
    ll ans = pairwise.size();
    ans = ans*(ans - 1)/2;
    for(auto l : pairwise) {
        ans -= cnt[{l.v1, l.v2}];
        cnt[{l.v1, l.v2}]++;
    }
    cout << ans << '\n';
}