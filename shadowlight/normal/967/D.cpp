#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n;

vector <pair <ll, ll> > a;

void check(ll x1, ll x2, bool swapped) {
    vector <ll> t(n, 0);
    vector <ll> pref(n, -INF);
    for (ll i = 0; i < n; i++) {
        ll k = (x2 - 1) / a[i].first + 1;
        t[i] = n - i - k;
        pref[i] = (i ? max(pref[i - 1], t[i]) : t[i]);
    }
    for (ll i = n - 1; i > 0; i--) {
        ll k = (x1 - 1) / a[i].first + 1;
        if (n - i - k < 0) continue;
        if (pref[i - 1] - k < 0) continue;
        vector <ll> resa, resb;
        cout << "Yes\n";
        for (ll j = n - 1; j > n - 1 - k; j--) {
            resa.push_back(a[j].second);
        }
        for (ll j = n - 1 - k; j >= 0; j--) {
            resb.push_back(a[j].second);
            ll cnt = resb.size();
            if (cnt * a[j].first >= x2) break;
        }
         if (swapped) {
            swap(resa, resb);
        }
        cout << resa.size() << " " << resb.size() << "\n";
        for (int x : resa) {
            cout << x + 1 << " ";
        }
        cout << "\n";
        for (int x : resb) {
            cout << x + 1 << " ";
        }
        cout << "\n";
        exit(0);
    }
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
    ll x1, x2;
    cin >> n >> x1 >> x2;
    bool swapped = false;
    a.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    check(x1, x2, 0);
    check(x2, x1, 1);
    cout << "No\n";
}