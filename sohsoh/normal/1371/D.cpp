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

const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[MAXN][MAXN] = {0};

ll solve() {
    ll n, k;
    cin >> n >> k;
    priority_queue<pll> C;
    for (int i = 0; i < n; i++) C.push({0, i});
    for (int i = 0; i < k % n; i++) {
        for (int j = 0; j < k / n + 1; j++) {
            pll p = C.top();
            C.pop();
            G[i][p.Y] = 1;
            C.push({p.X - 1, p.Y});
        }
    }

    for (int i = k % n; i < n; i++) {
        for (int j = 0; j < k / n; j++) {
            pll p = C.top();
            C.pop();
            G[i][p.Y] = 1;
            C.push({p.X - 1, p.Y});
        }
    }

    if (k % n) cout << 2 << endl;
    else cout << 0 << endl;
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << G[i][j];
                G[i][j] = 0;
            }
            cout << endl;
    }

    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}