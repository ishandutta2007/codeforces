#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 2e5 + 21;

int n, tot, x[max_N], y[max_N], c[max_N], ch[max_N][2];

std::queue<int> Q;

int poll() {
    int ret = Q.front();
    return Q.pop(), ret;
}

inline LL abs2(LL x, LL y) {
    return x * x + y * y;
}

void merge3() {
    std::vector<int> vec = {poll(), poll(), poll()};
    LL r = 0;
    for (auto i : vec) r = std::max(r, abs2(x[i], y[i]));
    assert(r <= 1e12);
    for (int i = 0; i < 3; ++i) {
        int a = vec[i];
        for (int j = i + 1; j < 3; ++j) {
            int b = vec[j];
            if (abs2(x[a] - x[b], y[a] - y[b]) <= r) {
                ++tot;
                ch[tot][0] = a;
                ch[tot][1] = -b;
                x[tot] = x[a] - x[b];
                y[tot] = y[a] - y[b];
                assert(abs2(x[tot], y[tot]) <= 1e12);
                Q.push(tot);
                int d = vec[0] ^vec[1] ^vec[2] ^a ^b;
                Q.push(d);
                return;
            }
            if (abs2(x[a] + x[b], y[a] + y[b]) <= r) {
                ++tot;
                ch[tot][0] = a;
                ch[tot][1] = b;
                x[tot] = x[a] + x[b];
                y[tot] = y[a] + y[b];
                assert(abs2(x[tot], y[tot]) <= 1e12);
                Q.push(tot);
                int d = vec[0] ^vec[1] ^vec[2] ^a ^b;
                Q.push(d);
                return;
            }
        }
    }
}

void merge2() {
    int a = poll(), b = poll();
    if (abs2(x[a] - x[b], y[a] - y[b]) <= 1.5e6 * 1.5e6) {
        ++tot;
        ch[tot][0] = a;
        ch[tot][1] = -b;
    } else {
        ++tot;
        ch[tot][0] = a;
        ch[tot][1] = b;
    }
}

void dfs(int u) {
    if (!ch[u][0]) return;
    c[ch[u][0]] = c[u];
    dfs(ch[u][0]);
    if (ch[u][1] < 0) {
        ch[u][1] = -ch[u][1];
        c[ch[u][1]] = -c[u];
    } else {
        c[ch[u][1]] = c[u];
    }
    dfs(ch[u][1]);
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x + i, y + i);
        Q.push(i);
    }
    tot = n;
    while (Q.size() >= 3) merge3();
    if (Q.size() >= 2) merge2();
    c[tot] = 1;
    dfs(tot);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", c[i], " \n"[i == n]);
    }
    return 0;
}