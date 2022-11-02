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


int s[2000][2000];

int counter = 2;

struct tt
{
    int start;
    int finish;
    int len;
};


tt calc(int cnt)
{
    if (cnt == 1)
    {
        tt res;
        res.start = counter++;
        res.finish = counter++;
        res.len = 1;
        s[res.start][res.finish] = 1;
        s[res.finish][res.start] = 1;
        return res;
    }

    if (cnt & 1)
    {
        tt res = calc(cnt - 1);

        int prev = res.start;

        for(int i = 0; i < res.len - 1; ++i)
        {
            int cur = counter++;
            s[prev][cur] = 1;
            s[cur][prev] = 1;
            prev = cur;
        }

        s[prev][res.finish] = 1;
        s[res.finish][prev] = 1;
        return res;
    }
    else
    {
        tt res = calc(cnt / 2);

        int l = counter++;
        int t = counter++;
        int b = counter++;
        int r = res.start;

        s[l][t] = 1;
        s[t][l] = 1;
        s[b][l] = 1;
        s[l][b] = 1;
        s[r][t] = 1;
        s[t][r] = 1;
        s[r][b] = 1;
        s[b][r] = 1;

        res.start = l;
        res.len += 2;

        return res;
    }
}

int main()
{
    int v = nxt();
    tt res = calc(v);

    s[0][res.start] = 1;
    s[res.start][0] = 1;
    s[res.finish][1] = 1;
    s[1][res.finish] = 1;

    printf("%d\n", counter);

    for(int i = 0; i < counter; ++i)
    {
        for(int j = 0; j < counter; ++j)
        {
            if (s[i][j])
                putchar('Y');
            else
                putchar('N');
        }
        puts("");
    }

    return 0;
}