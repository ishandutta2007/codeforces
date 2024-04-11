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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
char res[MAXN][MAXN];
pll inp[MAXN][MAXN];
queue<pll> stop, loop_cell;

void DFS(pll now, pll sp, char c = 'N') {
    ll x = now.X, y = now.Y;
    if (inp[x][y + 1] == sp && res[x][y + 1] == c) {
        res[x][y + 1] = 'L';
        DFS({x, y + 1}, sp, c);
    }

    if (inp[x][y - 1] == sp && res[x][y - 1] == c) {
        res[x][y - 1] = 'R';
        DFS({x, y - 1}, sp, c);
    }

    if (inp[x + 1][y] == sp && res[x + 1][y] == c) {
        res[x + 1][y] = 'U';
        DFS({x + 1, y}, sp, c);
    }

    if (inp[x - 1][y] == sp && res[x - 1][y] == c) {
        res[x - 1][y] = 'D';
        DFS({x - 1, y}, sp, c);
    }
}

int main() {
    fast_io;
    cin >> n;
    pll ls_sign = {-1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> inp[i][j].X >> inp[i][j].Y;
            pll t_pair = {i, j};
            if (inp[i][j] == t_pair) {
                res[i][j] = 'X';
                stop.push({i, j});
            } else if (inp[i][j] == ls_sign) {
                res[i][j] = 'Z';
                loop_cell.push({i, j});
            } else res[i][j] = 'N';
        }
    }

    while (!stop.empty()) {
        pll sp = stop.front();
        DFS(sp, sp);
        stop.pop();
    }

    while (!loop_cell.empty()) {
        pll cur = loop_cell.front();
        ll x = cur.X, y = cur.Y;
        loop_cell.pop();
        if (res[x][y] != 'Z') continue;

        if (res[x][y - 1] == 'Z') {
            res[x][y] = 'L';
            res[x][y - 1] = 'R';

            DFS(cur, {-1, -1}, 'Z');
            DFS({x, y - 1}, {-1, -1}, 'Z');
        } else if (res[x][y + 1] == 'Z') {
            res[x][y] = 'R';
            res[x][y + 1] = 'L';

            DFS(cur, {-1, -1}, 'Z');
            DFS({x, y + 1}, {-1, -1}, 'Z');
        } else if (res[x - 1][y] == 'Z') {
            res[x][y] = 'U';
            res[x - 1][y] = 'D';

            DFS(cur, {-1, -1}, 'Z');
            DFS({x - 1, y}, {-1, -1}, 'Z');
        } else if (res[x + 1][y] == 'Z') {
            res[x][y] = 'D';
            res[x + 1][y] = 'U';

            DFS(cur, {-1, -1}, 'Z');
            DFS({x + 1, y}, {-1, -1}, 'Z');
        } else {
            return cout << "INVALID" << endl, 0;
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (res[i][j] == 'N') return cout << "INVALID" << endl, 0;

    cout << "VALID" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}