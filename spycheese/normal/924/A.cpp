#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define fst first 
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define FILE_NAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

const int MAXN = 55;

int n, m;
string s[MAXN];

bool read() {
    if (!(cin >> n >> m)) {
        return 0;
    }
    forn(i, n) {
        cin >> s[i];
    }
    return 1;
}

bool solve() {
    sort(s, s + n); 
    n = unique(s, s + n) - s;
    vi used(m, 0);
    forn(i, n) {
        forn(j, m) {
            if (s[i][j] == '#') {
                if (used[j]) {
                    return 0;
                }
                used[j] = 1;
            }
        }
    }
    return 1;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << (solve() ? "Yes" : "No") << '\n';
    }

#ifdef LOCAL
    eprintf("Time: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif

    return 0;

}