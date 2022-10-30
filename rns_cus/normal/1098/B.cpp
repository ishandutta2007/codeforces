#include <bits/stdc++.h>
using namespace std;

#define N 300030

int n, m, r[N][4][4], c[N][4][4];
char s[N];

char ch[] = "ACGT";
bool dir;
int x, y, z, w;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%s", s + i * m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < 4; k ++) {
                if (j == k) continue;
                for (int l = 0; l < m; l ++)
                    if (s[i*m+l] != ch[l&1?k:j]) r[i][j][k] ++;
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < 4; j ++) {
            for (int k = 0; k < 4; k ++) {
                if (j == k) continue;
                for (int l = 0; l < n; l ++)
                    if (s[l*m+i] != ch[l&1?k:j]) c[i][j][k] ++;
            }
        }
    }
    int rlt = n * m + 1;
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (i == j) continue;
            int k = 0, l;
            while (k == i || k == j) k ++;
            l = 6 - i - j - k;
            int cnt = 0;
            for (int t = 0; t < n; t ++) {
                if (t & 1) cnt += min(r[t][k][l], r[t][l][k]);
                else cnt += min(r[t][i][j], r[t][j][i]);
            }
            if (rlt > cnt) rlt = cnt, dir = 0, x = i, y = j, z = k, w = l;
        }
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (i == j) continue;
            int k = 0, l;
            while (k == i || k == j) k ++;
            l = 6 - i - j - k;
            int cnt = 0;
            for (int t = 0; t < m; t ++) {
                if (t & 1) cnt += min(c[t][k][l], c[t][l][k]);
                else cnt += min(c[t][i][j], c[t][j][i]);
            }
            if (rlt > cnt) rlt = cnt, dir = 1, x = i, y = j, z = k, w = l;
        }
    }
    if (dir) {
        for (int t = 0; t < m; t ++) {
            if (t & 1) {
                if (c[t][z][w] > c[t][w][z]) swap(z, w);
                for (int p = 0; p < n; p ++) s[p*m+t] = ch[p&1?w:z];
            }
            else {
                if (c[t][x][y] > c[t][y][x]) swap(x, y);
                for (int p = 0; p < n; p ++) s[p*m+t] = ch[p&1?y:x];
            }
        }
    }
    else {
        for (int t = 0; t < n; t ++) {
            if (t & 1) {
                if (r[t][z][w] > r[t][w][z]) swap(z, w);
                for (int p = 0; p < m; p ++) s[t*m+p] = ch[p&1?w:z];
            }
            else {
                if (r[t][x][y] > r[t][y][x]) swap(x, y);
                for (int p = 0; p < m; p ++) s[t*m+p] = ch[p&1?y:x];
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) putchar(s[i*m+j]);
        puts("");
    }
}