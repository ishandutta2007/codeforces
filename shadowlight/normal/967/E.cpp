#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 60;

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
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <ll> res;
    for (ll k = LOGN - 1; k >= 0; k--) {
        vector <ll> x, y;
        for (ll i = 0; i < n; i++) {
            if (a[i] < (1LL << k)) continue;
            if (a[i] < (1LL << (k + 1))) {
                x.push_back(a[i]);
            }
        }
        for (ll i = 0; i < (ll) res.size(); i++) {
            if (res[i] & (1LL << k)) {
                y.push_back(i);
            }
        }
        if (x.size() > y.size() + 1) {
            cout << "No\n";
            return 0;
        }
        //cout << x.size() << " " << y.size() << "\n";
        vector <ll> nres;
        ll idy = 0, now = 0;
        while (x.size() > 1) {
            nres.push_back(x.back());
            x.pop_back();
            while (now != y[idy]) {
                nres.push_back(res[now++]);
            }
            nres.push_back(res[now++]);
            idy++;
        }
        if (x.size()) {
            nres.push_back(x[0]);
        }
        while (now < res.size()) {
            nres.push_back(res[now++]);
        }
        res = nres;
    }
    cout << "Yes\n";
    for (ll x : res) {
        cout << x << " ";
    }
}