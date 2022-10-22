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
    int n, d;
    cin >> n >> d;
    int l = 0, r = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            l += x;
            r += x;
            if (l > d) {
                cout << -1;
                return 0;
            }
            r = min(r, d);
        } else if (x < 0) {
            l += x;
            r += x;
        } else {
            if (r < 0) {
                cnt++;
                r = d;
            }
            if (l < 0) {
                l = 0;
            }
        }
        //cout << l << " " << r << "\n";
    }
    cout << cnt;
}