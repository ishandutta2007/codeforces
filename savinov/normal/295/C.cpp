#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
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
int clock0 = clock();
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 4e-5; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 2e9; typedef complex<ld> cbase; inline void fft (vector<cbase> &a, bool invert) {int n = (int)a.size(); for (int i = 1, j = 0; i < n; ++i) {int bit = n >> 1; for (; j >= bit; bit >>= 1) j -= bit; j += bit; if (i < j) swap(a[i], a[j]);} for (int len = 2; len <= n; len <<= 1) {ld ang = 2 * PI / len * (invert ? -1 : 1); cbase wlen(cos(ang), sin(ang)); for (int i = 0; i < n; i += len) {cbase w(1); for (int j=0; j < len / 2; ++j) {cbase u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen;}}} if (invert) for (int i = 0; i < n; ++i) a[i] /= n;} inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} struct lnum {vector <int> a; int base; lnum(int num = 0, int base = 1000000000):base(base) {if (!num) a.resize(1); while(num) {a.pb(num % base); num /= base;}} inline int len() const {return a.size();} lnum & operator=(const lnum &l) {if (this != &l) {a = l.a; base = l.base;} return *this;} inline friend lnum operator+(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int ln = l.len(), rn = r.len(); int n = max(ln, rn); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = o; if (i < ln) s += l.a[i]; if (i < rn) s += r.a[i]; o = s >= base; if (o) s -= base; ret.a[i] = s;} if (o) ret.a.push_back(1); return ret;} inline friend lnum operator-(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int n = l.len(); int rn = r.len(); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = l.a[i] - o; if (i < rn) s -= r.a[i]; o = s < 0; if (o) s += base; ret.a[i] = s;} if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator*(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; if (l.len() * r.len() > 1000000) {vector<cbase> fa (l.a.begin(), l.a.end()), fb (r.a.begin(), r.a.end()); int n = 1; while (n < max (l.len(), r.len())) n <<= 1; n <<= 1; fa.resize (n), fb.resize (n); fft (fa, false), fft (fb, false); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft (fa, true); ret.a.resize(n); for (int i = 0; i < n; ++i) ret.a[i] = int (fa[i].real() + 0.5); int carry = 0; for (int i=0; i < n; ++i) {ret.a[i] += carry; carry = ret.a[i] / base; ret.a[i] %= base;}} else {ret.a.resize(l.len() + r.len()); for (int i = 0; i < l.len(); ++i) for (int j = 0, carry = 0; j < r.len() || carry; ++j) {long long cur = ret.a[i + j] + (ll)l.a[i] * (j < r.len() ? r.a[j] : 0) + carry; ret.a[i + j] = cur % base; carry = cur / base;}} while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator/(const lnum &l, const int &r) {lnum ret(0, l.base); ret.a.resize(l.len()); int carry = 0; for(int i = l.len() - 1; i >= 0; --i) {long long cur = l.a[i] + (ll)carry * l.base; ret.a[i] = cur / r; carry = cur % r;} while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back(); return ret;}  inline friend bool operator<(const lnum &l, const lnum &r) {if (l.len() < r.len()) return true; if (l.len() > r.len()) return false; int n = l.len(); for(int i = n - 1; i >= 0; --i) {if (l.a[i] < r.a[i]) return true; if (l.a[i] > r.a[i]) return false;} return false;} inline friend bool operator>(const lnum &l, const lnum &r) {return r < l;} inline friend bool operator==(const lnum &l, const lnum &r) {if (l.len() != r.len()) return false; int n = l.len(); for(int i = n - 1; i; --i) {if (l.a[i] != r.a[i]) return false;} return true;} inline friend bool operator!=(const lnum &l, const lnum &r) {return !(l == r);} inline void print() {if (base == 1000000000) {printf("%d", a.back()); for(int i = a.size() - 2; i >=0; --i) printf("%09d", a[i]);} else {for(int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);}}};

struct state
{
    int a, b, c;
};


int main()
{
    int mod = 1000000007;
    int bin[51][51];
    clr(bin);
    For(i, 0, 50)
    {
        bin[i][0] = 1;
        For(j, 1, i)
            bin[i][j] = (bin[i - 1][j - 1] + bin[i - 1][j]) % mod;
    }
    in(n); in(k);
    k /= 50;
    int cnt[2];
    clr(cnt);

    forn(i, n)
        cnt[nxt() / 50 - 1]++;
    int d[cnt[0] + 1][cnt[1] + 1][2];
    clr(d);
    ll num[cnt[0] + 1][cnt[1] + 1][2];
    char used[cnt[0] + 1][cnt[1] + 1][2];
    clr(num);
    clr(used);
    num[cnt[0]][cnt[1]][0] = 1;
    used[cnt[0]][cnt[1]][0] = 1;
    state s{cnt[0], cnt[1], 0};
    queue <state> q;
    q.push(s);
    while(!q.empty())
    {
        state cur = q.front();
        q.pop();
        if (!cur.a && !cur.b && cur.c)
        {
            cout << d[0][0][1] << endl;
            cout << num[0][0][1] << endl;
            return 0;
        }
        if (cur.c)
        {
            forn(i, cnt[0] - cur.a + 1)
                forn(j, cnt[1] - cur.b + 1)
                {
                    if (!i && !j) continue;
                    if (i + 2 * j <= k)
                    {
                        if (!used[cur.a + i][cur.b + j][0])
                        {
                            d[cur.a + i][cur.b + j][0] = d[cur.a][cur.b][1] + 1;
                            used[cur.a + i][cur.b + j][0] = 1;
                            q.push(state{cur.a + i, cur.b + j, 0});
                        }
                        if (d[cur.a + i][cur.b + j][0] == d[cur.a][cur.b][1] + 1)
                        {
                            num[cur.a + i][cur.b + j][0] = (num[cur.a + i][cur.b + j][0] + num[cur.a][cur.b][1] * bin[cnt[0] - cur.a][i] % mod * bin[cnt[1] - cur.b][j] % mod) % mod;
                        }
                    }
                }
        }
        else
        {
            forn(i, cur.a + 1)
                forn(j, cur.b + 1)
                {
                    if (!i && !j) continue;
                    if (i + 2 * j <= k)
                    {
                        if (!used[cur.a - i][cur.b - j][1])
                        {
                            d[cur.a - i][cur.b - j][1] = d[cur.a][cur.b][0] + 1;
                            used[cur.a - i][cur.b - j][1] = 1;
                            q.push(state{cur.a - i, cur.b - j, 1});
                        }
                        if (d[cur.a - i][cur.b - j][1] == d[cur.a][cur.b][0] + 1)
                        {
                            num[cur.a - i][cur.b - j][1] = (num[cur.a - i][cur.b - j][1] + num[cur.a][cur.b][0] * bin[cur.a][i] % mod * bin[cur.b][j] % mod) % mod;
                        }
                    }
                }
        }
    }
    puts("-1");
    puts("0");
    return 0;
}