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
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 5e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; typedef complex<ld> cbase; inline void fft (vector<cbase> &a, bool invert) {int n = (int)a.size(); for (int i = 1, j = 0; i < n; ++i) {int bit = n >> 1; for (; j >= bit; bit >>= 1) j -= bit; j += bit; if (i < j) swap(a[i], a[j]);} for (int len = 2; len <= n; len <<= 1) {ld ang = 2 * PI / len * (invert ? -1 : 1); cbase wlen(cos(ang), sin(ang)); for (int i = 0; i < n; i += len) {cbase w(1); for (int j=0; j < len / 2; ++j) {cbase u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen;}}} if (invert) for (int i = 0; i < n; ++i) a[i] /= n;} inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(ll a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} struct lnum {vector <int> a; int base; lnum(int num = 0, int base = 1000000000):base(base) {if (!num) a.resize(1); while(num) {a.pb(num % base); num /= base;}} inline int len() const {return a.size();} lnum & operator=(const lnum &l) {if (this != &l) {a = l.a; base = l.base;} return *this;} inline friend lnum operator+(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int ln = l.len(), rn = r.len(); int n = max(ln, rn); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = o; if (i < ln) s += l.a[i]; if (i < rn) s += r.a[i]; o = s >= base; if (o) s -= base; ret.a[i] = s;} if (o) ret.a.push_back(1); return ret;} inline friend lnum operator-(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int n = l.len(); int rn = r.len(); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = l.a[i] - o; if (i < rn) s -= r.a[i]; o = s < 0; if (o) s += base; ret.a[i] = s;} if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator*(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; if (l.len() * r.len() > 1000000) {vector<cbase> fa (l.a.begin(), l.a.end()), fb (r.a.begin(), r.a.end()); int n = 1; while (n < max (l.len(), r.len())) n <<= 1; n <<= 1; fa.resize (n), fb.resize (n); fft (fa, false), fft (fb, false); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft (fa, true); ret.a.resize(n); for (int i = 0; i < n; ++i) ret.a[i] = int (fa[i].real() + 0.5); int carry = 0; for (int i=0; i < n; ++i) {ret.a[i] += carry; carry = ret.a[i] / base; ret.a[i] %= base;}} else {ret.a.resize(l.len() + r.len()); for (int i = 0; i < l.len(); ++i) for (int j = 0, carry = 0; j < r.len() || carry; ++j) {long long cur = ret.a[i + j] + (ll)l.a[i] * (j < r.len() ? r.a[j] : 0) + carry; ret.a[i + j] = cur % base; carry = cur / base;}} while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator/(const lnum &l, const int &r) {lnum ret(0, l.base); ret.a.resize(l.len()); int carry = 0; for(int i = l.len() - 1; i >= 0; --i) {long long cur = l.a[i] + (ll)carry * l.base; ret.a[i] = cur / r; carry = cur % r;} while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back(); return ret;}  inline friend bool operator<(const lnum &l, const lnum &r) {if (l.len() < r.len()) return true; if (l.len() > r.len()) return false; int n = l.len(); for(int i = n - 1; i >= 0; --i) {if (l.a[i] < r.a[i]) return true; if (l.a[i] > r.a[i]) return false;} return false;} inline friend bool operator>(const lnum &l, const lnum &r) {return r < l;} inline friend bool operator==(const lnum &l, const lnum &r) {if (l.len() != r.len()) return false; int n = l.len(); for(int i = n - 1; i; --i) {if (l.a[i] != r.a[i]) return false;} return true;} inline friend bool operator!=(const lnum &l, const lnum &r) {return !(l == r);} inline void print() {if (base == 1000000000) {printf("%d", a.back()); for(int i = a.size() - 2; i >=0; --i) printf("%09d", a[i]);} else {for(int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);}}};

const int N = 70100;

struct Bitset
{
    uint32_t * data;
    int n;
    Bitset(const int _n)
    {
        n = (_n + 31) >> 5;
        data = new uint32_t[n];
        memset(data, 0, 4 * n);
    }

    Bitset & operator=(const Bitset & r)
    {
        if (this == &r)
            return *this;
        n = r.n;
        memcpy(data, r.data, n * 4);
        return *this;
    }

    void set(int pos)
    {
        if (pos >= 0 && (pos >> 5) < n)
            data[pos >> 5] |= 1 << (pos & 31);
    }

    bool test(int pos)
    {
        if (pos >= 0 && (pos >> 5) < n)
            return (data[pos >> 5] >> (pos & 31)) & 1;
        else
            return false;
    }

    void operator|=(const Bitset & r)
    {
        for(int i = 0; i < n; ++i)
            data[i] |= r.data[i];
    }
    void operator&=(const Bitset & r)
    {
        for(int i = 0; i < n; ++i)
            data[i] &= r.data[i];
    }
    void operator^=(const Bitset & r)
    {
        for(int i = 0; i < n; ++i)
            data[i] ^= r.data[i];
    }
    void operator<<=(int shift)
    {
        int delta = shift >> 5;
        if (delta >= n)
        {
            memset(data, 0, n * 4);
            return;
        }
        shift &= 31;
        if (shift == 0)
        {
            memmove(data + delta, data, (n - delta) * 4);
            memset(data, 0, delta * 4);
            return;
        }
        for(int i = n - 1; i >= delta + 1; --i)
            data[i] = (data[i - delta] << shift) | (data[i - delta - 1] >> (32 - shift));

        data[delta] = data[0] << shift;
        memset(data, 0, delta * 4);
    }
    void operator>>=(int shift)
    {
        int delta = shift >> 5;
        if (delta >= n)
        {
            memset(data, 0, n * 4);
            return;
        }
        shift &= 31;
        if (shift == 0)
        {
            memmove(data, data + delta, (n - delta) * 4);
            memset(data + n - delta, 0, delta * 4);
            return;
        }
        for(int i = 0; i < n - delta - 1; ++i)
            data[i] = (data[i + delta] >> shift) | (data[i + delta + 1] << (32 - shift));

        data[n - delta - 1] = data[n - 1] >> shift;
        memset(data + n - delta, 0, delta * 8);
    }

    int set_of_bits(int * res) const
    {
        int size = 0;
        for(int i = 0; i < n; ++i)
        {
            if (!data[i])
                continue;
            uint32_t temp = data[i];
            while(temp)
            {
                int pos = __builtin_ctz(temp);
                res[size++] = pos + (i << 5);
                temp ^= 1 << pos;
            }
        }
        return size;
    }
    inline void print()
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < 64; ++j)
                cout << ((data[i] >> j) & 1ull);
        }
        cout << endl;
    }
    ~Bitset()
    {
        delete data;
    }
};


typedef bitset<N> bset;

int main()
{
    //ios_base::sync_with_stdio(false);
    in(n); in(s);
    PII a[n];
    int rem[n];
    for(int i = 0; i < n; ++i)
    {
        a[i].x = nxt();
        rem[i] = a[i].x;
        a[i].y = i;
    }
    sort(a, a + n, greater<PII>());
    Bitset cur(s + 1), cur1(s + 1), temp(s + 1);
    if (a[0].x > s)
    {
        puts("-1");
        return 0;
    }
    cur.set(a[0].x);
    int first[s + 1];
    memset(first, 255, sizeof(first));
    first[a[0].x] = 0;
    int buffer[s + 32];
    for(int i = 1; i < n; ++i)
    {
        cur1 = cur;
        cur1 <<= a[i].x;
        temp = cur;
        cur |= cur1;
        temp ^= cur;
        //cur.print();
        int sz = temp.set_of_bits(buffer);
        for(int j = 0; j < sz && buffer[j] <= s; ++j)
            first[buffer[j]] = i;
        if (first[s] != -1)
            break;
    }
    if (first[s] == -1)
    {
        puts("-1");
        return 0;
    }
    char chosen[n];
    memset(chosen, 0, sizeof(chosen));
    while(s > 0)
    {
        chosen[first[s]] = 1;
        s -= a[first[s]].x;
    }
    int g[n];
    memset(g, 0, sizeof(g));
    for(int i = 1; i < n; ++i)
    {
        if (!chosen[i])
        {
            rem[a[i - 1].y] = rem[a[i - 1].y] - a[i].x;
            g[a[i - 1].y] = a[i].y + 1;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        //out(rem[i]);
        //putchar(' ');
        //printf("%d ", rem[i]);
        cout << rem[i] << " ";
        if (g[i])
        {
            //putchar('1');
            //putchar(' ');
            //out(g[i]);
            //printf("1 %d\n", g[i]);
            cout << "1 " << g[i] << endl;
        }
        else
        {
            cout << "0" << endl;
            //puts("0");
        }
    }
    return 0;
}