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
typedef pair<ll, string> pls;

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

string to_str(ll n) {
    string s = "";
    while (n > 0) {
        s.push_back((n % 10) + '0');
        n /= 10;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {
    fast_io;
    ll n, m, k;
    cin >> n >> m >> k;

    if (k > 4 * n * m - 2 * m - 2 * n) return cout << "NO" << endl, 0;
    cout << "YES" << endl;

    ll c = 2 * n + 1;
    queue<pls> q;
    q.push(make_pair(m - 1, "R"));
    q.push(make_pair(m - 1, "L"));
    q.push(make_pair(1, "D"));

    ll mv = 0;
    ll row = 1;
    while (row < n) {
        mv = (mv + 1) % 3;
        if (mv == 0) {
            q.push(make_pair(1, "D"));
            c++;
        } else if (mv == 1) {
            q.push(make_pair(m - 1, "R"));
            c += n;
        } else {
            q.push(make_pair(m - 1, "UDL"));
            c += 3 * n;
            row++;
        }
    }

    q.push(make_pair(n - 1, "U"));

    queue<string> res;
    while (!q.empty() && k > 0) {
        ll ch = q.front().first * q.front().second.size();
        if (q.front().first > 0) {
            if (ch <= k) {
                k -= ch;
//                debug(q.front().first)
                res.push(to_str(q.front().first) + " " + q.front().second);
            } else {
                ll fn = k / q.front().second.size();
                ll rem = k % q.front().second.size();
                if (fn > 0) {
                    res.push(to_str(fn) + " " + q.front().second);
                }

                if (rem > 0) {
                    string r = "";
                    for (int i = 0; i < rem; i++) {
                        r.push_back(q.front().second[i]);
                    }

                    res.push("1 " + r);
                }

                break;
            }
        }


        q.pop();
    }

    cout << res.size() << endl;

    while (!res.empty()) {
        cout << res.front() << endl;
        res.pop();
    }

    return 0;
}