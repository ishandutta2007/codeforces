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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string check(string s, string c) {
    if (lexicographical_compare(all(s), all(c))) {
        return s;
    }

    return "---";
}

ll solve() {
    string s, c;
    cin >> s >> c;
    string s2 = s, s3 = s;
    Sort(s2);

    string ans = "";
    while (!s2.empty() && s3.front() == s2.front()) {
        ans.push_back(s3.front());
        s3.erase(s3.begin());
        s2.erase(s2.begin());
    }

    if (s2.empty()) return cout << check(ans, c) << endl, 0;
    auto it = s3.begin();
    for (auto i = s3.begin(); i != s3.end(); i++) {
        if (*it >= *i) it = i;
    }
    swap(*s3.begin(), *it);
    ans += s3;
    return cout << check(ans, c) << endl, 0;
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