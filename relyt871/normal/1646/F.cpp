#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int N = 105;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, c[N][N];
vector< vector<int> > ans;

int Find(int i) {
    for (int j = 0; j < n; ++j) {
        if (c[i][j] > 1) {
            return j;
        }
    }
    return -1;
}

void solve() {
    read(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; read(x);
            ++c[i][x - 1];
        }
    }
    while (1) {
        int b = -1, p = -1;
        for (int i = 0; i < n; ++i) {
            if (Find(i) != -1) {
                b = i;
                break;
            }
        }
        if (b == -1) {
            break;
        }
        vector<int> cur;
        cur.resize(n);
        int i = b; do {
            int j = Find(i);
            if (j == -1) {
                cur[i] = p;
            } else {
                ++c[i][p];
                p = cur[i] = j;
                --c[i][j];
            }
            i = (i + 1) % n;
        } while (i != b);
        ++c[b][p];
        ans.push_back(cur);
    }
    for (int k = 1; k < n; ++k) {
        vector<int> cur;
        for (int i = 0; i < n; ++i) {
            cur.push_back((i - k + n) % n);
        }
        for (int i = 0; i < k; ++i) {
            ans.push_back(cur);
        }
    }
    printf("%d\n", ans.size());
    for (auto v : ans) {
        for (auto x : v) {
            printf("%d ", x + 1);
        }
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}