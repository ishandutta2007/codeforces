#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int LOGN = 64;
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
    ll n, k;
    cin >> n >> k;
    map <ll, ll> all;
    ll pos = 0;
    ll cnt = 0;
    while (n) {
        if (n % 2) {
            all[pos] = 1;
            cnt++;
        }
        pos++;
        n /= 2;
    }
    if (all.size() > k) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = LOGN - 1; i >= -LOGN; i--) {
        if (cnt + all[i] > k) break;
        cnt += all[i];
        all[i - 1] += 2 * all[i];
        all[i] = 0;
    }
    int d = all.begin()->first;
    while (cnt < k) {
        cnt++;
        all[d]--;
        d--;
        all[d] += 2;
    }
    for (auto it = all.rbegin(); it != all.rend(); it++) {
        auto p = *it;
        for (ll x = 0; x < p.second; x++) {
            cout << p.first << " ";
        }
    }
    cout << "\n";
}