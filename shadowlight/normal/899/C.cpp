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
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    ll need = sum / 2;
    ll res = 0;
    cout << sum % 2 << "\n";
    vector <ll> ans;
    for (ll x = n; x >= 1; x--) {
        if (x + res >= need) {
            ans.push_back(need - res);
            break;
        }
        res += x;
        ans.push_back(x);
    }
    cout << ans.size() << " ";
    for (ll x : ans) {
        cout << x << " ";
    }
}