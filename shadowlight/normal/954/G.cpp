#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 2e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, r, k;

vector <ll> a;

bool can(ll x) {
    ll ost = k;
    queue <pair <ll, ll> > q;
    ll sum = 0;
    for (ll i = 0; i < r; i++) {
        sum += a[n - i - 1];
        q.push({a[n - i - 1], n - i - 1});
    }
    for (ll i = n - 1; i >= 0; i--) {
        while (q.size() && q.front().second > i + r) {
            sum -= q.front().first;
            q.pop();
        }
        if (i - r >= 0) {
            sum += a[i - r];
            q.push({a[i - r], i - r});
        }
        if (sum < x) {
            if (ost < x - sum) {
                return false;
            }
            ost -= x - sum;
            q.back().first += x - sum;
            sum = x;
        }
    }
    return true;
}

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
    cin >> n >> r >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (can(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
}