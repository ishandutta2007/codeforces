#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, lst, ans[N], bln[N];
char opt[3];
std::set<int> f;
std::stack<int> g;

int main() {
    n = read(); g.push(n + 1);
    for (int _ = 0; _ < n * 2; _++) {
        scanf("%s", opt);
        if (opt[0] == '+') {
            m++;
            f.insert(m);
        } else {
            int x = read();
            if (f.empty()) { printf("NO\n"); return 0; }
            int y;
            while (true) {
                y = g.top();
                if (y > x) { break; }
                g.pop();
            }
            g.push(x); bln[x] = m;
            auto it = f.lower_bound(bln[y] + 1);
            if (it == f.end()) { printf("NO\n"); return 0; }
            int p = *it;
            ans[p] = x;
            f.erase(p);
            lst = m;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}