/*
    Soheil Mohammadkhani
    now, i'm expert, but i don't have time to think about the text right now(this is a text :))
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
#define alog(a, n)                  for (ll i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (ll i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 3;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD =  998244353; // 1e9 + 9;

ll n, m, t, res[MAXN][MAXN] = {0};
bool a[MAXN][MAXN] = {false};
queue<pll> q, tq;

void prep() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && a[i][j] == a[i - 1][j]) {
                q.push({i, j});
                if (res[i - 1][j] == -1) q.push({i - 1, j});
                res[i][j] = 0;
                res[i - 1][j] = 0;
            }
            if (j > 0 && a[i][j] == a[i][j - 1]) {
                q.push({i, j});
                if (res[i][j - 1] == -1) q.push({i, j - 1});
                res[i][j] = 0;
                res[i][j - 1] = 0;
            }
        }
    }
}

bool avai(ll i, ll j) {
    return res[i][j] == -1;
}

void check(pll p) {
    ll i = p.X;
    ll j = p.Y;

    if (i > 0 && avai(i - 1, j)) {
        res[i - 1][j] = res[i][j] + 1;
        tq.push({i - 1, j});
    }

    if (avai(i + 1, j)) {
        res[i + 1][j] = res[i][j] + 1;
        tq.push({i + 1, j});
    }

    if (j > 0 && avai(i, j - 1)) {
        res[i][j - 1] = res[i][j] + 1;
        tq.push({i, j - 1});
    }

    if (avai(i, j + 1)) {
        res[i][j + 1] = res[i][j] + 1;
        tq.push({i, j + 1});
    }
}

void BFS() {
    while (!q.empty()) {
        while (!q.empty()) {
            check(q.front());
            q.pop();
        }

        while (!tq.empty()) {
            q.push(tq.front());
            tq.pop();
        }
    }
}

ll solve() {
    ll i, j, p;
    cin >> i >> j >> p;
    i--; j--;

    if (res[i][j] == -1 || p < res[i][j]) kill(a[i][j]);
    ll diff = p - res[i][j];
    if (diff % 2 == 0) kill(a[i][j]);
    cout << !a[i][j] << endl;
    return 0;
}


int main() {
    fast_io;
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '1') a[i][j] = true;
            res[i][j] = -1;
        }
    }

    prep();
    BFS();

    while (t--) {
        solve();
    }
    return 0;
}