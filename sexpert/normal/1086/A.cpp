#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    vector<ii> pts, ans;
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }
    sort(pts.begin(), pts.end());
    for(int x = pts[0].first; x < pts[1].first; x++)
        ans.push_back({x, pts[0].second});
    for(int x = pts[1].first + 1; x <= pts[2].first; x++)
        ans.push_back({x, pts[2].second});
    int ymax = max({pts[0].second, pts[1].second, pts[2].second}), ymin = min({pts[0].second, pts[1].second, pts[2].second});
    for(int y = ymax; y >= ymin; y--)
        ans.push_back({pts[1].first, y});
    cout << ans.size() << endl;
    for(ii p : ans)
        cout << p.first << " " << p.second << endl;
}