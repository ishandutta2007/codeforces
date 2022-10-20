#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m, good[MAXN], tot;
int a[MAXN], pos[MAXN], bad;
vector<int> arr[MAXN];
map<pii, int> mp;
set<pii> st;

bool Check(int x, int y) {
    if (x > y) swap(x, y);
    int delta = 0;
    delta -= (a[x] < a[x - 1]);
    delta -= (a[x + 1] < a[x]);
    delta -= (a[y] < a[y - 1]);
    delta -= (a[y + 1] < a[y]);
    if (x + 1 == y && a[y] < a[x]) {
        ++delta;
    }
    swap(a[x], a[y]);
    delta += (a[x] < a[x - 1]);
    delta += (a[x + 1] < a[x]);
    delta += (a[y] < a[y - 1]);
    delta += (a[y + 1] < a[y]);
    if (x + 1 == y && a[y] < a[x]) {
        --delta;
    }
    swap(a[x], a[y]);
    return (delta == -bad);
}

void solve() {
    mp.clear();
    read(n); read(m);
    a[0] = -1;
    a[m + 1] = 2e9;
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        arr[i].clear();
        for (int j = 1; j <= m; ++j) {
            read(a[j]);
            arr[i].push_back(a[j]);
        }
        bad = 0;
        for (int j = 2; j <= m; ++j) {
            if (a[j] < a[j - 1]) {
                pos[++bad] = j;
            }
        }
        if (!bad) {
            good[++tot] = i;
        } else if (bad > 2) {
            puts("-1");
            return;
        } else {
            st.clear();
            for (int j = 1; j <= bad; ++j) {
                for (int k = 1; k <= m; ++k) {
                    if (Check(pos[j], k)) {
                        st.insert(make_pair(min(pos[j], k), max(pos[j], k)));
                    }
                    if (Check(pos[j] - 1, k)) {
                        st.insert(make_pair(min(pos[j] - 1, k), max(pos[j] - 1, k)));
                    }
                }
            }
            for (auto pr : st) {
                ++mp[pr];
            }
        }
    }
    if (tot == n) {
        printf("1 1\n");
        return;
    }
    for (auto pr : mp) {
        if (pr.se == n - tot) {
            bool ok = 1;
            for (int i = 1; i <= tot; ++i) {
                if (arr[good[i]][pr.fi.fi - 1] != arr[good[i]][pr.fi.se - 1]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                printf("%d %d\n", pr.fi.fi, pr.fi.se);
                return;
            }
        }
    }
    puts("-1");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}