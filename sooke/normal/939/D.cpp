#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 100005;

int n, cnt, fa[maxN], a[maxN], b[maxN];
std::string s, t;

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

int main() {
    std::cin >> n >> s >> t;
    for (int i = 0; i < 26; i++) { fa[i] = i; }
    for (int i = 0; i < n; i++) {
        if (find(s[i] - 'a') != find(t[i] - 'a')) { a[++cnt] = find(s[i] - 'a'); fa[find(s[i] - 'a')] = b[cnt] = find(t[i] - 'a'); }
    }
    std::cout << cnt << std::endl;
    for (int i = 1; i <= cnt; i++) { putchar(a[i] + 'a'); putchar(' '); putchar(b[i] + 'a'); putchar('\n'); }
    return 0;
}