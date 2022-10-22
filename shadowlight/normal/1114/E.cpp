#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int main() {
    mt19937 gen(1488);
    ll n;
    cin >> n;
    ll l = -1, r = INF;
    ll cnt = 0;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        cout << "> " << mid << endl;
        cnt++;
        ll x;
        cin >> x;
        if (x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ll maxk = r;
    ll g = 0;
    vector <ll> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), gen);
    for (ll i = cnt; i < min(60LL, n + cnt); i++) {
        cout << "? " << p[i - cnt] + 1 << endl;
        ll val;
        cin >> val;
        g = __gcd(g, maxk - val);
      //  cout << g << "\n";
    }
    cout << "! " << maxk - (n - 1) * g << " " << g << endl;
}