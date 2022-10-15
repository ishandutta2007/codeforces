#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

template<int r, int c, class T> struct Matrix {
    T a[r+1][c+1];
    Matrix() {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                a[i][j] = 0;
            }
        }
    }
};

template<int N, class T>
void matrix_invert(Matrix<N, N, T>& orig, int siz = N)
{
    Matrix<N, 2 * N, T> mat;
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j <= siz; j++) {
            mat.a[i][j] = orig.a[i][j];
        }
    }
    for (int i = 1; i <= siz; i++) {
        mat.a[i][siz+i] = 1;
    }
    for (int i = 1; i <= siz; i++) {
        int bestrow = i;
        for (int j = i + 1; j <= siz; j++) {
            if (mat.a[j][i] > mat.a[bestrow][i]) bestrow = j;
        }
        if (bestrow != i) {
            for (int j = 1; j <= 2 * siz; j++) swap(mat.a[i][j], mat.a[bestrow][j]);
        }
        for (int j = i + 1; j <= siz; j++) {
            T mult_by = mat.a[j][i] / mat.a[i][i];
            for (int k = 1; k <= 2 * siz; k++) {
                mat.a[j][k] = mat.a[j][k] - mult_by * mat.a[i][k];
            }
        }
        for (int j = 2 * siz; j >= i; j--) {
            mat.a[i][j] = mat.a[i][j] / mat.a[i][i];
        }
    }
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j < i; j++) {
            T mult_by = mat.a[j][i];
            for (int k = 1; k <= 2 * siz; k++) {
                mat.a[j][k] = mat.a[j][k] - mult_by * mat.a[i][k];
            }
        }
    }
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j <= siz; j++) {
            orig.a[i][j] = mat.a[i][siz+j];
        }
    }
}

int mod;

struct mi {
    int val;
    mi() {
        val = 0;
    }
    mi(int a) {
        val = a % mod;
    }
};

mi operator "" _m(unsigned long long x) {
    mi res = x; return res;
}

mi operator+(mi a, mi b)
{
    mi ans;
    ll val = (ll)(a.val) + (ll)(b.val);
    if (val >= mod) val -= mod;
    ans.val = val; return ans;
}

mi operator-(mi a, mi b)
{
    mi ans;
    ans.val = a.val - b.val;
    if (ans.val < 0) ans.val += mod;
    return ans;
}

mi operator*(mi a, mi b)
{
    mi ans;
    ans.val = ((ll)(a.val) * (ll)(b.val)) % (ll)mod;
    return ans;
}

mi fpow(mi base, int exponent)
{
    mi ans = 1_m;
    mi cur = base;
    while (exponent) {
        if (exponent & 1) ans = ans * cur;
        cur = cur * cur; exponent >>= 1;
    }
    return ans;
}

// PRIME MOD ONLY!
mi operator/(mi a, mi b)
{
#ifndef ONLINE_JUDGE
    if (b.val == 0) {
        fprintf(stderr, "Division by zero :(\n"); abort();
    }
#endif
    return a * fpow(b, mod - 2);
}

bool operator>(mi a, mi b)
{
    return a.val > b.val; // for matrix_invert
}

Matrix<11, 11, mi> mat;

int d;

mi C[15][15];
mi curseq[5005];

int add(int x, int y, int out)
{
    printf("+ %d %d %d\n", x, y, out);
    curseq[out] = curseq[x] + curseq[y];
    return out;
}

int pwr(int x, int out)
{
    printf("^ %d %d\n", x, out);
    curseq[out] = fpow(curseq[x], d);
    return out;
}

int nxt = 100;

int mul_const(int x, mi mval)
{
    //printf("multiply %d by %d\n", curseq[x].val, mval.val);
    int val = mval.val;
    if (val == 0) val = mod;
    if (val == 1) return x;
    vector<int> seq; seq.push_back(x);
    for (int i = 1; i <= 30; i++) {
        add(seq.back(), seq.back(), nxt);
        seq.push_back(nxt); nxt++;
    }
    int pos = 0;
    for (int i = 30; i >= 0; i--) {
        if (!(val & (1 << i))) continue;
        if (!pos) {
            pos = seq[i];
        } else {
            add(pos, seq[i], pos);
        }
    }
    //printf("result %d\n", curseq[pos].val);
    return pos;
}

int square(int x)
{
    vector<int> seq; seq.push_back(x);
    for (int i = 1; i <= d; i++) {
        add(seq.back(), 3, nxt); seq.push_back(nxt);
        nxt++;
    }
    for (int i = 0; i <= d; i++) {
        int pwrloc = pwr(seq[i], nxt);
        nxt++;
        seq[i] = mul_const(pwrloc, mat.a[3][i+1]);
    }
    //for (int i = 0; i <= d; i++) printf("%d ", print_val[i]);
    //printf("\n");
    for (int i = 1; i <= d; i++) {
        add(seq[i], seq[i-1], seq[i]);
        //printf("getting %d\n", curseq[seq[i]].val);
    }
    //printf("%d result %d\n", sqval, curseq[seq[d]].val);
    return seq[d];
}

int main()
{
    for (int i = 3; i <= 5000; i++) curseq[i].val = 1;
    scanf("%d%d", &d, &mod);
    for (int i = 0; i <= 12; i++) {
        C[i][0] = 1_m;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    mat.a[1][d+1] = 1_m;
    for (int i = 2; i <= d + 1; i++) {
        for (int j = 1; j <= d + 1; j++) {
            // (x + i - 1)^d, coeff of x^(j-1)
            mat.a[i][j] = C[d][j-1] * fpow(i - 1, d - j + 1);
        }
    }
    /*for (int i = 1; i <= d + 1; i++) {
        for (int j = 1; j <= d + 1; j++) {
            printf("%d ", mat.a[i][j].val);
        }
        printf("\n");
    }*/
    matrix_invert(mat, d + 1);
    /*for (int i = 1; i <= d + 1; i++) {
        for (int j = 1; j <= d + 1; j++) {
            printf("%d ", mat.a[i][j].val);
        }
        printf("\n");
    }*/
    int a = mul_const(add(1, 2, 4), 1_m / 2_m);
    int asq = square(a);
    int bsq = square(add(1, mul_const(a, mod - 1), 5));
    add(asq, mul_const(bsq, mod - 1), 6);
    printf("f 6\n");
    //printf("%d\n", curseq[6].val);
    return 0;
}