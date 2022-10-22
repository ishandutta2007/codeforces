#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, h;
    cin >> n >> w >> h;
    vector <vector <pair <int, int> > > points1(2 * MAXN), points2(2 * MAXN);
    vector <pair <pair <int, int>, int> > posx, posy;
    for (int i = 0; i < n; i++) {
        int type, p, t;
        cin >> type >> p >> t;
        if (type == 1) {
            posx.push_back({{p, t}, i});
        } else {
            posy.push_back({{p, t}, i});
        }
    }
    for (auto p : posx) {
        int x = p.first.first, tm = p.first.second;
        points1[x - tm + MAXN].push_back({x, p.second});
    }
    for (auto p : posy) {
        int x = p.first.first, tm = p.first.second;
        points2[x - tm + MAXN].push_back({x, p.second});
    }
    for (auto &p : points1) {
        sort(p.begin(), p.end());
    }
    for (auto &p : points2) {
        sort(p.begin(), p.end());
    }
    vector <pair <int, int> > ans(n);
    for (int i = 0; i < 2 * MAXN; i++) {
        vector <int> data;
        for (int id = (int) points1[i].size() - 1; id >= 0; id--) {
            data.push_back(points1[i][id].second);
        }
        for (auto p : points2[i]) {
            data.push_back(p.second);
        }
        vector <pair <int, int> > data1;
        for (auto p : points2[i]) {
            data1.push_back({p.first, 0});
        }
        for (int id = (int) points1[i].size() - 1; id >= 0; id--) {
            data1.push_back({points1[i][id].first, 1});
        }
        for (int i = 0; i < (int) data.size(); i++) {
            auto p = data1[i];
            int id = data[i];
            if (!p.second) {
                ans[id] = {w, p.first};
            } else {
                ans[id] = {p.first, h};
            }
        }
    }
    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}