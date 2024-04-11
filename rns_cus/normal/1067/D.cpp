#include <bits/stdc++.h>

typedef long long int int64;
typedef double ld;
struct quest {
    ld prob;
    ld w;
    ld prod;
    ld get(ld x) {
        return prob * x + prod;
    }
} q[100003];
int64 t;
int n;
double maxw;
bool cmp1(const quest &a, const quest &b) {
    return a.prob < b.prob || (a.prob == b.prob && a.w < b.w);
}
bool cmp(ld k1, ld b1, ld k2, ld b2, ld k3, ld b3) {
    return (k2 - k1) * (b3 - b1) - (k3 - k1) * (b2 - b1) < 0;
}
struct matrix {
    double val[3][3];
    matrix operator *(const matrix &y) const {
        matrix ans;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ld v = 0;
                for (int k = 0; k < 3; ++k)
                    v += val[i][k] * y.val[k][j];
                ans.val[i][j] = v;
            }
        }
        return ans;
    }
    ld getdp(ld dpn, ld n) const {
        return val[0][0] * dpn + val[1][0] * n + val[2][0];
    }
};
matrix e;
matrix getm(const quest &q) {
    matrix ans;
    /*
    ans.val[0][1] = ans.val[0][2] = ans.val[1][2] = 0;
    ans.val[1][1] = ans.val[2][2] = ans.val[2][1] = 1;
    ans.val[0][0] = 1 - q.prob;
    ans.val[1][0] = q.prob * maxw;
    ans.val[2][0] = q.prob * q.w;
    */
    ans.val[0][0] = 1 - q.prob; ans.val[1][0] = q.prob * maxw; ans.val[2][0] = q.prod;
    ans.val[0][1] = 0; ans.val[1][1] = 1; ans.val[2][1] = 1;
    ans.val[0][2] = 0; ans.val[1][2] = 0; ans.val[2][2] = 1;
    return ans;
}
int main() {
    memset(&e, 0, sizeof(e));
    for (int i = 0; i < 3; ++i) e.val[i][i] = 1;
    scanf("%d%I64d", &n, &t);
    for (int i = 0; i < n; ++i) {
        ld a, b, p;
        scanf("%lf%lf%lf", &a, &b, &p);
        if (b * p > maxw)
            maxw = b * p;
        q[i].prob = p; q[i].w = a; q[i].prod = p * a;
    }
    std::sort(q, q + n, cmp1);
    int j = 1;
    for (int i = 1; i < n; ++i) {
        while (j >= 2 && !cmp(q[j - 2].prob, q[j - 2].prod, q[j - 1].prob, q[j - 1].prod, q[i].prob, q[i].prod)) --j;
        while (j >= 1 && q[j - 1].prob >= q[i].prob) --j;
        q[j++] = q[i];
    }
    int64 curt = 0;
    ld curdp = 0;
    for (int i = 0; i < j; ++i) {
        matrix temp[34];
        matrix temp2[34];
        temp[0] = e;
        for (int k = 1; k <= 33; ++k) {
            if ((curt + (1LL << k)) > t) break;
            temp[k] = temp[k - 1] * temp[k - 1] * getm(q[i]);
        }
        for (int k = 33; k >= 0; --k) {
            int64 next = curt + (1LL << k) - 1;
            if (next + 1 > t) continue;
            ld nexdp = temp[k].getdp(curdp, curt);
            ld x = next * maxw - nexdp;
            if (i == j - 1 || q[i].get(x) > q[i + 1].get(x)) {
                //curdp = temp[k].getdp(curdp, curt);
                curdp = nexdp + q[i].get(x);
                curt = next + 1;
            }
        }
    }
    printf("%f\n", curdp);
}
//hello