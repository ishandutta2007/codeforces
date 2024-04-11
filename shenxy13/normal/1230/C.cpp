#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n, num[7];
bool gen(int i) {
    if (i == n - 1) {
        if (++num[i] == 7) {
            num[i] = 1;
            return false;
        } else return true;
    } else {
        if (!gen(i + 1)) {
            if (++num[i] == 7) {
                num[i] = 1;
                return false;
            } else return true;
        } else return true;
    }
}
int main() {
    int m, a, b, ans = 0;
    scanf("%d %d", &n, &m);
    int edges[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        --a, --b;
        edges[i] = a * n + b;
    }
    fill_n(num, n, 1);
    unordered_set<int> dominos;
    for (int i = 0; i < m; ++i) {
        a = edges[i] / n, b = edges[i] % n;
        a = num[a] - 1, b = num[b] - 1;
        if (a <= b) dominos.insert(a * 6 + b);
        else dominos.insert(b * 6 + a);
    }
    ans = max(ans, (int) dominos.size());
    while (gen(0)) {
        dominos.clear();
        for (int i = 0; i < m; ++i) {
            a = edges[i] / n, b = edges[i] % n;
            a = num[a] - 1, b = num[b] - 1;
            if (a <= b) dominos.insert(a * 6 + b);
            else dominos.insert(b * 6 + a);
        }
        ans = max(ans, (int) dominos.size());
    }
    printf("%d", ans);
    return 0;
}