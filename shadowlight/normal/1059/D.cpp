#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e14 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <pair <double, double> > a;

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
    cin >> n;
    a.resize(n);
    bool fl1 = false, fl2 = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].second > 0) {
            fl1 = true;
        }
        if (a[i].second < 0) {
            fl2 = true;
        }
    }
    if (fl1 && fl2) {
        cout << -1;
        return 0;
    }
    double l = 0, r = INF;
    for (int t = 0; t < 100; t++) {
        double mid = (l + r) / 2;
        bool can = true;
        double lt = -INF, rt = INF;
        for (int i = 0; i < n; i++) {
            double x = 2 * mid / 10000.0;
            x *= abs(a[i].second);
            x -= a[i].second * a[i].second / 10000.0;
            if (x < 0) {
                can = false;
                break;
            }
            lt = max(lt, a[i].first - sqrt(x) * 100.0);
            rt = min(rt, a[i].first + sqrt(x) * 100.0);
        }
        if (!can || rt < lt) {
            l = mid;
            continue;
        } else {
            r = mid;
        }
    }
    cout.precision(30);
    cout << l;
}