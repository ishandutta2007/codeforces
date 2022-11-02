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
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 5e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

#define bit(a, pos) ((a >> pos) & 1)

vector <int> source;
vector <int> ans[4][4];
char used[100000000];

void calc(int l, int r)
{
    if (!ans[l][r].empty()) return;
    if (l == r)
    {
        ans[l][l].pb(source[l]);
        ans[l][l].pb(-source[l]);
        return;
    }
    int nu = 0;
    for(int i = l; i <= r; ++i)
        nu = nu * 10 + source[i];
    ans[l][r].pb(nu);
    ans[l][r].pb(-nu);
    for(int pos = l; pos < r; ++pos)
    {
        calc(l, pos);
        calc(pos + 1, r);
        for(int x : ans[l][pos])
            for(int y : ans[pos + 1][r])
            {
                ans[l][r].pb(x + y);
                ans[l][r].pb(x - y);
                ans[l][r].pb(x * y);
            }
    }
    sort(all(ans[l][r]));
    ans[l][r].resize(unique(all(ans[l][r])) - ans[l][r].begin());
}

int main()
{
    int M = 10000;
    vector <int> * can = new vector<int>[2 * M + 1] + M;
    clr(used);
    int mini = 100000;
    for(int i = 0; i < M; ++i)
    {
        forn(l, 4)
            forn(r, 4)
                ans[l][r].clear();
        source.clear();
        int cur = i;
        forn(j, 4)
        {
            source.pb(cur % 10);
            cur /= 10;
        }
        reverse(all(source));
        calc(0, 3);
        remin(mini, ans[0][3].size());
        for(int x : ans[0][3])
            can[x].pb(i);
    }
    in(k); in(m);
    for(int i = -9999; m; i++)
    {
        for(int z: can[i])
        {
            if (!m) break;
            if (k - i >= -M && k - i <= M)
            {
                for(int q : can[k - i])
                {
                    if (!m) break;
                    if (!used[z * M + q])
                    {
                        used[z * M + q] = 1;
                        printf("%04d%04d\n", z, q);
                        --m;
                    }
                    if (!m) break;
                    if (!used[q * M + z])
                    {
                        used[q * M + z] = 1;
                        printf("%04d%04d\n", q, z);
                        --m;
                    }
                }
            }
            if (!m) break;
            if (k + i >= -M && k + i <= M)
            {
                for(int q : can[k + i])
                {
                    if (!m) break;
                    if (!used[z * M + q])
                    {
                        used[z * M + q] = 1;
                        printf("%04d%04d\n", z, q);
                        --m;
                    }
                    if (!m) break;
                    if (!used[q * M + z])
                    {
                        used[q * M + z] = 1;
                        printf("%04d%04d\n", q, z);
                        --m;
                    }
                }
            }
        }
    }
    return 0;

}