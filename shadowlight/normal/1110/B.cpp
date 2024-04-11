#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    ll n, m, k;
    cin >> n >> m >> k;
    ll pr;
    cin >> pr;
    vector <ll> a;
    ll sum = n;
    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x - pr - 1);
        pr = x;
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n - k; i++) {
        sum += a[i];
    }
    cout << sum;
}