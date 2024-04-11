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
    ll n, k, l;
    cin >> n >> k >> l;
    ll m = n * k;
    vector <ll> a(m);
    for (ll i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sum = 0;
    sum += a[0];
    while (a.back() > a[0] + l) {
        a.pop_back();
    }
    if (a.size() < n) {
        cout << 0;
        return 0;
    }
    ll now = k;
    vector <ll> used(a.size(), 0);
    used[0] = 1;
    ll cnt = 1;
    while (now < a.size()) {
        sum += a[now];
        used[now] = 1;
        now += k;
        cnt++;
    }
    now = a.size() - 1;
    while (cnt < n) {
        if (!used[now]) {
            cnt++;
            sum += a[now];
            used[now] = 1;
        }
        now--;
    }
    cout << sum;
}