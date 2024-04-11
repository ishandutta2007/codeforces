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
    vector <ll> last(n, -1);
    vector <ll> a(n, 0);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        last[i - x] = i;
    }
    vector <ll> exist(n, 0);
    ll pos = 0;
    for (ll i = 0; i < n; i++) {
        if (last[i] >= pos) {
            while (pos <= last[i]) {
                exist[pos] = 1;
                pos++;
            }
            pos++;
        } else {
            pos++;
        }
    }
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        cnt += exist[i];
        sum += cnt - a[i] - 1;
    }
    cout << sum;
}