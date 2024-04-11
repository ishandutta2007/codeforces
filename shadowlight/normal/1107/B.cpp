#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const int MAXN = 207;
const double EPS = 1e-6;

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
    #endif // MYs
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll k, x;
        cin >> k >> x;
        cout << (k - 1) * 9 + x << "\n";
    }
}