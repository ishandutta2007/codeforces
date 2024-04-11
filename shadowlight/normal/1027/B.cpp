#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define TASKNAME ""

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        ll cnt = 0;
        if ((x + y) % 2) {
            cnt += (n * n + 1) / 2;
            cnt += ((x - 1) * n) / 2;
            if (x % 2 == 0) {
                cnt += (y + 1) / 2;
            } else {
                cnt += y / 2;
            }
        } else {
            cnt += ((x - 1) * n + 1) / 2;
            if (x % 2 == 0) {
                cnt += y / 2;
            } else {
                cnt += (y + 1) / 2;
            }
        }
        cout << cnt << "\n";
    }

}