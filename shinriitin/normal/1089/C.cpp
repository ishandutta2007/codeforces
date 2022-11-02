#include <bits/stdc++.h>

const int max_N = 500 + 21;

int n, m, dis[max_N][max_N], Q[max_N], tail;

std::vector<int> vec[max_N];

inline void bfs(int *dis, int s) {
    memset(dis + 1, -1, n * sizeof(int));
    dis[s] = 0;
    Q[tail = 1] = s;
    for (int i = 1; i <= tail; ++i) {
        int u = Q[i];
        for (auto &v : vec[u]) {
            if (~dis[v]) continue;
            dis[v] = dis[u] + 1;
            Q[++tail] = v;
        }
    }
}

int query_cnt;

inline int query(int x) {
    ++query_cnt;
    assert(query_cnt <= 10);
    printf("%d\n", x);
    fflush(stdout);
    char tmp[10];
    scanf("%s", tmp);
    if (*tmp == 'F') return -1;
    scanf("%d", &x);
    return x;
}

inline int find() {
    int rt = -1, tmp = 0;
    for (int i = 1; i <= tail; ++i) {
        int u = Q[i], sum = 0;
        for (int j = 1; j <= tail; ++j) {
            int v = Q[j];
            sum += dis[u][v];
        }
        if (rt == -1 || tmp > sum) {
            rt = u;
            tmp = sum;
        }
    }
    return rt;
}

void testCase() {
    query_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        Q[i] = i;
    }
    tail = n;
    while (true) {
        int u = find();
        int v = query(u);
        if (v == -1) break;
        for (int i = 1; i <= tail; ++i) {
            int x = Q[i];
            if (dis[u][x] > dis[v][x]) continue;
            std::swap(Q[i--], Q[tail--]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, k, pre, cur; i <= m; ++i) {
        scanf("%d", &k);
        pre = 0;
        while (k--) {
            scanf("%d", &cur);
            if (pre) {
                vec[pre].push_back(cur);
                vec[cur].push_back(pre);
            }
            pre = cur;
        }
    }
    for (int i = 1; i <= n; ++i) {
        bfs(dis[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        testCase();
    }
}