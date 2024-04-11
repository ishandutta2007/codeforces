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

string s, s2, res;
stack<char> t;
ll cnt[26] = {0};

char best() {
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) return i + 'a';
    }

    return ';';
}

int main() {
    fast_io;
    cin >> s;

    s2 = s;
    Sort(s2);

    for (char c : s2) cnt[c - 'a']++;
    while (!s.empty()) {
        char c = best();
        while (!s.empty() && (t.empty() || t.top() > c)) {
            t.push(s.front());
            cnt[s.front() - 'a']--;
            s.erase(s.begin());
        }

        while (!t.empty() && (s.empty() || t.top() <= c)) {
            res.push_back(t.top());
            t.pop();
        }
    }

    cout << res << endl;
    return 0;
}