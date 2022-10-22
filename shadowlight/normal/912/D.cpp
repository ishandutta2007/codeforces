#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, m, r, k;

ll count(ll x, ll y) {
    x++, y++;
    ll res = (min(n + 1, x + r) - max(x, r)) * (min(m + 1, y + r) - max(y, r));
    //cout << x << " " << y << " " << res << "\n";
    return res;
}

ll ans = 0;

void upd(ll x, ll y) {
    ans += count(x, y);
    //cout << x << " " << y << " " << count(x, y) << "\n";
    k--;
    if (!k) {
        cout << fixed << setprecision(9);
        cout << (double) ans / (double) ((n - r + 1) * (m - r + 1));
        exit(0);
    }
}

const int D = 4;
vector <int> dx = {0, 1, 0, -1};
vector <int> dy = {1, 0, -1, 0};

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m >> r >> k;
    ll lx = n / 2, ly = m / 2, rx = n / 2, ry = m / 2;
    if (n % 2 == 0) {
        rx++;
    }
    if (m % 2 == 0) {
        ry++;
    }
    vector <map <ll, ll> > used(n);
    set <pair <ll, ll> > q;
    used[n / 2][m / 2] = 1;
    q.insert({count(n / 2, m / 2), (n / 2) * m + m / 2});
    while (!q.empty()) {
        ll v = q.rbegin()->second;
        q.erase(*q.rbegin());
        ll x = v / m, y = v % m;
        upd(x, y);
        for (int i = 0; i < D; i++) {
            ll x1 = x + dx[i], y1 = y + dy[i];
            if (!isCorrect(x1, y1)) continue;
            if (!used[x1][y1]) {
                q.insert({count(x1, y1), x1 * m + y1});
                used[x1][y1] = 1;
            }
        }
    }
}