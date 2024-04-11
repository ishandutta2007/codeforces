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

const ll MAXN = 131072 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve(string s, char c) {
    if (s.size() == 1) return int(s[0] != c);
    string p1 = "", p2 = "";
    ll p1c = 0, p2c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() / 2) {
            p1.push_back(s[i]);
            if (s[i] == c) p1c++;
        } else {
            p2.push_back(s[i]);
            if (s[i] == c) p2c++;
        }
    }

    c++;
    return min(p1.size() - p1c + solve(p2, c), p2.size() - p2c + solve(p1, c));
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, 'a') << endl;
    }
    return 0;
}