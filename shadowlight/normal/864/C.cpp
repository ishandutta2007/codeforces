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
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int cnt = 0;
    int now = b;
    if (b < f || b < a - f) {
        cout << -1;
        return 0;
    }
    if (k > 1 && b < 2 * (a - f)) {
        cout << -1;
        return 0;
    }
    if (k > 2 && b < 2 * f) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < k - 1; i++) {
        if (a + a - f > now) {
            cnt++;
            now = b - (a - f);
        } else {
            now -= a;
        }
        f = a - f;
    }
    if (a > now) {
        cnt++;
    }
    cout << cnt;
}