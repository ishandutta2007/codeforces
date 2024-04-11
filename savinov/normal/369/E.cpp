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

const int N = 1000000;

vector <int> t[2 * N];

int get(int l, int r)
{
    int ans = 0;
    for(int L = l + N, R = r + N; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
    {
        if (L & 1)
            ans += upper_bound(all(t[L]), r) - t[L].begin();
        if (!(R & 1))
            ans += upper_bound(all(t[R]), r) - t[R].begin();
    }
    return ans;
}

int q[300002];

int main()
{
    in(n); in(m);
    for(int i = 0; i < n; ++i)
    {
        int l = nxt() - 1;
        int r = nxt() - 1;
        t[l + N].pb(r);
    }
    for(int i = 0; i < N; ++i)
    {
        sort(all(t[i + N]));
    }
    for(int i = N - 1; i > 0; --i)
    {
        merge(all(t[i + i]), all(t[i + i + 1]), back_inserter(t[i]));
    }
    while(m--)
    {
        int k = nxt();
        int sz = 0;
        q[sz++] = -1;
        while(k--)
            q[sz++] = nxt() - 1;
        q[sz++] = 1000000;
        int ans = 0;
        //cout << endl;
        for(int i = 0; i < sz - 1; ++i)
        {
            ans += get(q[i] + 1, q[i + 1] - 1);
            //cout << q[i] + 1 << " "<< q[i + 1] - 1 << " * " << get(q[i] + 1, q[i + 1] - 1) << endl;
        }
        cout << n - ans << "\n";
    }
    return 0;
}