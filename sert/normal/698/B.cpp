#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll INF = 1e12;

int p[N], a[N];
bool ok[N];
vector <int> bad;
int root = -1;
int fnd(int v) {
    return (p[v] == v ? v : p[v] = fnd(p[v]));
}
void uniq(int v1, int v2) {
    p[fnd(v1)] = fnd(v2);
}
int n;
int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i]--;
        if (i == a[i])
            root = i;
    }
    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < n; i++) {
        if (i == root) continue;
        if (fnd(i) != fnd(a[i])) {
            uniq(i, a[i]);
        } else {
            bad.push_back(i);
        }
    }

    printf("%d\n", bad.size());

    if (root == -1) {
        root = a[bad.back()] = bad.back();
        bad.pop_back();
    }

    p[root] = fnd(root);

    int cur = 0;

    for (auto q: bad) {
        if (fnd(q) != p[root]) {
            uniq(q, root);
            a[q] = root;
        } else {
            while (fnd(cur) == p[root])
                cur++;
            uniq(cur, q);
            a[q] = cur;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i] + 1);

    return 0;
}