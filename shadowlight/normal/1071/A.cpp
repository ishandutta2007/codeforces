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
    ll a, b;
    cin >> a >> b;
    ll s = 0;
    ll now = 1;
    while (s + now <= a + b) {
        s += now;
        now++;
    }
    now--;
    ll cnt = 0;
    vector <ll> p(now + 1, 1);
    for (ll i = now; i > 0; i--) {
        if (a >= i) {
            cnt++;
            p[i] = 0;
            a -= i;
        }
    }
    cout << cnt << "\n";
    for (ll i = 1; i <= now; i++) {
        if (!p[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << now - cnt << "\n";
    for (ll i = 1; i <= now; i++) {
        if (p[i]) {
            cout << i << " ";
        }
    }
}