#include <bits/stdc++.h>

const int maxn = 1000*1000+5, maxm = 105;
const long long Mod = 1000*1000*1000+7;

struct Mat {
    long long m[maxm][maxm];
    Mat() {
        for (int y = 0; y < maxm; y++) for (int x = 0; x < maxm; x++) m[y][x] = 0;
    }
    void iden() {
        for (int i = 0; i < maxm; i++) m[i][i] = 1;
    }
};

Mat operator*(const Mat &a, const Mat &b) {
    Mat m;
    for (int y = 0; y < maxm; y++) for (int x = 0; x < maxm; x++) for (int k = 0; k < maxm; k++) {
        m.m[y][x] = (m.m[y][x] + a.m[y][k] * b.m[k][x]) % Mod;
    }
    return m;
}

int n, l, m, c[maxn];
long long start[maxm], ways[maxm];
Mat iden;

Mat sqr(const Mat &mat) {
    return mat * mat;
}

Mat modexp(const Mat &mat, long long e) {
    if (e == 0) return iden;
    else if (e%2 == 1) return sqr(modexp(mat, e/2)) * mat;
    else return sqr(modexp(mat, e/2));
}

int main() {
    iden.iden();

    scanf("%d%d%d", &n, &l, &m);
    for (int i = 0; i < n; i++) {
        int s;
        scanf("%d", &s);
        start[s % m]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", c+i);
        ways[c[i] % m]++;
    }

    Mat mat;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            mat.m[i][(i+j) % m] = ways[j];
            //printf("mat[%d][%d] = %lld\n", i, (i+j)%m, ways[j]);
        }
    }
    mat = modexp(mat, l-2);

    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("mat[%d][%d] = %lld\n", i, (i+j)%m, ways[j]);
        }

    }*/

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int e;
        scanf("%d", &e);
        int need = (m + m - e%m - c[i]%m) % m;
        for (int st = 0; st < m; st++) {
            ans = (ans + (start[st] * mat.m[st][need])) % Mod;
        }
    }

    printf("%lld\n", ans);
}