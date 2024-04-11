#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Rect {
    int x1, x2, y1, y2, id;
};

int n;
vector <Rect> a;

void check(int v) {
    int maxx = -INF, minx = INF, maxy = -INF, miny = INF;
    for (int i = 0; i < n; i++) {
        if (i == v) continue;
        maxx = max(maxx, a[i].x1);
        minx = min(minx, a[i].x2);
        miny = min(miny, a[i].y2);
        maxy = max(maxy, a[i].y1);
    }
    if (minx >= maxx && miny >= maxy) {
        cout << maxx << " " << maxy << "\n";
        exit(0);
    }
}

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
    cin >> n;
    Rect t;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    t.id = 0;
    a.push_back(t);
    Rect minx = t, maxx = t, miny = t, maxy = t;
    for (int i = 1; i < n; i++) {
        cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
        t.id = i;
        if (t.x2 < minx.x2) {
            minx = t;
        }
        if (t.x1 > maxx.x1) {
            maxx = t;
        }
        if (t.y2 < miny.y2) {
            miny = t;
        }
        if (t.y1 > maxy.y1) {
            maxy = t;
        }
        a.push_back(t);
    }
    check(minx.id);
    check(maxx.id);
    check(miny.id);
    check(maxy.id);
}