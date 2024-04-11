#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    double AX, AY, BX, BY, TX, TY;
    cin >> AX >> AY >> BX >> BY >> TX >> TY;

    int N;
    cin >> N;

    vector<double> af(N), bf(N), oth(N);
    vector<pair<double, int>> as(N), bs(N);

    double tot_oth = 0;

    for (int i = 0; i < N; i++) {
        int xx, yy;
        cin >> xx >> yy;

        double recyc = dist(TX, TY, xx, yy);

        af[i] = dist(AX, AY, xx, yy) + recyc;
        bf[i] = dist(BX, BY, xx, yy) + recyc;
        oth[i] = 2 * recyc;

        as[i] = { oth[i] - af[i], i };
        bs[i] = { oth[i] - bf[i], i };

        tot_oth += oth[i];
    }

    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    reverse(bs.begin(), bs.end());

    double ans = min(tot_oth - as[0].first, tot_oth - bs[0].first);

    if (as[0].second != bs[0].second) {
        ans = min(ans, tot_oth - as[0].first - bs[0].first);
    } else if (N > 1) {
        ans = min(ans, tot_oth - as[0].first - bs[1].first);
        ans = min(ans, tot_oth - as[1].first - bs[0].first);
    }

    cout << ans << "\n";
    return 0;
}