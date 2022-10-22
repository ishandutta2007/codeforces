/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master"(it's going up every day xD ) :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> ans;
ll n, m, d;

int main() {
    fast_io
    cin >> n >> m >> d;
    ll pos = 1;
    for (int k = 1; k <= m; k++) {
        ll x;
        cin >> x;
        for (int i = 1; i < d; i++) ans.push_back(0);
        for (int i = pos + d; i < pos + d + x; i++) ans.push_back(k);
        for (auto it = ans.begin(); it != ans.end() && ans.size() > n; it++) {
            if (*it == 0) {
                ans.erase(it);
                it--;
            }
        }
    }

    ll check = 0;
    while (ans.size() < n) {
        check++;
        ans.push_back(0);
    }

    if (check >= d) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    return 0;
}