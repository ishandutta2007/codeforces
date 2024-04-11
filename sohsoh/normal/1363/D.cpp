/*
    Soheil Mohammadkhani
    I will change this text here when i've got "...":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll LOG = 22;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// fuck lazy propagation :|

ll solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> tmp;
    for (int i = 0; i < k; i++) {
        ll c;
        cin >> c;
        vector<ll> v;
        for (int j = 0; j < c; j++) {
            ll t;
            cin >> t;
            v.push_back(t);
        }

        tmp.push_back(v);
    }

    ll mx;
    cout << "? " << n << sep;
    for (int i = 1; i <= n; i++) {
        cout << i << sep;
    }
    cout << endl;
    cout.flush();
    cin >> mx;

    ll L = 1, R = n;
    while (L < R) {
        ll mid = (L + R) / 2;
        cout << "? ";
        cout << mid - L + 1 << sep;
        for (ll i = L; i <= mid; i++) {
            cout << i << sep;
        }
        cout << endl;
        cout.flush();

        ll ans;
        cin >> ans;
        if (ans == mx) R = mid;
        else L = mid + 1;
    }

    vector<ll> final_ans;

    for (vector<ll> v : tmp) {
        if (find(all(v), L) == v.end()) final_ans.push_back(mx);
        else {
            cout << "? ";
            vector<ll> q;
            for (int i = 1; i <= n; i++) {
                if (find(all(v), i) == v.end()) {
                    q.push_back(i);
                }
            }

            cout << q.size() << sep;
            for (ll u : q) {
                cout << u << sep;
            }

            cout << endl;
            cout.flush();
            ll ans;
            cin >> ans;
            final_ans.push_back(ans);
        }
    }

    cout << "! ";
    for (ll v : final_ans) {
        cout << v << sep;
    } cout << endl;

    string fucking_str;
    cin >> fucking_str;

    return 0;
}

int main() {
//    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}