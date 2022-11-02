#include <bits/stdc++.h>

const int maxn = 1005;

int n, count[maxn][maxn], ecount;
std::vector<std::vector<int>> v[maxn];
std::vector<int> e[maxn];
bool seen[maxn];

void fail() {
    printf("-1\n");
    exit(0);
}

int go(int i, int from) {
    seen[i] = true;
    int sum = 1;
    for (int j : e[i]) {
        if (j == from) continue;
        if (seen[j]) fail();
        sum += go(j, i);
    }
    return sum;
}

void ho(int i, int from, std::vector<int> &w) {
    w.push_back(i);
    for (int j : e[i]) {
        if (j == from) continue;
        ho(j, i, w);
    }
}

void check() {
    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> w;
        for (int j : e[i]) {
            w.push_back(std::vector<int>());
            ho(j, i, w.back());
            std::sort(w.back().begin(), w.back().end());
        }
        std::sort(w.begin(), w.end());
        if (v[i] != w) fail();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int left = n-1;
        while (left) {
            v[i].push_back(std::vector<int>());
            int m;
            scanf("%d:", &m);
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);
                x--;
                v[i].back().push_back(x);
                if (j+1 < m) scanf(",");
                count[i][x] = m;
            }
            std::sort(v[i].back().begin(), v[i].back().end());

            left -= m;
            if (left) {
                scanf("-");
            }
        }
        std::sort(v[i].begin(), v[i].end());
    }
    int ecount = 0;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        if (count[i][j] + count[j][i] == n) {
            //printf("edge %d %d\n", i, j);
            e[i].push_back(j);
            e[j].push_back(i);
            ecount++;
        }
    }

    if (ecount != n-1) fail();
    else if (go(0, -1) != n) fail();
    else check();
    printf("%d\n", n-1);
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        if (count[i][j] + count[j][i] == n) {
            printf("%d %d\n", i+1, j+1);
        }
    }
}