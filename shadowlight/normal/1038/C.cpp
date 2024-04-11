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
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll d = 0;
    bool num = false;
    for (ll i = 0; i < 2 * n; num ^= 1, i++) {
        if (!a.size()) {
            d += (num ? -b.back() : 0);
            b.pop_back();
            continue;
        }
        if (!b.size()) {
            d += (num ? 0 : a.back());
            a.pop_back();
            continue;
        }
        if (a.back() > b.back()) {
            d += (num ? 0 : a.back());
            a.pop_back();
        } else {
            d += (num ? -b.back() : 0);
            b.pop_back();
        }
    }
    cout << d;
}