#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 2e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 32;

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
    ll l, r;
    cin >> l >> r;
    ll cnt = 0;
    for (ll i = 0; i < LOGN; i++) {
        ll now = (1LL << i);
        for (ll j = 0; j < LOGN; j++) {
            if (now > INF) break;
            if (now >= l && now <= r) {
                cnt++;
            }
            now = now * 3;
        }
    }
    cout << cnt;
}