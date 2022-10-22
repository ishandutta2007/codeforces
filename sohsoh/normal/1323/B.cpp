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
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
//    fast_io;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> part1;
    vector<int> part2;
    int now = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            now++;
        }
        else {
            part1.push_back(now);
            now = 0;
        }
    }

    if (now) {
        part1.push_back(now);
    }

    now = 0;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            now++;
        }
        else {
            part2.push_back(now);
            now = 0;
        }
    }

    if (now) {
        part2.push_back(now);
    }

    long long sum = 0;
    for (int x = 1; x <= n; x++) {
        if (k % x == 0) {
            int y = k / x;
            ll s = 0;
            ll s2 = 0;

            for (vector<int>::iterator it = part1.begin(); it != part1.end(); it++) {
                int x1 = *it;
                if (x1 >= x) {
                    s += x1 - x + 1;
                }
            }

            for (vector<int>::iterator it = part2.begin(); it != part2.end(); it++) {
                int x1 = *it;
                if (x1 >= y) {
                    s2 += x1 - y + 1;
                }
            };

            sum += s * s2;
        }
    }

    cout << sum << endl;
    return 0;
}