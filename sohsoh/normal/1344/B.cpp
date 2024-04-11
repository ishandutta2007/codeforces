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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 1e6 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m;
bool a[MAXN][MAXN] = {false};
queue<ll> black;

bool ans_ex = false;

void check() {
    bool av = false, ab = false;
    for (int i = 0; i < n; i++) {
        ll c = 0;
        for (int j = 1; j < m; j++) {
            if (a[i][j - 1] && !a[i][j]) c++;
        }

        if (a[i][m - 1]) c++;

        if (c == 0) ab = true;

        if (c > 1) {
            cout << -1 << endl;
            exit(0);
        }
    }

    for (int j = 0; j < m; j++) {
        ll c = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1][j] && !a[i][j]) c++;
        }

        if (a[n - 1][j]) c++;

        if (c == 0) av = true;

        if (c > 1) {
            cout << -1 << endl, 0;
            exit(0);
        }
    }

    if (av != ab) {
        cout << -1 << endl, 0;
        exit(0);
    }
}

void DFS(pll p) {
    a[p.X][p.Y] = false;

    if (a[p.X][p.Y + 1]) {
        DFS({p.X, p.Y + 1});
    }

    if (p.Y > 0 && a[p.X][p.Y - 1]) {
        DFS({p.X, p.Y - 1});
    }

    if (a[p.X + 1][p.Y]) {
        DFS({p.X + 1, p.Y});
    }

    if (p.X > 0 && a[p.X - 1][p.Y]) {
        DFS({p.X, p.Y - 1});
    }
}

int main() {
    fast_io;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = ans_ex = true; // use black queue if you want :), and some comment here for some works :)
        }
    }

    check();

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                DFS({i, j});
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}