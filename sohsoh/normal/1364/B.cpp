/*
    Soheil Mohammadkhani
    Maybe candidate after this contest :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
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

const ll MAXN = 1e6 + 10; //Change me please :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0}, n;

ll solve() {
    vector<ll> ans;
    bool prev = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (ans.size() == 0) ans.push_back(A[i]);
        if (i == 1) {
            ans.push_back(A[i]);
            prev = A[1] > A[0];
        }

        if (i > 1) {
            ll p = ans.back();
            if (prev) {
                if (A[i] > p) {
                    ans.pop_back();
                    ans.push_back(A[i]);
                } else {
                    prev = false;
                    ans.push_back(A[i]);
                }
            } else {
                if (A[i] < p) {
                    ans.pop_back();
                    ans.push_back(A[i]);
                } else {
                    prev = true;
                    ans.push_back(A[i]);
                }
            }
        }
    }

    cout << SZ(ans) << endl;
    for (ll e : ans) {
        cout << e << sep;
    }

    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}