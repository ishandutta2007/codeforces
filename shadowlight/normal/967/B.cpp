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
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> s(n - 1);
    ll sum = 0;
    ll st;
    cin >> st;
    sum += st;
    for (ll i = 0; i < n - 1; i++) {
        cin >> s[i];
        sum += s[i];
    }
    sort(s.rbegin(), s.rend());
    for (ll cnt = 0; cnt < n; cnt++) {
        if (sum * b <= a * st) {
            cout << cnt;
            return 0;
        }
        sum -= s[cnt];
    }
}