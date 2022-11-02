#include <bits/stdc++.h>
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=int(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 1e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; typedef complex<ld> cbase; inline void fft (vector<cbase> &a, bool invert) {int n = (int)a.size(); for (int i = 1, j = 0; i < n; ++i) {int bit = n >> 1; for (; j >= bit; bit >>= 1) j -= bit; j += bit; if (i < j) swap(a[i], a[j]);} for (int len = 2; len <= n; len <<= 1) {ld ang = 2 * PI / len * (invert ? -1 : 1); cbase wlen(cos(ang), sin(ang)); for (int i = 0; i < n; i += len) {cbase w(1); for (int j=0; j < len / 2; ++j) {cbase u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen;}}} if (invert) for (int i = 0; i < n; ++i) a[i] /= n;} inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(ll a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} struct lnum {vector <int> a; int base; lnum(int num = 0, int base = 1000000000):base(base) {if (!num) a.resize(1); while(num) {a.pb(num % base); num /= base;}} inline int len() const {return a.size();} lnum & operator=(const lnum &l) {if (this != &l) {a = l.a; base = l.base;} return *this;} inline friend lnum operator+(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int ln = l.len(), rn = r.len(); int n = max(ln, rn); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = o; if (i < ln) s += l.a[i]; if (i < rn) s += r.a[i]; o = s >= base; if (o) s -= base; ret.a[i] = s;} if (o) ret.a.push_back(1); return ret;} inline friend lnum operator-(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int n = l.len(); int rn = r.len(); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = l.a[i] - o; if (i < rn) s -= r.a[i]; o = s < 0; if (o) s += base; ret.a[i] = s;} if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator*(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; if (l.len() * r.len() > 1000000) {vector<cbase> fa (l.a.begin(), l.a.end()), fb (r.a.begin(), r.a.end()); int n = 1; while (n < max (l.len(), r.len())) n <<= 1; n <<= 1; fa.resize (n), fb.resize (n); fft (fa, false), fft (fb, false); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft (fa, true); ret.a.resize(n); for (int i = 0; i < n; ++i) ret.a[i] = int (fa[i].real() + 0.5); int carry = 0; for (int i=0; i < n; ++i) {ret.a[i] += carry; carry = ret.a[i] / base; ret.a[i] %= base;}} else {ret.a.resize(l.len() + r.len()); for (int i = 0; i < l.len(); ++i) for (int j = 0, carry = 0; j < r.len() || carry; ++j) {long long cur = ret.a[i + j] + (ll)l.a[i] * (j < r.len() ? r.a[j] : 0) + carry; ret.a[i + j] = cur % base; carry = cur / base;}} while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator/(const lnum &l, const int &r) {lnum ret(0, l.base); ret.a.resize(l.len()); int carry = 0; for(int i = l.len() - 1; i >= 0; --i) {long long cur = l.a[i] + (ll)carry * l.base; ret.a[i] = cur / r; carry = cur % r;} while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back(); return ret;}  inline friend bool operator<(const lnum &l, const lnum &r) {if (l.len() < r.len()) return true; if (l.len() > r.len()) return false; int n = l.len(); for(int i = n - 1; i >= 0; --i) {if (l.a[i] < r.a[i]) return true; if (l.a[i] > r.a[i]) return false;} return false;} inline friend bool operator>(const lnum &l, const lnum &r) {return r < l;} inline friend bool operator==(const lnum &l, const lnum &r) {if (l.len() != r.len()) return false; int n = l.len(); for(int i = n - 1; i; --i) {if (l.a[i] != r.a[i]) return false;} return true;} inline friend bool operator!=(const lnum &l, const lnum &r) {return !(l == r);} inline void print() {if (base == 1000000000) {printf("%d", a.back()); for(int i = a.size() - 2; i >=0; --i) printf("%09d", a[i]);} else {for(int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);}}};

struct IO
{
    char * buf_i, * buf_o;
    FILE * I, * O;
    int i, o;
    int sz_i, sz_o;
    char t[20];
    IO(int s_i = 3000000, int s_o = 3000000) : I(stdin), O(stdout), i(0), o(0), sz_i(s_i), sz_o(s_o)
    {
        buf_i = (char *)malloc(s_i * sizeof(char));
        buf_o = (char *)malloc(s_o * sizeof(char));
        sz_i = fread(buf_i, sizeof(char), sz_i, I);
    }
    ~IO() { fwrite(buf_o, sizeof(char), o, O);}
    inline int readInt()
    {
        while(!isdigit(buf_i[i]) && buf_i[i] != '-') ++i;
        char neg = buf_i[i] == '-';
        if (neg) ++i;
        int res = 0;
        while(isdigit(buf_i[i]))
            res = 10 * res + buf_i[i++] - '0';
        if (neg) res = -res;
        return res;
    }
    inline int readLong()
    {
        while(!isdigit(buf_i[i]) && buf_i[i] != '-') ++i;
        char neg = buf_i[i] == '-';
        if (neg) ++i;
        long long res = 0;
        while(i < sz_i && isdigit(buf_i[i]))
            res = 10 * res + buf_i[i++] - '0';
        if (neg) res = -res;
        return res;
    }
    inline char readChar()
    {
        return buf_i[i++];
    }
    inline string readString()
    {
        while(buf_i[i] == ' ' || buf_i[i] == '\n' || buf_i[i] == '\t') ++i;
        char * b = buf_i + i;
        while(i < sz_i && buf_i[i] != ' ' && buf_i[i] != '\n' && buf_i[i] != '\t') ++i;
        return string(b, buf_i + i - b);
    }
    inline string readLine()
    {
        char * b = buf_i + i;
        while(i < sz_i && buf_i[i] != '\n' && buf_i[i] != '\t') ++i;
        return string(b, buf_i + i - b);
    }
    inline void print(const string & s)
    {
        for(size_t j = 0; j < s.length(); ++j)
            buf_o[o++] = s[j];
    }
    inline void print(char a)
    {
        buf_o[o++] = a;
    }
    inline void print(int a)
    {
        if (!a)
        {
            buf_o[o++] = '0';
            return;
        }
        if (a < 0)
        {
            buf_o[o++] = '-';
            a = -a;
        }
        int j;
        for(j = 0; a; ++j, a /= 10)
            t[j] = a % 10 + '0';
        --j;
        while(j >= 0) buf_o[o++] = t[j--];
    }
    inline void print(long long a)
    {
        if (!a)
        {
            buf_o[o++] = '0';
            return;
        }
        if (a < 0)
        {
            buf_o[o++] = '-';
            a = -a;
        }
        int j;
        for(j = 0; a; ++j, a /= 10)
            t[j] = a % 10 + '0';
        --j;
        while(j >= 0) buf_o[o++] = t[j--];
    }
};

const int N = 7000003;

struct mapp
{
    int a[N];
    ull val[N];
    mapp()
    {
        clr(a);
    }
    void clear()
    {
        clr(a);
        clr(val);
    }
    inline int find(ull key)
    {
        int pos = key % N;
        while(val[pos] != key && a[pos])
        {
            ++pos;
            if (pos >= N) pos = 0;
        }
        if (val[pos] == key)
            return a[pos];
        else
            return 0;
    }
    inline void add(ull key)
    {
        int pos = key % N;
        while(val[pos] != key && a[pos])
        {
            ++pos;
            if (pos >= N) pos = 0;
        }
        val[pos] = key;
        a[pos]++;
    }
} ha;

int main()
{
    IO io;
    string s = io.readString();
    int n = io.readInt();
    int l[n], r[n];
    string q[n];
    forn(i, n)
    {
        q[i] = io.readString();
        l[i] = io.readInt();
        r[i] = io.readInt();
    }
    vector <ull> hh;
    forn(i, s.length())
    {
        ull h = 0;
        forn(j, s.length() - i)
        {
            h = h * 31 + s[i + j] - 'a' + 1;
            hh.pb(h);
        }
    }
    sort(all(hh));
    hh.resize(unique(all(hh)) - hh.begin());
    int pos[n];
    forn(i, n)
        pos[i] = i;
    random_shuffle(pos, pos + n);
    forn(z, n)
    {
        int i = pos[z];
        forn(j, q[i].length())
        {
            ull h = 0;
            forn(l, q[i].length() - j)
            {
                h = h * 31 + q[i][j + l] - 'a' + 1;
                ha.add(h);
            }
        }
        vector <ull> H;
        forn(j, hh.size())
        {
            int cnt = ha.find(hh[j]);
            if (cnt >= l[i] && cnt <= r[i])
                H.pb(hh[j]);
        }
        ha.clear();
        hh = H;
    }
    io.print((int)hh.size());
    return 0;
}