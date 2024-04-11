#include <cstdio>
#include <queue>

int n, m, a[200005], b[200005];
std::deque<int> q;

int get(int &x) { x = q.front(); q.pop_front(); }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = n, x; i; i--) { scanf("%d", &x); q.push_back(x); }
    for (int i = 0; i < n + n; i++) {
        get(a[i]); get(b[i]);
        q.push_front(std::max(a[i], b[i]));
        q.push_back(std::min(a[i], b[i]));
    }
    for (long long i; m; m--) {
        scanf("%I64d", &i); i = i < n ? i - 1 : (i - 2) % (n - 1) + n;
        printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}