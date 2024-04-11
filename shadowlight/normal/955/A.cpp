#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int h, m;
    cin >> h >> m;
    m += 60 * h;
    int d, c, n;
    cout.precision(20);
    cin >> h >> d >> c >> n;
    if (m >= 60 * 20) {
        double res = 0.8 * c * (((h - 1)  / n) + 1);
        cout << res << "\n";
        return 0;
    }
    int tm = 60 * 20 - m;
    double res = c * ((h - 1) / n + 1);
    res = min(res, 0.8 * c * ((h + tm * d - 1) / n + 1));
    cout << res;
}