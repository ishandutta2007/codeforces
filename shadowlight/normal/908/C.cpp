#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

double rast(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
    int n;
    double r;
    cin >> n >> r;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout.precision(20);
    vector <pair <double, double> > coord;
    for (int i = 0; i < n; i++) {
        double x = a[i];
        double ay = r;
        for (auto p : coord) {
            double x1 = p.first, y1 = p.second;
            double ly = y1, ry = INF;
            if (rast(x, ly, x1, y1) - 2 * r > EPS) {
                continue;
            }
            for (int j = 0; j < 100; j++) {
                double mid = (ly + ry) / 2;
                if (rast(x, mid, x1, y1) > 2 * r) {
                    ry = mid;
                } else {
                    ly = mid;
                }
            }
            ay = max(ay, ly);
        }
        coord.push_back({x, ay});
        cout << ay << " ";
    }
}