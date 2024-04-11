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
#define SZ(x)                       ll(x.size());
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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;



int main() {
//    fast_io;
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (char c = 'z'; c > 'a'; c--) {
        bool b = true;
        while (b) {
            b = false;
            if (s.size() < 2) break;
            for (string::iterator i = s.begin(); i != s.end(); i++) {
//                cout << "A" << endl;
                if (*i != c) continue;
                char prev = '5', next = '5', now = *i;
                if (i != s.begin()) prev = *(i - 1);
                if (i != s.end() - 1) next = *(i + 1);
                if (now == prev + 1 || now == next + 1) {
                    s.erase(i);
                    i--;
                    b = true;
                }
            }
        }
    }

//    cout << s << endl;

    cout << n - s.size() << endl;
    return 0;
}