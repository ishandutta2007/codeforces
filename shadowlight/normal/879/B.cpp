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
    ll n, k;
    cin >> n >> k;
    ll maxk = -1;
    queue <ll> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        q.push(x);
        maxk = max(maxk, x);
    }
    ll now = q.front();
    q.pop();
    ll cnt = 0;
    while (now != maxk) {
        ll v = q.front();
        q.pop();
        if (v > now) {
            q.push(now);
            now = v;
            cnt = 1;
        } else {
            q.push(v);
            cnt++;
            if (cnt == k) {
                cout << now << "\n";
                return 0;
            }
        }
    }
    cout << maxk << "\n";
}