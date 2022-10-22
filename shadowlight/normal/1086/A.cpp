#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    vector <pair <int, int> > a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector <pair <int, int> > res;
    int sx = a[0].first, sy = a[0].second;
    res.push_back({sx, sy});
    while (sx < a[1].first) {
        sx++;
        res.push_back({sx, sy});
    }
    int l = sy, r = sy;
    while (sy > a[1].second) {
        sy--;
        res.push_back({sx, sy});
    }
    while (sy < a[1].second) {
        sy++;
        res.push_back({sx, sy});
    }
    l = min(l, sy), r = max(r, sy);
    while (r < a[2].second) {
        r++;
        res.push_back({sx, r});
    }
    while (l > a[2].second) {
        l--;
        res.push_back({sx, l});
    }
    while (sx < a[2].first) {
        sx++;
        res.push_back({sx, a[2].second});
    }
    cout << res.size() << "\n";
    for (auto t : res) {
        cout << t.first << " " << t.second << "\n";
    }
}