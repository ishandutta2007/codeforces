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

const ll MAXN = 100 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, k, B[MAXN];
bool A[MAXN][MAXN];
char C[MAXN], ans[MAXN][MAXN];
ll solve() {
    ll r = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            A[i][j] = (c == 'R');
            if (A[i][j]) r++;
        }
    }

    ll ind = 0;
    for (int i = 0; i < k; i++) B[i] = r / k;
    for (int i = 0; i < r % k; i++) B[i]++;
    B[k - 1] = INF;

    for (int i = 0; i < n; i++) {
        for (int j_t = 0; j_t < m; j_t++) {
            ll j = j_t;
//            debug(i);
//            debug(j);
            if (i % 2) j = m - j - 1;
            if (A[i][j]) B[ind]--;
            ans[i][j] = C[ind];
            if (B[ind] == 0) ind++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }

        cout << endl;
    }

    fill(B, B + k, 0);

    return 0;
}

int main() {
    fast_io;
    ll i = 0;
    for (char c = '0'; c <= '9'; c++) {
        C[i] = c;
        i++;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        C[i] = c;
        i++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        C[i] = c;
        i++;
    }
    C[i] = C[i - 1];

    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}