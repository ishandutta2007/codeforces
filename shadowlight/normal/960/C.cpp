#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

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
    ll x, d;
    cin >> x >> d;
    ll now = 1;
    vector <ll> a;
    for (ll i = LOGN; i >= 1; i--) {
        ll st = (1 << i) - 1;
        while (x >= st) {
            for (ll j = 0; j < i; j++) {
                a.push_back(now);
            }
            now += d;
            x -= st;
        }
    }
    cout << a.size() << "\n";
    for (ll x : a) {
        cout << x << " ";
    }
}