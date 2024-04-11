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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 2e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string build(string s1, string s2) {
    string res = "";
    while (!s1.empty()) {
        char c1 = s1.back();
        char c2 = s2.back();
        s1.pop_back();
        s2.pop_back();
        if (c1 == c2) res.push_back(c1);
        else {
            if (c1 > c2) swap(c1, c2);
            if (c1 == 'E') {
                if (c2 == 'S') res.push_back('T');
                if (c2 == 'T') res.push_back('S');
            } else res.push_back('E');
        }
    }

    reverse(all(res));

    return res;
}

int main() {
//    fast_io;
    ll n;
    cin >> n;

    ll k;
    cin >> k;

    set<string> r;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        r.insert(s);
        v.push_back(s);
    }

    ll c = 0;

    for (string s1 : v) {
        for (string s2 : v) {
            if (s1 == s2) continue;
            string s3 = build(s1, s2);
            if (r.find(s3) != r.end() && s3 != s1 && s3 != s2) c++;
        }
    }

    cout << c / 6 << endl;
    return 0;
}