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
    ll n, m, k;
    cin >> n >> m >> k;
    k++;
    if (k <= n) {
        cout << k << " " << 1 << "\n";
        return 0;
    }
    k -= n;
    ll x = (k - 1) / (m - 1);
    cout << n - x << " ";
    ll d = (k - 1) % (m - 1);
    if (x % 2 == 0) {
        cout << d + 2 << "\n";
    } else {
        cout << m - d << "\n";
    }
}