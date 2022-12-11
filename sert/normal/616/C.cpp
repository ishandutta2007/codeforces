#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
//using namespace std;

const int N = 1003;
const int B = 320;

int p[N * N], sz[N * N];
char ss[N];
std::string a[N];
int v[10], len, res, n, m;

int fnd(int v) {
    return (v == p[v] ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 != v2) {
        if (sz[v1] > sz[v2]) {
            p[v2] = v1;
            sz[v1] += sz[v2];
        } else {
            p[v1] = v2;
            sz[v2] += sz[v1];
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(ss);
        a[i] = ss;
    }

    for (int i = 0; i < n * m; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j] == '.' && a[i][j - 1] == '.')
                uniq(i * m + j, i * m + j - 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.' && a[i - 1][j] == '.')
                uniq(i * m + j, i * m + j - m);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (a[i][j] == '*') {
        len = 0;
        if (i > 0 && a[i - 1][j] == '.')
            v[len++] = fnd(i * m + j - m);
        if (j > 0 && a[i][j - 1] == '.')
            v[len++] = fnd(i * m + j - 1);
        if (i + 1 < n && a[i + 1][j] == '.')
            v[len++] = fnd(i * m + j + m);
        if (j + 1 < m && a[i][j + 1] == '.')
            v[len++] = fnd(i * m + j + 1);
        std::sort(v, v + len);
        len = std::unique(v, v + len) - v;
        res = 1;
        for (int ii = 0; ii < len; ii++)
            res += sz[v[ii]];
        a[i][j] = char('0' + res % 10);
    }

    for (int i = 0; i < n; i++)
        puts(a[i].c_str());

    return 0;
}