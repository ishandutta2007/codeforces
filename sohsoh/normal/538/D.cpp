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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char G[MAXN][MAXN], ans[MAXN][MAXN];
vector<pll> v, b, z, st;
ll n;

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'o') v.push_back({i, j});
            else if (G[i][j] == 'x') b.push_back({i, j});
            else z.push_back({i, j});
        }
    }

    for (int i = -1 * n; i <= n; i++) {
        for (int j = -1 * n; j <= n; j++) {
            bool ok = true;
            for (pll e : v) {
                if (e.X + i >= 0 && e.X + i < n && e.Y + j >= 0 && e.Y + j < n && G[e.X + i][e.Y + j] == '.') {
                    ok = false;
                    break;
                }
            }

            if (ok) st.push_back({i, j});
        }
    }

    for (pll e : b) {
        bool rem = false;

        for (pll p : st) {
            if (e.X - p.X >= 0 && e.X - p.X < n && e.Y - p.Y >= 0 && e.Y - p.Y < n && G[e.X - p.X][e.Y - p.Y] == 'o') {
                rem = true;
                break;
            }
        }

        if (!rem) return cout << "NO" << endl, 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) ans[i][j] = '.';
    for (pll p : st) ans[n + p.X][n + p.Y] = 'x';
    ans[n][n] = 'o';
    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}