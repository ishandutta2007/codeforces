#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
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
    ll n, m, k;
    cin >> n >> m >> k;
    if (2 * n * m % k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector <ll> f;
    for (ll i = 2; i < MAXN; i++) {
        while (k % i == 0) {
            f.push_back(i);
            k /= i;
        }
    }
    if (k != 1) {
        f.push_back(k);
    }
    ll n1 = n, m1 = m;
    bool fl = false;
    for (ll x : f) {
        if (n % x == 0) {
            n /= x;
        } else if (m % x == 0){
            m /= x;
        } else {
            fl = true;
        }
    }
    if (!fl) {
        if (n * 2 <= n1) {
            n *= 2;
        } else {
            m *= 2;
        }
    }
    cout << "0 0\n";
    cout << "0 " << m << "\n";
    cout << n << " 0" << "\n";
}