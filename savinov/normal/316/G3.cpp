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
#include <unordered_map>
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
using namespace std; typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 1e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; typedef complex<ld> cbase; inline void fft (vector<cbase> &a, bool invert) {int n = (int)a.size(); for (int i = 1, j = 0; i < n; ++i) {int bit = n >> 1; for (; j >= bit; bit >>= 1) j -= bit; j += bit; if (i < j) swap(a[i], a[j]);} for (int len = 2; len <= n; len <<= 1) {ld ang = 2 * PI / len * (invert ? -1 : 1); cbase wlen(cos(ang), sin(ang)); for (int i = 0; i < n; i += len) {cbase w(1); for (int j=0; j < len / 2; ++j) {cbase u = a[i + j], v = a[i + j + len / 2] * w; a[i + j] = u + v; a[i + j + len / 2] = u - v; w *= wlen;}}} if (invert) for (int i = 0; i < n; ++i) a[i] /= n;} inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(ll a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;} struct lnum {vector <int> a; int base; lnum(int num = 0, int base = 1000000000):base(base) {if (!num) a.resize(1); while(num) {a.pb(num % base); num /= base;}} inline int len() const {return a.size();} lnum & operator=(const lnum &l) {if (this != &l) {a = l.a; base = l.base;} return *this;} inline friend lnum operator+(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int ln = l.len(), rn = r.len(); int n = max(ln, rn); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = o; if (i < ln) s += l.a[i]; if (i < rn) s += r.a[i]; o = s >= base; if (o) s -= base; ret.a[i] = s;} if (o) ret.a.push_back(1); return ret;} inline friend lnum operator-(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; int n = l.len(); int rn = r.len(); ret.a.resize(n); int o = 0; for(int i = 0; i < n; ++i) {int s = l.a[i] - o; if (i < rn) s -= r.a[i]; o = s < 0; if (o) s += base; ret.a[i] = s;} if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator*(const lnum &l, const lnum &r) {lnum ret(0, l.base); int base = l.base; if (l.len() * r.len() > 1000000) {vector<cbase> fa (l.a.begin(), l.a.end()), fb (r.a.begin(), r.a.end()); int n = 1; while (n < max (l.len(), r.len())) n <<= 1; n <<= 1; fa.resize (n), fb.resize (n); fft (fa, false), fft (fb, false); for (int i = 0; i < n; ++i) fa[i] *= fb[i]; fft (fa, true); ret.a.resize(n); for (int i = 0; i < n; ++i) ret.a[i] = int (fa[i].real() + 0.5); int carry = 0; for (int i=0; i < n; ++i) {ret.a[i] += carry; carry = ret.a[i] / base; ret.a[i] %= base;}} else {ret.a.resize(l.len() + r.len()); for (int i = 0; i < l.len(); ++i) for (int j = 0, carry = 0; j < r.len() || carry; ++j) {long long cur = ret.a[i + j] + (ll)l.a[i] * (j < r.len() ? r.a[j] : 0) + carry; ret.a[i + j] = cur % base; carry = cur / base;}} while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back(); return ret;} inline friend lnum operator/(const lnum &l, const int &r) {lnum ret(0, l.base); ret.a.resize(l.len()); int carry = 0; for(int i = l.len() - 1; i >= 0; --i) {long long cur = l.a[i] + (ll)carry * l.base; ret.a[i] = cur / r; carry = cur % r;} while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back(); return ret;}  inline friend bool operator<(const lnum &l, const lnum &r) {if (l.len() < r.len()) return true; if (l.len() > r.len()) return false; int n = l.len(); for(int i = n - 1; i >= 0; --i) {if (l.a[i] < r.a[i]) return true; if (l.a[i] > r.a[i]) return false;} return false;} inline friend bool operator>(const lnum &l, const lnum &r) {return r < l;} inline friend bool operator==(const lnum &l, const lnum &r) {if (l.len() != r.len()) return false; int n = l.len(); for(int i = n - 1; i; --i) {if (l.a[i] != r.a[i]) return false;} return true;} inline friend bool operator!=(const lnum &l, const lnum &r) {return !(l == r);} inline void print() {if (base == 1000000000) {printf("%d", a.back()); for(int i = a.size() - 2; i >=0; --i) printf("%09d", a[i]);} else {for(int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);}}};

struct node
{
    node * next[26];
    node * link;
    int cnt[11];
    int len;
    node()
    {
        link = 0;
        len = 0;
        memset(next, 0, sizeof(next));
        memset(cnt, 0, sizeof(cnt));
    }
    node(node * x)
    {
        link = x->link;
        len = x->len;
        memset(cnt, 0, sizeof(cnt));
        memcpy(next, x->next, sizeof(next));
    }
};

node * last, * root;

vector <node *> nodes;

void add(int c)
{
    node * cur = new node();
    nodes.pb(cur);
    cur->len = last->len + 1;
    node * p = last;
    for(; p && !p->next[c]; p = p->link)
        p->next[c] = cur;
    if (!p)
    {
        cur->link = root;
    }
    else
    {
        node * q = p->next[c];
        if (p->len + 1 == q->len)
        {
            cur->link = q;
        }
        else
        {
            node * cl = new node(q);
            nodes.pb(cl);
            cl->len = p->len + 1;
            for(; p && p->next[c] == q; p = p->link)
                p->next[c] = cl;
            q->link = cur->link = cl;
        }
    }
    last = cur;
}

void process(const string & s, int ind)
{
    last = root;
    int len = 0;
    for(char c : s)
    {
        ++len;
        if (last->next[c - 'a'] && last->next[c - 'a']->len == len)
        {
            last = last->next[c - 'a'];
        }
        else
        {
            add(c - 'a');
        }
        ++last->cnt[ind];
    }
}

bool cmp(node * l, node * r)
{
    return l->len <= r->len;
}


string ok;

int main()
{
    last = root = new node();

    int l[11], r[11];
    string s[11];

    cin >> s[0];
    l[0] = 1, r[0] = s[0].length();

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i] >> l[i] >> r[i];
    }

    ++n;

    for(int i = 0; i < n; ++i)
        process(s[i], i);

    stable_sort(all(nodes), cmp);

    ll ans = 0;

    for(int i = (int)nodes.size() - 1; i >= 0; --i)
    {
        bool ok = true;
        node * cur = nodes[i];
        for(int j = 0; j < n; ++j)
        {
            cur->link->cnt[j] += cur->cnt[j];
            if (cur->cnt[j] < l[j] || cur->cnt[j] > r[j])
                ok = false;
        }
        if (ok && cur->link)
            ans += cur->len - cur->link->len;
    }
    cout << ans << endl;
    return 0;
}