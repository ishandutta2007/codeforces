#include <cstdio>

/* Submit through luogu */

using namespace std;

#define MOD 998244353
#define mul(a, b) (((long long)(a) * (long long)(b)) % MOD)
const int size = 65536;

struct Poly {
    int coeff[65536];
    bool transformed;
    int trans[65536];
};

int rev[65536];

Poly* zero_poly()
{
    Poly* res = new Poly; res->transformed = false;
    for (int i = 0; i < size; i++) res->coeff[i] = 0;
    return res;
}

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

void NTT(int* poly, int op)
{
    for (int i = 0; i < size; i++) {
        if (i < rev[i]) {
            int tmp = poly[i]; poly[i] = poly[rev[i]]; poly[rev[i]] = tmp;
        }
    }
    for (int interval = 2; interval <= size; interval <<= 1) {
        int half = interval >> 1;
        int change = fpow(3, (MOD - 1) / interval);
        if (op == -1) change = fpow(change, MOD - 2);
        for (int start = 0; start < size; start += interval) {
            int cur = 1;
            for (int i = start; i < start + half; i++) {
                int tmp = mul(cur, poly[i + half]);
                poly[i + half] = poly[i] - tmp;
                if (poly[i + half] < 0) poly[i + half] += MOD;
                poly[i] = poly[i] + tmp;
                if (poly[i] >= MOD) poly[i] -= MOD;
                cur = mul(cur, change);
            }
        }
    }
    if (op == -1) {
        int inv = fpow(size, MOD - 2);
        for (int i = 0; i < size; i++) poly[i] = mul(poly[i], inv);
    }
}

bool is_last_mul = false;

Poly* multiply(Poly* a, Poly* b)
{
    /*Poly* na = zero_poly(); Poly* nb = zero_poly();
    for (int i = 0; i < size / 2; i++) {
        na->coeff[i] = a->coeff[i];
        nb->coeff[i] = b->coeff[i];
    }
    NTT(na->coeff, 1);
    NTT(nb->coeff, 1);*/

    if (!a->transformed) {
        for (int i = 0; i < size / 2; i++) {
            a->trans[i] = a->coeff[i];
        }
        for (int i = size / 2; i < size; i++) a->trans[i] = 0;
        NTT(a->trans, 1);
        a->transformed = true;
    }

    if (!b->transformed) {
        for (int i = 0; i < size / 2; i++) {
            b->trans[i] = b->coeff[i];
        }
        for (int i = size / 2; i < size; i++) b->trans[i] = 0;
        NTT(b->trans, 1);
        b->transformed = true;
    }

    Poly* ans = new Poly; ans->transformed = true;
    for (int i = 0; i < size; i++)
        ans->coeff[i] = ans->trans[i] = mul(a->trans[i], b->trans[i]);
    NTT(ans->coeff, -1);
    return ans;
}

Poly* add(Poly* a, Poly* b)
{
    Poly* ans = new Poly; ans->transformed = false;
    for (int i = 0; i < size; i++) {
        ans->coeff[i] = a->coeff[i] + b->coeff[i];
        if (ans->coeff[i] >= MOD) ans->coeff[i] -= MOD;
    }
    delete a; delete b;
    return ans;
}

struct Matrix {
    Poly* a[2][2];
};

Matrix operator*(Matrix a, Matrix b)
{
    Matrix ans;
    ans.a[0][0] = add(multiply(a.a[0][0], b.a[0][0]), multiply(a.a[0][1], b.a[1][0]));
    if (is_last_mul) return ans;
    ans.a[0][1] = add(multiply(a.a[0][0], b.a[0][1]), multiply(a.a[0][1], b.a[1][1]));
    ans.a[1][0] = add(multiply(a.a[1][0], b.a[0][0]), multiply(a.a[1][1], b.a[1][0]));
    ans.a[1][1] = add(multiply(a.a[1][0], b.a[0][1]), multiply(a.a[1][1], b.a[1][1]));
    return ans;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1) {
        printf("1 ");
        for (int i = 2; i <= k; i++) printf("0 ");
        return 0;
    }
    //n--;
    for (int i = 1; i < size; i++) {
        rev[i] = (i & 1) ? (size>>1) | rev[i^1] : rev[i>>1]>>1;
    }
    Matrix ans;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans.a[i][j] = zero_poly();
            if (i==j) ans.a[i][j]->coeff[0] = 1;
        }
    }
    Matrix trans;
    trans.a[0][0] = zero_poly();
    trans.a[0][0]->coeff[0] = trans.a[0][0]->coeff[1] = 1;
    trans.a[0][1] = zero_poly();
    trans.a[0][1]->coeff[0] = 1;
    trans.a[1][0] = zero_poly();
    trans.a[1][0]->coeff[1] = 1;
    trans.a[1][1] = zero_poly();
    while (n) {
        if (n == 1) is_last_mul = true;
        if (n & 1) ans = ans * trans;
        if (n > 1) trans = trans * trans;
        n >>= 1;
    }
    for (int i = 1; i <= k; i++) {
        printf("%d ", ans.a[0][0]->coeff[i]);
    }
    return 0;
}