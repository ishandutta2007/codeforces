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
    ll n, t;
    cin >> n >> t;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <ll> p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    auto sp = p;
    sort(sp.begin(), sp.end());
    if (sp != p) {
        cout << "No\n";
        return 0;
    }
    vector <ll> b(n, 0);
    ll last = 0;
    for (ll i = 1; i < n; i++) {
        if (p[i] < i) {
            cout << "No\n";
            return 0;
        }
        if (p[i] != p[i - 1]) {
            if (p[i - 1] != i - 1) {
                cout << "No\n";
                return 0;
            }
            for (ll j = last + 1; j < i; j++) {
                b[j - 1] = a[j] + t;
            }
            if (last == i - 1) {
                b[i - 1] = a[i - 1] + t;
            } else {
                b[i - 1] = b[i - 2] + 1;
            }
            if (b[i - 1] >= a[i] + t) {
                cout << "No\n";
                return 0;
            }
            last = i;
        }
    }
    b[last] = a[n - 1] + t;
    for (ll j = last + 1; j < n; j++) {
        b[j] = b[j - 1] + 1;
    }
//    for (ll i = 1; i < b.size(); i++) {
//        if (b[i] <= b[i - 1]) {
//            cout << "No\n";
//            return 0;
//        }
//    }
    cout << "Yes\n";
    for (ll x : b) {
        cout << x << " ";
    }
}