#include <cstdio>
#include <vector>

inline int read() {
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 1005;

int n, sum, a[6][maxN];
std::vector<int> ans;
bool flag;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) { a[j][i] = read(); }
    }
    for (int i = 1; i <= n; i++) {
        flag = false;
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (i != u && i != v && u != v) {
                    sum = 0;
                    for (int j = 1; j <= 5; j++) { sum += (a[j][u] - a[j][i]) * (a[j][v] - a[j][i]); }
                    if (sum > 0) { flag = true; break; }
                }
            }
            if (flag) { break; }
        }
        if (!flag) { ans.push_back(i); }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (int) ans.size(); i++) { printf("%d\n", ans[i]); }
    return 0;
} //