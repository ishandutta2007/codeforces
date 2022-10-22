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
    ll b;
    cin >> b;
    ll d = 0;
    for (ll i = 1; i <= sqrtl(b); i++) {
        if (b % i == 0) {
            d += 2;
        }
    }
    ll k = sqrtl(b);
    if (k * k == b) {
        d--;
    }
    cout << d;
}