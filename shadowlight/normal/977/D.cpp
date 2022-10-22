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
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](ll x, ll y) {
        ll st2x = 0, st2y = 0;
        ll px = 0, py = 0;
        while (x % 2 == 0) {
            st2x++;
            x /= 2;
        }
        while (y % 2 == 0) {
            st2y++;
            y /= 2;
        }
        while (x % 3 == 0) {
            px++;
            x /= 3;
        }
        while (y % 3 == 0) {
            py++;
            y /= 3;
        }
        if (st2x != st2y) {
            return st2x < st2y;
        }
        return px > py;
    });
    for (auto x : a) {
        cout << x << " ";
    }
}