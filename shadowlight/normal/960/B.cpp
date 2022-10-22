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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int k = k1 + k2;
    vector <ll> a(n), b(n), c(n);
    multiset <ll> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        q.insert(abs(a[i] - b[i]));
    }
    for (ll i = 0; i < k; i++) {
        ll x = *q.rbegin();
        q.erase(q.find(x));
        if (!x) {
            q.insert(x + 1);
        } else {
            q.insert(x - 1);
        }
    }
    ll res = 0;
    for (ll x : q) {
        res += x * x;
    }
    cout << res;
}