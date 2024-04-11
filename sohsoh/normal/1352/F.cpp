/*
    Soheil Mohammadkhani
    IDK :)
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
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

//CHANGE IT
const ll MAXN = 8000 + 5;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char rev(char c) {
    if (c == '1') return '0';
    return '1';
}

ll solve() {
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n2 == 0 && n3 == 0) {
        for (int i = 0; i < n1 + 1; i++) {
            cout << 0;
        }
        cout << endl;

        return 0;
    }

    if (n1 == 0 && n2 == 0) {
        for (int i = 0; i < n3 + 1; i++) {
            cout << 1;
        }
        cout << endl;

        return 0;
    }

    string s;
    for (int i = 0; i < n1 + 1; i++) {
        s.push_back('0');
    }

    for (int i = 0; i < n3 + 1; i++) {
        s.push_back('1');
    }

    n2--;
    while (n2 > 0) {
        s.push_back(rev(s.back()));
        n2--;
    }

    cout << s << endl;


    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}