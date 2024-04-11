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
    int n, l;
    cin >> n >> l;
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    ll res = 0;
    ll ans = INF;
    for (int i = n - 1; i >= 0; i--) {
        while (l >= (1 << i)) {
            l -= (1 << i);
            res += c[i];
        }
        if (l) {
            ans = min(res + c[i], ans);
        } else {
            ans = min(ans, res);
        }
    }
    cout << ans;
}