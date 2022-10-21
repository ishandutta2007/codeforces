#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
typedef long double ld;
const ld EPS = 1e-15;

struct Point {
    ld x, y;
    int id;
    Point operator - (Point other) const{
        return {x - other.x, y - other.y, -1};
    }
};

ld cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

int n;
Point p[N];
Point h[N];
int in[N], f[N];
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) f[i] = i;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        p[i] = {1 / (double)x, 1 / (double)y, i};
    }
    sort(p, p + n, [](const Point &p1, const Point &p2) {
        return abs(p1.x - p2.x) < EPS ? (abs(p1.y - p2.y) > EPS ? p1.y + EPS < p2.y : p1.id < p2.id) : p1.x + EPS < p2.x;
    });
    rep(i, 0, n) {
        Point pt = p[i];
        if(!cnt) h[cnt++] = pt;
        else {
            if(abs(h[cnt - 1].x - pt.x) < EPS && abs(h[cnt - 1].y - pt.y) < EPS) {
                f[pt.id] = h[cnt - 1].id;
                continue;
            }
            if(h[cnt - 1].y - EPS < pt.y) continue;

            while (cnt >= 2 && cross(h[cnt - 2] - pt, h[cnt - 1] - pt) < -EPS) {
                cnt--;
            }
            h[cnt++] = pt;

        }
    }
    for(int i = 0; i < cnt; i++) in[h[i].id] = 1;
    vi res;
    for(int i = 0; i < n; i++) {
        if(in[f[i]]) res.push_back(i);
    }
    sort(all(res));
    for(int x : res) cout << x + 1 << " ";
    cout << '\n';
}