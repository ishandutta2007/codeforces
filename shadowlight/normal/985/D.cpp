#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 2e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, h;

ll calc(ll cnt) {
    if (cnt <= h) {
        return cnt * (cnt + 1) / 2;
    }
    ll res = h * (h + 1) / 2 + h;
    cnt -= h + 1;
    if (cnt % 2) {
        res += h + cnt / 2 + 1;
    }
    if (res >= n) {
        return res;
    }
    cnt /= 2;
    res += 2 * cnt * h + cnt * (cnt + 1);
    return res;
}

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
    cin >> n >> h;
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (calc(mid) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
}