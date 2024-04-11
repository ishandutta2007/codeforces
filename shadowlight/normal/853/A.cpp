#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, k;
    cin >> n >> k;
    vector <pair <ll, ll> > a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    set <ll> q;
    for (ll i = 0; i < n; i++) {
        q.insert(i + 1 + k);
    }
    vector <ll> ans(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++){
        ll x = a[i].second;
        ll p = *q.lower_bound(x);
        q.erase(p);
        sum += (p - x) * a[i].first;
        ans[a[i].second - 1] = p;
    }
    cout << sum << "\n";
    for (ll i : ans) {
        cout << i << " ";
    }
}