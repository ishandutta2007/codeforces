#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 2007;

int n, k;

char a[N][N];
int ma[N][N];
int nxt[N][N];

struct State {
    int a, b, id;
};

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
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ma[i][j] = -1;
            nxt[i][j] = -1;
        }
    }
    if (a[0][0] == 'a') {
        ma[0][0] = 1;
    } else {
        ma[0][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 != n) {
                ma[i][j + 1] = max(ma[i][j + 1], ma[i][j] + (a[i][j + 1] == 'a' ? 1 : 0));
            }
            if (i + 1 != n) {
                ma[i + 1][j] = max(ma[i + 1][j], ma[i][j] + (a[i + 1][j] == 'a' ? 1 : 0));
            }
        }
    }
    if (2 * n - 1 - ma[n - 1][n - 1] <= k) {
        for (ll i = 0; i < 2 * n - 1; i++) {
            cout << 'a';
        }
        return 0;
    }
    int maxsum = -1;
    vector <pair <int, int> > all;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < maxsum) continue;
            int cnt = i + j + 1;
            int cnta = ma[i][j];
            //cout << i << " " << j << " " << cnt << " " << cnta << "\n";
            if (cnt - cnta <= k) {
                if (i + j > maxsum) {
                    maxsum = i + j;
                    all.clear();
                }
                all.push_back({i, j});
            }
        }
    }
    vector <int> pos(n, -1);
    pos[n - 1] = 0;
    for (int sum = 2 * n - 3; sum >= 0; sum--) {
        vector <State> s;
        for (int i = 0; i < n; i++) {
            int j = sum - i;
            if (j < 0 || j >= n) continue;
            int mink = INF;
            int way = -1;
            if (i + 1 < n) {
                if (mink > pos[i + 1]) {
                    mink = pos[i + 1];
                    way = i + 1;
                }
            }
            if (j + 1 < n) {
                if (mink > pos[i]) {
                    mink = pos[i];
                    way = i;
                }
            }
            s.push_back({a[i][j] - 'a', mink, i});
            nxt[i][j] = way;
        }
        sort(s.begin(), s.end(), [&] (State a, State b) {
            if (a.a != b.a) {
                return a.a < b.a;
             }
             if (a.b != b.b) {
                return a.b < b.b;
             }
             return a.id < b.id;
        });
        for (int i = 0; i < (int) s.size(); i++) {
            pos[s[i].id] = i;
        }
    }
    if (!all.size()) {
        int x = 0, y = 0;
        string res = "";
        res += a[x][y];
        while (x + y != 2 * n - 2) {
            if (nxt[x][y] == x) {
                y++;
            } else {
                x++;
            }
            res += a[x][y];
        }
        cout << res << "\n";
        return 0;
    }
    vector <pair <string, int> > needsort;
    for (auto p : all) {
        int v = p.first * n + p.second;
        int x = p.first, y = p.second;
        //cout << x << " " << y << "\n";
        string s = "";
        while (x + y != 2 * n - 2) {
            if (nxt[x][y] == x) {
                y++;
            } else {
                x++;
            }
            s += a[x][y];
        }
        needsort.push_back({s, v});
    }
    sort(needsort.begin(), needsort.end());
    auto t = needsort[0];
    string suf = t.first;
    int v = t.second;
    int i = v / n, j = v % n;
    string pref = "";
    for (int k = 0; k <= i + j; k++) {
        pref += 'a';
    }
    cout << pref << suf;
}