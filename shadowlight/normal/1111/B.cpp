#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
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
    ll n, k, m;
    cin >> n >> k >> m;
    vector <ll> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    double res = 0;
    for (ll i = 0; i <= min(n, m); i++) {
       res = max(res, (double) (sum + max(min(m - i, k * (n - i)), 0LL)) / (n - i));
       sum -= a[i];
    }
    cout.precision(20);
    cout << res;
}