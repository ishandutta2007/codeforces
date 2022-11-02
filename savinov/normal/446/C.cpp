#ifdef LOCAL
    #include <iostream>
    #include <cstring>
    #include <cmath>
    #include <vector>
    #include <set>
    #include <map>
    #include <cstdio>
    #include <cmath>
    #include <iomanip>
    #include <sstream>
    #include <cassert>
#else
    #include <bits/stdc++.h>
#endif

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))
 
using namespace std;
 
template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

typedef vector <vector <long long> > matrix;

const long long mod = 1000000009;

const long long MANY = 7e18;

matrix operator*(const matrix & l, const matrix & r) {
    int n = l.size();

    matrix res(n, vector <long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] += l[i][k] * r[k][j];
                if (res[i][j] > MANY) {
                    res[i][j] %= mod;
                }
            }
            res[i][j] %= mod;
        }
    }
    return res;
}

const int N = 300000;

matrix p[N + 1];

long long S[4 * N];
long long A[4 * N];
long long B[4 * N];
long long a[N];

long long getS(long long a, long long b, int len) {
    return (p[len][2][0] * a + p[len][2][1] * b) % mod;
}

void add(int v, int tl, int tr, int l, int r, long long a, long long b) {
    if (l > r) {
        return;
    }

    if (tl == l && tr == r) {
        A[v] += a;
        if (A[v] >= mod) {
            A[v] -= mod;
        }
        B[v] += b;
        if (B[v] >= mod) {
            B[v] -= mod;
        }
        return;
    }
    int tm = (tl + tr) / 2;

    int len = max(0, min(tm, r) - l + 1);

    add(v + v, tl, tm, l, min(tm, r), a, b);

    long long aa = (p[len][0][0] * a + p[len][0][1] * b) % mod;
    long long bb = (p[len][1][0] * a + p[len][1][1] * b) % mod;

    add(v + v + 1, tm + 1, tr, max(tm + 1, l), r, aa, bb);

    S[v] = (S[v + v] + S[v + v + 1] + getS(A[v + v], B[v + v], tm - tl + 1) + getS(A[v + v + 1], B[v + v + 1], tr - tm)) % mod;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        S[v] = a[tl];
        return;
    } 
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    S[v] = (S[v + v] + S[v + v + 1]) % mod;
}

long long get(int v, int tl, int tr, int l, int r, long long a, long long b) {
    if (l > r) {
        return 0;
    }
    a %= mod, b %= mod;
    if (tl == l && tr == r) {
        return (S[v] + getS(a, b, tr - tl + 1)) % mod;
    }

    int tm = (tl + tr) / 2;

    int len = tm - tl + 1;

    long long res = 0;

    res += get(v + v, tl, tm, l, min(tm, r), a + A[v + v], b + B[v + v]);

    long long aa = (p[len][0][0] * a + p[len][0][1] * b) % mod;
    long long bb = (p[len][1][0] * a + p[len][1][1] * b) % mod;

    res += get(v + v + 1, tm + 1, tr, max(tm + 1, l), r, aa + A[v + v + 1], bb + B[v + v + 1]);

    res %= mod;
    return res;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    in(n); in(q);

    matrix m(3, vector <long long>(3));

    m[0][0] = 1, m[0][1] = 1;
    m[1][0] = 1;
    m[2][0] = 1, m[2][2] = 1;


    p[0] = matrix(3, vector <long long>(3));

    p[0][0][0] = 1, p[0][1][1] = 1, p[0][2][2] = 1;

    for (int i = 1; i <= n; ++i) {
        p[i] = m * p[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }

    build(1, 0, n - 1);

    while (q--) {
        in(t);
        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt() - 1;

            add(1, 0, n - 1, l, r, 1, 0);
        } else {
            int l = nxt() - 1;
            int r = nxt() - 1;
            int res = get(1, 0, n - 1, l, r, A[1], B[1]);
            printf("%d\n", res);
        }
        /*for (int i = 0; i < n; ++i) {
            cout << get(1, 0, n - 1, i, i, A[1], B[1]) << " ";
        }
        cout << endl;*/
    }
    return 0;
}