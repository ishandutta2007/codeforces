#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e7 + 7;
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
    ll n, m;
    cin >> n >> m;
    ll s;
    ll t;
    cin >> s >> t;
    ll od = t % n;
    s--;
    unordered_map <ll, ll> was(4 * MAXN);
    ll now = 1;
    while (t > 0) {
        if (was[(s << 20) + od]) break;
        was[(s << 20) + od] = now++;
        if (s < m) {
            s += od;
            if (s >= n) {
                s -= n;
            }
        } else {
            s -= od;
            if (s < 0) {
                s += n;
            }
        }
        if (!od) {
            od = n - 1;
        } else {
            od--;
        }
        t--;
    }
    if (!t) {
        cout << s + 1 << "\n";
        return 0;
    }
    ll cycle = now - was[(s << 20) + od];
    t %= cycle;
    od = t % n;
    while (t > 0) {
        if (s < m) {
            s += od;
            if (s >= n) {
                s -= n;
            }
        } else {
            s -= od;
            if (s < 0) {
                s += n;
            }
        }
        if (!od) {
            od = n - 1;
        } else {
            od--;
        }
        t--;
    }
    cout << s + 1;
}