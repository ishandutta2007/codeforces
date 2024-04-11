#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double
#define int long long

char matr[60][60];
bool us[60][60];
int n;

bool ok(int x, int y) {
    return x > -1 && x < n && y > -1 && y < n && !us[x][y];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> matr[i][j];
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) q.pb({i, n});
    for (int i = 0; i < n; i++) q.pb({n, i});
    memset(us, 0, sizeof(us));
    while (!q.empty()) {
        auto v = q.front();
        q.pop_front();
        if (ok(v.x - 1, v.y) && matr[v.x - 1][v.y] == '1') {
            us[v.x - 1][v.y] = 1;
            q.pb({v.x - 1, v.y});
        }
        if (ok(v.x, v.y - 1) && matr[v.x][v.y - 1] == '1') {
            us[v.x][v.y - 1] = 1;
            q.pb({v.x, v.y - 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == '1' && !us[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}