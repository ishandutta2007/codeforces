/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
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

const ll MAXN = 1e2 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string a[MAXN];
ll n, m;

bool check(string s) {
    for (int i = 0; i < n; i++) {
        ll y = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != s[j]) y++;
        }

        if (y > 1) return false;
    }

    return true;
}

ll solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) {
        vector<ll> tmp[26];
        for (int i = 0; i < n; i++) tmp[a[i][j] - 'a'].push_back(i);

        vector<string> seed;
        for (int i = 0; i < 26; i++) {
            if (tmp[i].size() > 0) {
                seed.push_back(a[tmp[i].front()]);
            }
        }

        if (seed.size() == 1) continue;
        for (int i = 0; i < seed.size(); i++) {
            int t = i + 1;
            if (t == seed.size()) t = 0;

            string ans = seed[t];
            ans[j] = seed[i][j];
            if (check(ans)) return cout << ans << endl, 0;
        }

        return cout << -1 << endl, 0;
    }

    cout << a[0] << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}