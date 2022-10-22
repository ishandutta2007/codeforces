/*
    Soheil Mohammadkhani
    Loading Text ... please wait
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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

//KeepCalm and just code until the contest :|

ll solve() {
    bool used[10] = {false};
    string s[10];
    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        used[s[i].back() - '0'] = true;
    }

    ll x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                for (int k = 0; k < 10; k++) {
                    if (!used[k]) {
                        used[k] = true;
                        s[i].pop_back();
                        s[i].push_back(char(k + '0'));
                        x++;
                        break;
                    }
                }
            }
        }
    }

    cout << x << endl;
    for (int i = 0; i < n; i++) cout << s[i] << endl;
}
int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}