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

int a[501][501];

int last_fill = 0;

void fill_next(int n) {
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            last_fill++;
            a[n - 1][i] = last_fill;
        }

        for (int i = n - 2; i >= 0; i--) {
            last_fill++;
            a[i][n - 1] = last_fill;
        }
    } else {
        for (int i = 0; i < n; i++) {
            last_fill++;
            a[i][n - 1] = last_fill;
        }

        for (int i = n - 2; i >= 0; i--) {
            last_fill++;
            a[n - 1][i] = last_fill;
        }
    }
}


ll n;
int main() {
    fast_io;
    cin >> n;

    if (n < 3) return cout << -1 << endl, 0;

    ll base_start = n * n - 3 * 3;

    a[0][0] = base_start + 7;
    a[0][1] = base_start + 8;
    a[0][2] = base_start + 1;
    a[1][0] = base_start + 6;
    a[1][1] = base_start + 4;
    a[1][2] = base_start + 3;
    a[2][0] = base_start + 9;
    a[2][1] = base_start + 5;
    a[2][2] = base_start + 2;

    for (int i = n; i > 3; i--) fill_next(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << sep;
        }
        cout << endl;
    }



    return 0;
}