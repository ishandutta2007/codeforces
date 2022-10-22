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
    int n, k;
    cin >> n >> k;
    vector <int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i]) {
            sum += a[i];
        }
    }
    int now = 0, res = 0;
    for (int i = 0; i < k; i++) {
        if (!t[i]) {
            now += a[i];
        }
    }
    res = max(res, now);
    for (int i = k; i < n; i++) {
        if (!t[i - k]) {
            now -= a[i - k];
        }
        if (!t[i]) {
            now += a[i];
        }
        res = max(res, now);
    }
    cout << res + sum;
}