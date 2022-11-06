#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define ll long long
#define ld long double
#define show(a) cerr << #a << " = " << a << '\n'

const ll oo = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll mx = 1;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                mx = max(mx, n / i);
            }
        }
        cout << mx << " " << mx * (n / mx - 1) << '\n';
    }
    return 0;
}