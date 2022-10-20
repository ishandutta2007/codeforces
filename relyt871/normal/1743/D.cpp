#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;

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

char s[MAXN], t[MAXN];
int n;

int Trans(int l, int r) {
    int ret = 0;
    for (int i = l; i <= r; ++i) {
        ret = ret * 2 + s[i];
    }
    return ret;
}

void solve() {
    read(n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] -= '0';
        t[i] = s[i];
    }
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 1) {
            p = i; break;
        }
    }
    if (p == 0) {
        puts("0");
        return;
    }
    if (n == 5) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    for (int l = k; l <= n; ++l) {
                        ans = max(ans, Trans(i, j) | Trans(k, l));
                    }
                }
            }
        }
        int a[10], c = 0;
        while (ans) {
            a[++c] = (ans & 1);
            ans >>= 1;
        }
        while (c) {
            printf("%d", a[c--]);
        }
        puts("");
        return;
    }
    vector<int> v;
    bool flag = 0;
    for (int i = p + 1; i <= n; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            ++v[j];
        }
        if (!flag) {
            for (int j = 1; j <= i; ++j) {
                v.push_back(j);
            }
        }
        vector<int> v0, v1;
        for (auto x : v) {
            if ((s[i] | s[x]) == 0) {
                v0.push_back(x);
            } else {
                v1.push_back(x);
            }
        }
        if (v1.size()) {
            if (s[i] == 0) {
                flag = 1;
            }
            t[i] = 1;
            swap(v, v1);
        } else if (flag) {
            t[i] = 0;
        } else {
            v.clear();
        }
    }
    for (int i = p; i <= n; ++i) {
        putchar(t[i] + '0');
    }
    puts("");
}

int main() {
    solve();
    return 0;
}