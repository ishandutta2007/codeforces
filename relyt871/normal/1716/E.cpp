#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 18) + 5;

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

struct Node {
    LL sum, ans, pre, suf;
    Node(LL x = 0): sum(x), ans(x > 0? x : 0), pre(x), suf(x) {}
    Node operator + (const Node &rhs) const {
        Node ret;
        ret.sum = sum + rhs.sum;
        ret.ans = max(max(ans, rhs.ans), suf + rhs.pre);
        ret.pre = max(pre, sum + rhs.pre);
        ret.suf = max(rhs.suf, suf + rhs.sum);
        return ret;
    }
};
vector<Node> dp[2][MAXN];

void solve() {
    int n; read(n);
    for (int i = 0; i < (1 << n); ++i) {
        LL x; read(x);
        dp[0][0].push_back(Node(x));
    }
    int pre = 0, cur = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << i); ++j) {
            dp[cur][j].clear();
        }
        for (int j = 0; j < (1 << i); ++j) {
            int sz = dp[pre][j].size();
            for (int k = 0; k < sz; k += 2) {
                dp[cur][j].push_back(dp[pre][j][k] + dp[pre][j][k + 1]);
                dp[cur][j ^ (1 << i)].push_back(dp[pre][j][k + 1] +dp[pre][j][k]);
            }
        }
        swap(pre, cur);
    }
    int q; read(q);
    int mask = 0;
    while (q--) {
        int k; read(k);
        mask ^= (1 << k);
        printf("%lld\n", dp[pre][mask][0].ans);
    }
}

int main() {
    solve();
    return 0;
}