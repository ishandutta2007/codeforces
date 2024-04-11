#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll p;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % p;
    if (k % 2) {
        return b * a % p;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, p - 2);
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
    ll a, b, x;
    cin >> a >> b >> p >> x;
    if (p == 2) {
        cout << (x + 1) / 2;
        return 0;
    }
    ll sum = 0;
    for (ll i = 1; i <= p - 1; i++) {
        ll j = rev(power(a, i)) * b % p;
        ll k = i - j;
        if (k < 0) {
            k += p;
        }
        //cout << i + (p - 1) * k << " " << (i + (p - 1) * k) % p << " " << j << "\n";
        if (i + (p - 1) * k <= x) {
            sum += (x - (i + (p - 1) * k)) / (p * (p - 1)) + 1;
        }
    }
    cout << sum;
}