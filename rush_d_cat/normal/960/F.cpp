#include <iostream>
#include <unordered_map>
using namespace std;
const int N = 1000000 + 10;
unordered_map<int, int> mp[N];
void add(int id, int i, int x) {
    while (i < N) {
        mp[id][i] = max(x, mp[id][i]);
        i += i & (-i);
    }
}
int sum(int id, int x) {
    int ret = 0;
    while (x > 0) {
        ret = max(mp[id][x], ret);
        x -= x & (-x);
    }
    return ret;
}
int n, m;
int a[N], b[N], w[N];
int main() {
    scanf("%d %d", &n, &m);
    int ret = 0;
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &a[i], &b[i], &w[i]); w[i] ++;
        int len = sum(a[i], w[i]-1);
        ret = max(ret, len + 1);
        add(b[i], w[i], len + 1);
    }
    printf("%d\n", ret);
}