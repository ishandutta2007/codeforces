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
    #include <queue>
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

struct state {
    int len, link;
    long long cnt[3];
    map<char,int> next;
};

const int MAXLEN = 333333;
state st[MAXLEN*2];
int sz, last;

void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    clr(st[0].cnt);
    ++sz;
}

vector <int> statesByLen[MAXLEN + 1];

void sa_extend (char c, int k) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    clr(st[cur].cnt);
    st[cur].cnt[k] = 1;
    statesByLen[st[cur].len].push_back(cur);
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            clr(st[clone].cnt);
            statesByLen[st[clone].len].push_back(clone);
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

long long mod = 1000000007;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    string a, b, c;
    cin >> a >> b >> c;
    sa_init();
    for (int i = 0; i < a.length(); ++i) {
        sa_extend(a[i], 0);
    }
    sa_extend('1', 0);
    for (int i = 0; i < b.length(); ++i) {
        sa_extend(b[i], 1);
    }
    sa_extend('2', 1);
    for (int i = 0; i < c.length(); ++i) {
        sa_extend(c[i], 2);
    }
    sa_extend('3', 2);


    for (int i = MAXLEN; i > 0; --i) {
        for (int v : statesByLen[i]) {
            for (int j = 0; j < 3; ++j) {
                st[st[v].link].cnt[j] += st[v].cnt[j];
            }
        }
    }
    int l = min(a.length(), min(b.length(), c.length()));
    long long add[l + 2];
    clr(add);
    for (int i = 1; i < sz; ++i) {
        //cout << st[i].cnt[0] << " " << st[i].cnt[1] << " " << st[i].cnt[2] << " " << st[i].len << endl;
        long long k = (st[i].cnt[0] * st[i].cnt[1] * st[i].cnt[2]) % mod;
        int l1 = min(l, st[i].len);
        int l2 = min(l, st[st[i].link].len);
        add[l2 + 1] += k;
        while (add[l2 + 1] >= mod) {
            add[l2 + 1] -= mod;
        }

        add[l1 + 1] += mod - k;
        while (add[l1 + 1] >= mod) {
            add[l1 + 1] -= mod;
        }
    }
    long long cur = 0;
    for (int i = 1; i <= l; ++i) {
        cur += add[i];
        if (cur >= mod) {
            cur -= mod;
        }
        if (i > 1) {
            cout << " ";
        }
        cout << cur;
    }
    cout << endl;
    return 0;
}