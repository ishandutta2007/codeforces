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

ll solve() {
    string s, suff = "", ans = "";
    ll n;
    cin >> n;
    cin >> s;
    ll start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') break;
        start++;
        cout << '0';
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            suff.push_back('1');
            s.pop_back();
        }
        else break;
    }

    ll f = -2;
    for (int i = start; i < s.size(); i++) {
        cout << '0';
        break;
    }

    cout << ans << suff << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}