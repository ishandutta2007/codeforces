#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;

void solve(ll x) {
    for (ll n = 1; n <= MAXN; n++) {
        if (n * n < x) continue;
        ll k = n * n - x;
        if (!k) continue;
        ll b = sqrt(k);
        if (b * b != k) {
            continue;
        }
        ll m = n / b;
        if (n / m != b) {
            continue;
        }
        cout << n << " " << m << "\n";
        return;
    }
    cout << -1 << "\n";
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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll x;
        cin >> x;
        solve(x);
    }
}