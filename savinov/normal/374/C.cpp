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

int n, m;

char s[1001][1001];
char used[1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

char nex[256];

vector <PII> topsort;

void dfs(int x, int y)
{
    used[x][y] = 1;
    for(int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] != nex[s[x][y]])
            continue;
        if (used[xx][yy] == 1)
        {
            puts("Poor Inna!");
            exit(0);
        }
        if (!used[xx][yy])
        {
            dfs(xx, yy);
        }
    }
    topsort.pb(mp(x, y));
    used[x][y] = 2;
}

int main()
{
    nex['D'] = 'I';
    nex['I'] = 'M';
    nex['M'] = 'A';
    nex['A'] = 'D';

    input(n); input(m);

    for(int i = 0; i < n; ++i)
    {
        gets(s[i]);
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if (!used[i][j])
            {
                dfs(i, j);
            }
        }
    }

    int dp[n][m];
    clr(dp);
    int ans = 0;
    for(auto q : topsort)
    {
        int x = q.x, y = q.y;
        for(int k = 0; k < 4; ++k)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] != nex[s[x][y]])
                continue;
            if (dp[xx][yy])
                remax(dp[x][y], dp[xx][yy]);
        }
        if (s[x][y] == 'A' || dp[x][y])
            ++dp[x][y];
        if (s[x][y] == 'D')
            remax(ans, dp[x][y] / 4);
    }
    if (ans)
    {
        cout << ans << endl;
    }
    else
    {
        puts("Poor Dima!");
    }
    //reverse(all(topsort));



    return 0;
}