#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Tree {
    ll n;
    vector <ll> t;
    Tree(ll n) : n(n), t(2 * n, 0) {}
    ll get(ll l, ll r) {
        ll res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) res += t[l++];
            if (r % 2 == 0) res += t[r--];
        }
        return res;
    }
    void change(ll v, ll x) {
        v += n;
        t[v] = x;
        v /= 2;
        while (v) {
            t[v] = t[2 * v] + t[2 * v + 1];
            v /= 2;
        }
    }
};

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
        a[i]--;
    }
    Tree t(n);
    set <pair <ll, ll> > q;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        while (q.size() && q.begin()->first < i) {
            t.change(q.begin()->second, 0);
            q.erase(q.begin());
        }
        sum += t.get(0, min(a[i], n - 1));
        q.insert({a[i], i});
        t.change(i, 1);
    }
    cout << sum;
}