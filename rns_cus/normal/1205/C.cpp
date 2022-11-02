#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, a[N][N];

typedef pair <int, int> pii;
vector <pii> vec, mid;

inline int val(pii p) {
    return a[p.first][p.second];
}

bool query(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout); int x;
    scanf("%d", &x); return x;
}

bool query(pii x, pii y) {
    return query(x.first, x.second, y.first, y.second);
}

int main() {
    scanf("%d", &n); a[1][1] = a[1][2] = a[2][1] = 1;
    for (int i = 1; i <= n; i ++) {
        if (i > 1) {
            if (i > 2) {
                if (query(i - 2, 1, i, 1)) a[i][1] = a[i-2][1];
                else a[i][1] = a[i-2][1] ^ 1;
                if (query(i - 1, 1, i, 2)) a[i][2] = a[i-1][1];
                else a[i][2] = a[i-1][1] ^ 1;
            }
            else {
                if (query(1, 1, 2, 2)) a[2][2] = 1;
                else a[2][2] = 0;
            }
        }
        for (int j = 3; j <= n; j ++) {
            if (i == n && j == n) continue;
            if (j != i + 1) {
                if (query(i, j - 2, i, j)) a[i][j] = a[i][j-2];
                else a[i][j] = a[i][j-2] ^ 1;
            }
            else {
                if (query(i - 1, j - 1, i, j)) a[i][j] = a[i-1][j-1];
                else a[i][j] = a[i-1][j-1] ^ 1;
            }
        }
    }
    vec.clear(); mid.clear();
    for (int i = 1; i < n; i += 2) vec.push_back(pii(1, i)), mid.push_back(pii(1, i + 1));
    for (int i = 1; i <= n; i += 2) vec.push_back(pii(i, n));
    for (int i = 1; i < n; i += 2) mid.push_back(pii(i + 1, n));
    int k, sz = vec.size();
    for (k = 0; k + 2 < sz; k ++) if (val(vec[k]) != val(vec[k+2])) break;
    if (val(vec[k+1]) == val(vec[k])) {
        if (val(mid[k]) == val(mid[k+1])) {
            bool fg = query(vec[k], mid[k+1]);
            if (fg ^ (val(mid[k+1]) == val(vec[k]))) {
                for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j += 2) a[i][j] ^= 1;
            }
        }
        else {
            bool fg = query(mid[k], vec[k+2]);
            if (fg ^ (val(mid[k+1]) == val(vec[k+1]))) {
                for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j += 2) a[i][j] ^= 1;
            }
        }
    }
    else {
        if (val(mid[k]) != val(mid[k+1])) {
            bool fg = query(vec[k], mid[k+1]);
            if (fg ^ (val(mid[k+1]) == val(vec[k]))) {
                for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j += 2) a[i][j] ^= 1;
            }
        }
        else {
            bool fg = query(mid[k], vec[k+2]);
            if (fg ^ (val(mid[k+1]) == val(vec[k+1]))) {
                for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j += 2) a[i][j] ^= 1;
            }
        }
    }
    vec.clear(); mid.clear();
    for (int i = 1; i < n; i += 2) vec.push_back(pii(i, 1)), mid.push_back(pii(i + 1, 1));
    for (int i = 1; i <= n; i += 2) vec.push_back(pii(n, i));
    for (int i = 1; i < n; i += 2) mid.push_back(pii(n, i + 1));
    sz = vec.size();
    for (k = 0; k + 2 < sz; k ++) if (val(vec[k]) != val(vec[k+2])) break;
    if (val(vec[k+1]) == val(vec[k])) {
        if (val(mid[k]) == val(mid[k+1])) {
            bool fg = query(vec[k], mid[k+1]);
            if (fg ^ (val(mid[k+1]) == val(vec[k]))) {
                for (int i = 1; i <= n; i ++) for (int j = i - 1; j >= 1; j -= 2) a[i][j] ^= 1;
            }
        }
        else {
            bool fg = query(mid[k], vec[k+2]);
            if (fg ^ (val(mid[k+1]) == val(vec[k+1]))) {
                for (int i = 1; i <= n; i ++) for (int j = i - 1; j >= 1; j -= 2) a[i][j] ^= 1;
            }
        }
    }
    else {
        if (val(mid[k]) != val(mid[k+1])) {
            bool fg = query(vec[k], mid[k+1]);
            if (fg ^ (val(mid[k+1]) == val(vec[k]))) {
                for (int i = 1; i <= n; i ++) for (int j = i - 1; j >= 1; j -= 2) a[i][j] ^= 1;
            }
        }
        else {
            bool fg = query(mid[k], vec[k+2]);
            if (fg ^ (val(mid[k+1]) == val(vec[k+1]))) {
                for (int i = 1; i <= n; i ++) for (int j = i - 1; j >= 1; j -= 2) a[i][j] ^= 1;
            }
        }
    }
    puts("!");
    for (int i = 1; i <= n; i ++, puts("")) for (int j = 1; j <= n; j ++) putchar(a[i][j] + '0');
    fflush(stdout);

}