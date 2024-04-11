#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
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
    int n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll res = INF;
    for (int i = 0; i < n; i++) {
        ll now = -INF;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (i != j) {
                    now = max(now, a[j] * b[k]);
                }
            }
        }
        if (now < res) {
            res = now;
        }
    }
    cout << res;
}