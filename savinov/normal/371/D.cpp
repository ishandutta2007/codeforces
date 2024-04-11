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
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

using namespace std;

int s[200001];

int n;

int get(int r)
{
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
    {
        res += s[r];
    }
    return res;
}

void add(int pos, int val)
{
    for(; pos <= n; pos |= pos + 1)
        s[pos] += val;
}

int find(int pos)
{
    int l = pos - 1, r = n - 1;
    int ss = get(pos - 1);
    while(l < r)
    {
        int m = (l + r + 1) >> 1;
        if (get(m) - ss != m - pos + 1)
            r = m - 1;
        else
            l = m;
    }
    return l + 1;
}

int vol[200000];
int cnt[200000];


void pull(int pos, int ad)
{
    pos = find(pos);
    if (pos == n) return;
    int d = min(vol[pos] - cnt[pos], ad);

    cnt[pos] += d;
    ad -= d;

    if (cnt[pos] == vol[pos])
        add(pos, 1);
    if (ad)
        pull(pos + 1, ad);
}


int main()
{
    input(n);
    for(int i = 0; i < n; ++i)
    {
        vol[i] = nxt();
    }
    in(m);
    while(m--)
    {
        in(t);
        if (t == 1)
        {
            int pos = nxt() - 1;
            int ad = nxt();
            pull(pos, ad);
        }
        else
        {
            int pos = nxt() - 1;
            cout << cnt[pos] << endl;
        }
    }
    return 0;
}