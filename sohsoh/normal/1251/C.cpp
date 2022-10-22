/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN];

ll solve() {
    string s;
    cin >> s;
    ll n = s.size();
    for (int i = 0; i < n; i++) A[i] = s[i] - '0';
    deque<ll> E, O;
    for (int i = 0; i < n; i++) {
        if (A[i] & 1) O.push_back(A[i]);
        else E.push_back(A[i]);
    }

    vector<ll> ans;
    while (!E.empty() || !O.empty()) {
        if (!E.empty() && (O.empty() || E.front() < O.front())) {
            ans.push_back(E.front());
            E.pop_front();
        } else {
            ans.push_back(O.front());
            O.pop_front();
        }
    }

    for (ll e : ans) cout << e;
    cout << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}