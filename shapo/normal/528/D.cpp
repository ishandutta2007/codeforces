#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <utility>
#include <tuple>
#include <complex>

using namespace std;

template< class T >
class MyComplex
{
    T re = 0.0, im = 0.0;
public:
    const T real() const
    {
        return re;
    }
    T &real()
    {
        return re;
    }
    const T imag() const
    {
        return im;
    }
    T &imag()
    {
        return im;
    }
public:
    MyComplex() : re(), im() {}
    template< class T1 >
    MyComplex(T1 re_ = 0.0, T1 im_ = 0.0) : re(re_), im(im_) {}
    template< class T1 >
    MyComplex(const MyComplex< T1 > &lhs) : re(lhs.re), im(lhs.im) {}
    template< class T1 >
    MyComplex operator=(const MyComplex< T1 > &lhs) 
    {
        re = lhs.re;
        im = lhs.im;
        return *this;
    }
    template< class T1, class T2 >
    friend MyComplex< T1 > operator+(const MyComplex< T1 > &a, const MyComplex< T2 > &b)
    {
        return MyComplex< T1 >(a.re + b.re, a.im + b.im);
    }
    template< class T1, class T2 >
    friend MyComplex< T1 > operator-(const MyComplex< T1 > &a, const MyComplex< T2 > &b)
    {
        return MyComplex< T1 >(a.re - b.re, a.im - b.im);
    }
    template< class T1, class T2 >
    friend MyComplex< T1 > operator*(const MyComplex< T1 > &a, const MyComplex< T2 > &b)
    {
        return MyComplex< T1 >(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
    }
    template< class U >
    MyComplex &operator+=(const MyComplex< U > &rhs)
    {
        re += rhs.re;
        im += rhs.im;
        return *this;
    }
    template< class U >
    MyComplex &operator*=(const MyComplex< U > &rhs)
    {
        T temp = re * rhs.re - im * rhs.im;
        im = re * rhs.im + im * rhs.re;
        re = temp;
        return *this;
    }
    template< class U >
    MyComplex &operator/=(const U &rhs)
    {
        re /= rhs;
        im /= rhs;
        return *this;
    }
    template< class T1  >
    friend ostream &operator<<(ostream &, const MyComplex< T1 >&);
};

template< class T >
ostream &
operator<<(ostream &out, const MyComplex< T > &val)
{
    return out << "(" << val.re << "," << val.im << ")";
}

#ifdef USE_STL_COMPLEX
typedef complex< double > cd;
#else
typedef MyComplex< double > cd;
#endif
typedef vector< cd > vcd;
typedef vector< int > vi;

const int MAXN = 270000;

double M_PI_ = acos(-1.);
const char dna[] = "AGCT";

char s[MAXN], t[MAXN];
int k;
int sbit[MAXN];
int tbit[MAXN];
int slen, tlen;
int old_pos[4];
int resbits[MAXN];
bool can_start[MAXN];
int tt[MAXN], ss[MAXN];
cd ta[MAXN];
cd roots[20];
int rev[MAXN];
int curk;

void
calc_rev(int n, int k)
{
    rev[0] = 0;
    int high1 = -1;
    for (int i = 1; i < n; ++i) {
        if ((i & (i - 1)) == 0) {
            high1++;
        }
        rev[i] = rev[i ^ (1 << high1)] | (1 << (k - high1 - 1));
    }
}

// fft using merge
void
fft(cd *as, int n)
{
    int k = 0;
    while ((1 << k) < n) {
        ++k;
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] > i) {
            swap(as[i], as[rev[i]]);
        }
    }

    double alpha = 2 * M_PI_ / n;
    roots[0] = cd(cos(alpha), sin(alpha));
    for (int i = 1; i < k; ++i) {
        roots[i] = roots[i - 1] * roots[i - 1];
    }
    for (int len = 1, it = k - 1; len < n; len <<= 1, --it) {
        cd mult1 = roots[it];
        for (int pdest = 0; pdest < n; pdest += len) {
            cd mult2 = cd(1., 0.);
            for (int i = 0; i < len; ++i, ++pdest) {
                cd val = mult2 * as[pdest + len];
                as[pdest + len] = as[pdest] - val;
                as[pdest] += val;
                mult2 *= mult1;
            }
        }
    }
}

void
multiply(int *a, int *b, int *c)
{
    for (int i = 0; i < slen; ++i) {
        ta[i] = cd(a[i], b[i]);
    }
    for (int i = slen; i < curk; ++i) {
        ta[i] = 0.;
    } 
    fft(ta, curk);
    for (int i = 0; i < curk; ++i) {
        ta[i] *= ta[i];
    }
    fft(ta, curk);
    reverse(ta + 1, ta + curk);
    // cerr << fixed << setprecision(4);
    for (int i = 0; i < slen; ++i) {
        double val = ta[i].imag() / (2. * curk);
        // cerr << val << ' ';
        c[i] = int(val + 0.5);
    }
    // cerr << endl;
}

int
main()
{
    scanf("%d%d%d %s %s", &slen, &tlen, &k, s, t);
    for (int i = 0; i < 4; ++i) {
        old_pos[i] = -k - 10;
    }
    memset(sbit, 0, sizeof(sbit));
    for (int i = 0; i < slen; ++i) {
        int j = find(dna, dna + 4, s[i]) - dna;
        old_pos[j] = i;
        for (int kk = 0; kk < 4; ++kk) {
            if (abs(old_pos[kk] - i) <= k) {
                sbit[i] |= 1 << kk;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        old_pos[i] = slen + tlen + k + 10;
    } 
    for (int i = slen - 1; i >= 0; --i) {
        int j = find(dna, dna + 4, s[i]) - dna;
        old_pos[j] = i;
        for (int kk = 0; kk < 4; ++kk) {
            if (abs(old_pos[kk] - i) <= k) {
                sbit[i] |= 1 << kk;
            }
        }
    }
    for (int i = 0; i < tlen; ++i) {
        int j = find(dna, dna + 4, t[i]) - dna;
        tbit[tlen - i - 1] = 1 << j;
    }
    fill(can_start, can_start + slen - tlen + 1, 1);
    int lg = 1;
    curk = 2;
    while (curk < slen) {
        curk *= 2;
        lg++;
    }
    calc_rev(curk, lg);
    for (int pos = 0; pos < 4; ++pos) {
        for (int i = 0; i < slen; ++i) {
            ss[i] = (sbit[i] >> pos) & 1;
        }
        int sum = 0;
        for (int i = 0; i < tlen; ++i) {
            tt[i] = (tbit[i] >> pos) & 1;
            sum += tt[i];
        }
        multiply(ss, tt, resbits); 
        for (int i = 0; i < slen - tlen + 1; ++i) {
            if (resbits[tlen + i - 1] != sum) {
                can_start[i] = false;
            }
        }
    }
    int res = accumulate(can_start, can_start + slen - tlen + 1, 0);
    printf("%d\n", res);
    return 0;
}