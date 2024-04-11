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
    fast_io;
//    cout << endl;
    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        string ss;
        cin >> ss;

        int* s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = ss[i] - 'a';
        }

        int* res = new int[n];
        int* best = new int[n];
        for (int i = 0; i < n; i++) {
            best[i] = s[i];
        }
        int m = 1;
        for (int k = 1; k <= n; k++) {
            int ma = k - 1;

            int last = 0;
            for (int i = ma; i < n; i++) {
                res[i - ma] = s[i];
                last = i - ma;
            }

            last++;

            for (int i = 0; i < ma; i++) {
                if (n % 2 == k % 2) {
                    res[last] = s[ma - i - 1];
                } else {
                    res[last] = s[i];
                }
                last++;
            }

            if (lexicographical_compare(res, res + n, best, best + n)) {
                m = k;
                for (int i = 0; i < n; i++) {
                    best[i] = res[i];
                }
            }
        }

        for (int i = 0; i < n; i++) cout << char(best[i] + 'a');
        cout << endl << m << endl;
    }
    return 0;
}