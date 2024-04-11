/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
    Editorial Solution :|
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

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll C[26], C2[26];

ll count_inv(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        for (int j = i + 1; j < s.size(); j++) {
            if (c > s[j]) ans++;
        }
    }

    return ans;
}

ll solve() {
    fill(C, C + 26, 0);
    fill(C2, C2 + 26, 0);
    ll n;
    string s, t;
    cin >> n >> s >> t;

    for (char c : s) C[c - 'a']++;
    for (char c : t) C2[c - 'a']++;
    for (int i = 0; i < 26; i++) if (C[i] != C2[i]) return cout << "NO" << endl, 0;
    for (int i = 0; i < 26; i++) if (C[i] > 1) return cout << "YES" << endl, 0;

    ll inv1 = count_inv(s), inv2 = count_inv(t);

    if (inv1 % 2 == inv2 % 2) return cout << "YES" << endl, 0;
    cout << "NO" << endl;

    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}