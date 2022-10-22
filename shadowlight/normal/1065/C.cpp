#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;
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
    vector <ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.rbegin(), h.rend());
    ll res = 0;
    ll now = 0;
    ll sum = 0;
    for (ll i = MAXN; i >= h.back(); i--) {
        sum += now;
        //if (sum) cout << i << " " << sum << "\n";
        if (sum > k) {
            sum = now;
            res++;
        }
        while (now < n && h[now] == i) {
            now++;
        }
    }
    if (sum) {
        res++;
    }
    cout << res;
}