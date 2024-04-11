#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
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
    ll maxk = -1, pos = -1, xp = -1;
    for (ll i = 0; i < k; i++) {
        ll x;
        cin >> x;
        ll a = n / x * x;
        if (a > maxk) {
            maxk = a;
            pos = i;
            xp = x;
        }
    }
    cout << pos + 1 << " " << n / xp;
}