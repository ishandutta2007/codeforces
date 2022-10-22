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
    multiset <ll> q;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        q.insert(x);
    }
    ll res = 0;
    if (q.size() % 2 == 0) {
        ll sum = 0;
        for (ll i = 0; i < 2; i++) {
            sum += *q.begin();
            q.erase(q.begin());
        }
        res += sum;
        q.insert(sum);
    }
    while (q.size() >= 3) {
        ll sum = 0;
        for (ll i = 0; i < 3; i++) {
            sum += *q.begin();
            q.erase(q.begin());
        }
        res += sum;
        q.insert(sum);
    }
    cout << res;
}