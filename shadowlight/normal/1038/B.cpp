#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll dig(ll x) {
    for (ll i = 2; i <= min(MAXN, x - 1); i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return -1;
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
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        sum += i;
    }
    //cout << sum << "\n";
    ll d = dig(sum);
    if (d == -1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    vector <ll> a, b;
    for (ll i = n; i > 0; i--) {
        if (d >= i) {
            d -= i;
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    cout << a.size() << " ";
    for (ll x : a) {
        cout << x << " " ;
    }
    cout << "\n";
    cout << b.size() << " ";
    for (ll x : b) {
        cout << x << " ";
    }
    cout << "\n";
}