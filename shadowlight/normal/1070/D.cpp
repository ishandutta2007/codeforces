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
    ll last = 0,res = 0;
    for (int i = 0; i < n; i++) {
        ll xn;
        cin >> xn;
        ll x = last + xn;
        res += x / k;
        if (x % k - xn > 0) {
            res++;
            x = 0;
        }
        last = x % k;
    }
    if (last) {
        res += (last - 1) / k + 1;
    }
    cout << res;
}