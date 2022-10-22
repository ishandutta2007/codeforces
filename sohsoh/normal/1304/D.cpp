/*
    Soheil Mohammadkhani
    import covid
    cov = new covid();
    cov.kill(Me)

    -- undefined variable Me ;)
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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 2; i <= n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

void l_solve(string s) {
    reverse(all(s));
    ll n = SZ(s) + 1;
    ll* res = new ll[n];
    int i = 0;
    ll h = n, l = 1;
    for (char c : s) {
        if (c == '<') {
            res[i] = h;
            h--;
        } else {
            res[i] = l;
            l++;
        }

        i++;
    }

    res[SZ(s)] = l;
    reverse(res, res + n);
    FOR(n) cout << res[i] << sep;
    cout << endl;
}

void s_solve(string s) {
    ll n = SZ(s) + 1;
    bool* oop = new bool[SZ(s)];
    int i = 0;
    for (char c : s) {
        oop[i] = false;
        if (c == '<') {
            oop[i] = true;
        }

        i++;
    }
    i = 0; // SOME PRESET

    ll* res = new ll[n];
    for (i = 0; i < n; i++) res[i] = n - i;

    ll f = -1, t = -1;
    for (i = 0; i < n - 1; i++) {
        if (oop[i] && f == -1) { f = i; t = i; }
        else if (oop[i]) t = i;
        else {
            if (f != -1) {;
                reverse(res + f, res + t + 2);
                f = -1;
                t = -1;
            }
        }
    }


    if (f != -1) {;
        reverse(res + f, res + t + 2);
        f = -1;
        t = -1;
    }


    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;

}

ll solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s_solve(s);
    l_solve(s);
    return 0;
}

int main() {
//    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}