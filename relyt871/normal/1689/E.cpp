#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 2005;

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

int n, a[N], ufs[N];

void Output(int m) {
    printf("%d\n", m);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int getf(int x) {
    return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
}

void Merge(int x, int y) {
    x = getf(x);
    y = getf(y);
    if (x != y) {
        ufs[x] = y;
    }
}

bool Check() {
    for (int i = 1; i <= n; ++i) {
        ufs[i] = i;
    }
    for (int d = 0; d < 30; ++d) {
        int fst = -1;
        for (int i = 1; i <= n; ++i) {
            if ((a[i] >> d) & 1) {
                if (fst == -1) {
                    fst = i;
                } else {
                    Merge(fst, i);
                }
            }
        }
    }
    int rt = getf(1);
    for (int i = 2; i <= n; ++i) {
        if (getf(i) != rt) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            ++ans;
            a[i] = 1;
        }
    }
    if (Check()) {
        Output(ans);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        ++a[i];
        if (Check()) {
            Output(ans + 1);
            return;
        }
        --a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) continue;
        --a[i];
        if (Check()) {
            Output(ans + 1);
            return;
        }
        ++a[i];
    }
    vector<int> pos;
    pos.push_back(1);
    int maxlow = (a[1] & (-a[1]));
    for (int i = 2; i <= n; ++i) {
        int cur = (a[i] & (-a[i]));
        if (cur > maxlow) {
            maxlow = cur;
            pos.clear();
        }
        if (cur == maxlow) {
            pos.push_back(i);
        }
    }
    assert(pos.size() >= 2);
    --a[pos[0]];
    ++a[pos[1]];
    assert(Check());
    Output(ans + 2);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}