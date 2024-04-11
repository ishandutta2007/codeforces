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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = INF;
    int tm = -1;
    for (int t = 1; t <= 100; t++) {
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > t) {
                now += a[i] - t - 1;
            } else if (a[i] < t) {
                now += t - 1 - a[i];
            }
        }
        if (res > now) {
            res = now;
            tm = t;
        }
    }
    cout << tm << " " << res;
}