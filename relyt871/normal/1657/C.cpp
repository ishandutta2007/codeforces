#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int N = 500001;
const int MAXN = 1000005;

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

inline void cmin(int &x, int y) {
    if (x > y) x = y;
}

char s[MAXN], ss[MAXN];
int n, lst[MAXN], p[MAXN], to[MAXN];

void solve() {
    read(n);
    scanf("%s", s + 1);
    lst[N] = 0;
    for (int i = 1; i <= n; ++i) {
        to[i] = n + 1;
        lst[N + i] = lst[N - i] = 0;
    }
    to[n + 1] = n + 1;

    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') {
            ++pre;
            lst[N + pre] = i;
        } else {
            if (lst[N + pre]) {
                cmin(to[lst[N + pre]], i);
            }
            --pre;
        }
    }

    int len = 0;
    ss[0] = 'a';
    for (int i = 1; i <= n; ++i) {
        ss[++len] = s[i];
        ss[++len] = 'a';
    }
    int r = 0, c = 0;
    for (int i = 1; i <= len; ++i) {
        if (i < r) {
            p[i] = min(p[c * 2 - i], r - i);
        } else {
            p[i] = 1;
        }
        while (i - p[i] >= 0 && i + p[i] <= len && ss[i - p[i]] == ss[i + p[i]]) {
            ++p[i];
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = n; i >= 1; --i) {
        pq.push(i * 2);
        while (!pq.empty()) {
            int u = pq.top();
            if (u - p[u] >= i * 2 - 1) {
                pq.pop();
            } else {
                cmin(to[i], u - i + 1);
                break;
            }
        }
        pq.push(i * 2 - 1);
    }

    int ans = 0, u = 1;
    while (1) {
        if (to[u] != n + 1) {
            ++ans;
            u = to[u] + 1;
        } else {
            printf("%d %d\n", ans, n - u + 1);
            return;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}