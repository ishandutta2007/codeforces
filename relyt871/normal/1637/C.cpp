#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizoef(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, a[MAXN], vis[MAXN];
vector<int> need, help, cnt;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        vis[i] = 0;
    }
    need.clear();
    help.clear();
    cnt.clear();
    LL ans = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] & 1) {
            if (need.size() && help.size() && help.back() > need.back()) {
                a[i] += 1;
                a[need.back()] += 1;
                if (--cnt.back() == 0) {
                    help.pop_back();
                    cnt.pop_back();
                }
                help.push_back(need.back());
                cnt.push_back(1);
                need.pop_back();
            } else {
                if (help.size()) {
                    vis[i] = 1;
                    help.clear();
                    cnt.clear();
                }
                need.push_back(i);
            }
        }
        if (a[i] >= 2) {
            help.push_back(i);
            cnt.push_back(a[i] / 2);
        }
    }
    bool flag = 1;
    for (int i = 2; i < n; ++i) {
        if (a[i] & 1) {
            flag = 0;
        }
    }
    for (int i = 2; i < n; ++i) {
        if (a[i] & 1) {
            if (vis[i] || (help.size() && help.back() > i)) {
                flag |= 1;
            }
        }
    }
    if (!flag) {
        puts("-1");
        return;
    }
    for (int i = 2; i < n; ++i) {
        ans += (a[i] + 1) / 2;
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}