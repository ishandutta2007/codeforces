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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s, t;
    cin >> s >> t;
    int k = t - s;
    int maxk = -1, cnt = 0;
    int tm = -1;
    for (int i = 0; i < k; i++) {
        cnt += a[i];
    }
    maxk = cnt;
    tm = s;
    for (int i = 1; i < n; i++) {
        cnt -= a[i - 1];
        cnt += a[(i + k - 1) % n];
        //cout << cnt << "\n";
        if (cnt > maxk) {
            maxk = cnt;
            tm = s - i + n;
            if (tm > n) {
                tm -= n;
            }
        } else if (cnt == maxk) {
            int tm1 = s - i + n;
            if (tm1 > n) {
                tm1 -= n;
            }
            tm = min(tm, tm1);
        }
    }
    cout << tm;
}