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
    ll p, k;
    cin >> p >> k;
    vector <ll> a;
    bool fl = 0;
    while (p) {
        if (p % k && fl) {
            p += k;
            a.push_back(k - p % k);
        } else {
            a.push_back(p % k);
        }
        p /= k;
        fl ^= 1;
    }
    cout << a.size() << "\n";
    for (ll x : a) {
        cout << x << " ";
    }
}