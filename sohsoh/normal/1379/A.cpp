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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt(string s) {
    ll c = 0;
    for (int i = 0; i < s.size() - 6; i++) if (s.substr(i, 7) == "abacaba") c++;
    return c;
}

ll solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string ps = s;
    ll c = 0;
    for (int i = 0; i < n - 6; i++) if (s.substr(i, 7) == "abacaba") c++;
    if (c == 1) {
        for (int i = 0; i < n; i++) if (s[i] == '?') s[i] = 'z';
        cout << "Yes" << endl;
        cout << s << endl;
    } else if (c == 0) {
        for (int i = 0; i < n - 6; i++) {
            string ss = s.substr(i, 7);
            string sss = "abacaba";
            bool ok = true;
            for (int j = 0; j < 7; j++) if (ss[j] != '?' && ss[j] != sss[j]) ok = false;
            if (!ok) continue;
            for (int j = 0; j < 7; j++) s[i + j] = sss[j];
            for (int i = 0; i < n; i++) if (s[i] == '?') s[i] = 'z';
            if (cnt(s) != 1) {
                s = ps;
                continue;
            }

            cout << "Yes" << endl;
            cout << s << endl;
            return 0;
        }

        cout << "No" << endl;
        return 0;
    } else {
        cout << "No" << endl;
    }
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