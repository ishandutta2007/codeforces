#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e3 + 7;
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
    if (k > MAXN) {
        cout << "No\n";
        return 0;
    }
    for (ll i = 1; i <= k; i++) {
        if (n % i != i - 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}