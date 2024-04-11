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

const ll MAXN = 1e3 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, R[MAXN], C[MAXN];
bool g[MAXN][MAXN] = {false};

int main() {
    fast_io;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++) g[i][j] = true;
        R[i] = x;
    }

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            if (R[j] == i) return cout << 0 << endl, 0;
            g[j][i] = true;
        }

        if (g[x][i]) return cout << 0 << endl, 0;

        C[i] = x;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (R[i] == j || C[j] == i || g[i][j]) continue;
            ans *= 2;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}