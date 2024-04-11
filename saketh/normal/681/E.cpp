#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;
typedef vector<int> vi;

const double PI = 2 * atan2(1, 0);
const double EPS = 1e-15;

double solve(double x0, double y0, double d, int N, vi &x, vi &y, vi &r) {
    vector<pair<double, double>> ranges;

    for (int i = 0; i < N; i++) {
        double dist = sqrt(pow(x0 - x[i], 2) + pow(y0 - y[i], 2));
        if (dist < r[i] + EPS) return 1;
        if (dist > d + r[i]) continue;

        double ctr = atan2(y[i] - y0, x[i] - x0);
        double r2 = 1.0 * r[i] * r[i];
        double leg = max(min(d, sqrt(dist * dist - r2)), EPS);
        double wid = acos((leg * leg + dist * dist - r2) / (2 * leg * dist));

        double first = ctr - wid, last = ctr + wid;

        if (ctr - wid < -PI) {
            ranges.emplace_back(ctr - wid + 2 * PI, PI);
            first = -PI;
        } 

        if (ctr + wid > PI) {
            ranges.emplace_back(-PI, ctr + wid - 2 * PI);
            last = PI;
        }
            
        ranges.emplace_back(first, last);
    }

    sort(ranges.begin(), ranges.end());

    double ans = 0;
    double sta = -PI, end = -PI;

    for (auto r : ranges) {
        if (r.first < end + EPS) {
            end = max(end, r.second);
        } else {
            ans += end - sta;
            sta = r.first;
            end = r.second;
        }
    }

    return (ans + end - sta) / (2 * PI);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int x_0, y_0, v, T;
    cin >> x_0 >> y_0 >> v >> T;

    int N;
    cin >> N;

    vi x(N), y(N), r(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i] >> r[i];

    cout << solve(x_0, y_0, 1.0 * v * T, N, x, y, r) << endl;
    return 0;
}