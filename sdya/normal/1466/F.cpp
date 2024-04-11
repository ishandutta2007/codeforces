#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

const int maxN = 510000;
int a[maxN], b[maxN], len[maxN];
int p[maxN];

int findP(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = findP(p[v]);
}

void merge(int u, int v) {
    u = findP(u);
    v = findP(v);
    p[u] = v;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        } else {
            scanf("%d%d", &a[i], &b[i]);
        }
        len[i] = k;
        --a[i];
        --b[i];
    }
    for (int i = 0; i < m; ++i) {
        p[i] = i;
    }
    set < int > visited;

    vector < int > res;
    for (int i = 0; i < n; ++i) {
        a[i] = findP(a[i]);
        b[i] = findP(b[i]);

        if (len[i] == 1) {
            if (visited.count(a[i])) {
                continue;
            }
            visited.insert(a[i]);
            res.push_back(i);
            continue;
        }

        if (a[i] == b[i]) {
            continue;
        }

        if (visited.count(a[i]) && visited.count(b[i])) {
            continue;
        }
        if (visited.count(a[i])) {
            swap(a[i], b[i]);
        }

        res.push_back(i);
        visited.insert(a[i]);
        merge(a[i], b[i]);
    }

    const int P = 1000000007;
    int ans = 1;
    for (int i = 0; i < res.size(); ++i) {
        ans = (ans + ans) % P;
    }
    printf("%d %d\n", ans, res.size());
    for (int i = 0; i < res.size(); ++i) {
        printf("%d ", res[i] + 1);
    }
    printf("\n");

    return 0;
}