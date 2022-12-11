#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
typedef pair<string, int> ii;
#define MAXN 200005
#define PI 3.14159265358979
#define OP 1
#define CLO 0
#define rep(i,x,y) for (i = (x); i < (y); i++)
typedef long double ld;
typedef complex<long double> cd;
typedef pair<ld, bool> ev;
int n,k;
vector<cd> points;
ld dist[MAXN];
bool can(ld r) {
    int i;
    ld d = 2.0 * r;
    cd spec = cd(0,0);
    vector<ev> events;
    rep(i,0,n) {
        if (dist[i] - d > 0.0) continue;
        ld B = acos(dist[i] / d);
        ld A = arg(points[i] - spec);
        ld alpha = A - B, beta = A + B;
        events.push_back({alpha, OP});
        events.push_back({alpha + 2.0 * PI, OP});
        events.push_back({beta, CLO});
        events.push_back({beta + 2.0 * PI, CLO});
    }
    sort(events.begin(), events.end());
    int count = 0;
    for (auto &[ang, typ] : events) {
        if (typ == OP) count++;
        else count--;
        if (count >= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    points.resize(n);
    int i;
    cd origin = cd(0,0);
    rep(i,0,n) {
        int a,b; cin >> a >> b;
        points[i] = cd((ld)(a),(ld)(b));
        dist[i] = abs(points[i] - origin);
    }
    ld lo = 0.0, hi = 200005, ans = -1.0;
    while (hi - lo > 1e-9) {
        ld mid = (hi + lo) / 2.0;
        if (can(mid)) {
            ans = mid;
            hi = mid;
        } else lo = mid;
    }
    cout << fixed << setprecision(6) << ans;
}