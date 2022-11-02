#include <bits/stdc++.h>

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

//#define double ld

long long mod = 1000000007;



typedef vector <long long> pt;

long long scal(const pt & a, const pt & b) {
    long long res = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        res += a[i] * b[i];
    }
    return res;
}

pt sub(const pt & a, const pt & b) {
    pt res(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
        res[i] = a[i] - b[i];
    }
    return res;
}

pt add(const pt & a, const pt & b) {
    pt res(a.size());
    for (int i = 0; i < (int)a.size(); ++i) {
        res[i] = a[i] + b[i];
    }
    return res;
}

pt vect(const pt & a, const pt & b) {
    pt res(a.size());

    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];

    return res;
}

long long len(long long x) {
    long long res = sqrt(x + 0.5);
    for (long long i = res - 1; i <= res + 1; ++i) {
        if (i * i == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //freopen("hot.in", "r", stdin);
    //freopen("hot.out", "w", stdout);
#endif
    
    vector <pt> p(8);
    vector <pt> z(8);
    vector <pair <pt, int> > so(8);
    int n = 8;
    for (int i = 0; i < n; ++i) {
        p[i].resize(3);
        for (int j = 0; j < 3; ++j) {
            p[i][j] = nxt();
        }
        z[i] = p[i];
        sort(all(z[i]));
        so[i] = mp(z[i], i);
    }

    sort(all(z));
    sort(all(so));

    for (int i = 0; i < n; ++i) {
        sort(all(p[i]));
        do {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                sort(all(p[j]));
                do {
                    for (int k = 0; k < n; ++k) {
                        if (i == k || j == k) continue;
                        sort(all(p[k]));
                        do {
                            pt u = sub(p[j], p[i]);
                            pt v = sub(p[k], p[i]);
                            if (scal(u, v) != 0) continue;
                            if (scal(u, u) != scal(v, v)) continue;
                            long long d = scal(u, u);
                            if (d == 0) continue;
                            long long l = len(d);

                            if (l <= 0) continue;
                            
                            vector <pt> need;
                            pt z = add(p[i], add(u, v));
                            pt q = vect(u, v);
                            if (q[0] % l != 0 || q[1] % l != 0 || q[2] % l != 0) continue;
                            for (long long & e : q) {
                                e /= l;
                            }
                            need.push_back(p[i]);
                            need.push_back(p[j]);
                            need.push_back(p[k]);
                            need.push_back(z);
                            need.push_back(add(p[i], q));
                            need.push_back(add(p[j], q));
                            need.push_back(add(p[k], q));
                            need.push_back(add(z, q));

                            vector <pt> tmp = need;

                            for (pt & e : tmp) {
                                sort(all(e));
                            }

                            vector <pair <pt, int> > pp(8);

                            for (int x = 0; x < 8; ++x) {
                                pp[x] = mp(tmp[x], x);
                            }

                            sort(all(pp));
                            char ok = true;
                            for (int x = 0; x < 8 && ok; ++x) {
                                if (pp[x].x != so[x].x) {
                                    ok = false;
                                }
                            }
                            if (ok) {
                                vector <pt> ans(8);
                                for (int x = 0; x < 8; ++x) {
                                    ans[so[x].y] = need[pp[x].y];
                                }
                                puts("YES");
                                for (int x = 0; x < 8; ++x) {
                                    cout << ans[x][0] << " " << ans[x][1] << " " << ans[x][2] << endl;
                                }
                                return 0;
                            }
                        } while(next_permutation(all(p[k])));
                    }
                } while(next_permutation(all(p[j])));
            }
        } while (next_permutation(all(p[i])));
    }

    puts("NO");
#ifdef LOCAL
    cout << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif
    return 0;
}