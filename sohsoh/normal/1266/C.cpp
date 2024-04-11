/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, vector<ll>> plv;
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

const ll MAXN = 500 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD =  998244353; // 1e9 + 9;

ll g[MAXN][MAXN];

bool is_prime(ll n) {
    ll sq = sqrt(n);
    for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
    return true;
}

void prep() {
    for (int i = 1; i < MAXN; i++) {
        g[1][i] = i + 1;
    }
}

int main() {
    ll r, c;
    cin >> r >> c;
    prep();

    if (r == 1 && c == 1) kill(0);
    if (c == 1) {
        for (int i = 0; i < r; i++) {
            cout << g[1][i + 1] << endl;
        }

        return 0;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            g[i][j] = i * (r + j);
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << g[i][j] << sep;
        }

        cout << endl;
    }
}