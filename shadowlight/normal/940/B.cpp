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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll res = 0;
    if (k > 1) {
        while (n >= k) {
            ll x = n / k;
            res += min(a * (n % k) + b, a * (n - x));
            n = x;
        }
    }
    cout << res + (n - 1) * a;
}