#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

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

int n;
multiset<LL> S;
LL sum;
priority_queue<LL> q;

void solve() {
    read(n);
    sum = 0;
    S.clear();
    for (int i = 1; i <= n; ++i) {
        int a; read(a);
        sum += a;
        S.insert(a);
    }
    while (!q.empty()) {
        q.pop();
    }
    q.push(sum);
    int cut = 0;
    while (cut < n - 1) {
        LL cur = q.top();
        q.pop();
        if (S.find(cur) != S.end()) {
            S.erase(S.find(cur));
        } else {
            ++cut;
            q.push(cur / 2);
            q.push((cur + 1) / 2);
        }
    }
    while (!q.empty()) {
        LL cur = q.top();
        q.pop();
        if (S.find(cur) != S.end()) {
            S.erase(S.find(cur));
        } else {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}