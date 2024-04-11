#include <bits/stdc++.h>
#include <ext/rope>
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
 
using namespace __gnu_cxx;
 
template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}
 
//inline void input(long long &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;}
 
vector <vector <int> > dr[25];
 
vector <int> cur;
 
void rec(int s, int prev, vector <vector <int> > & z) {
    if (s == 0) {
        z.push_back(cur);
        return;
    }
    for (int i = 1; i <= min(prev, s); ++i) {
        cur.push_back(i);
        rec(s - i, i, z);
        cur.pop_back();
    }
}
 
int main()
{
    in(n);
    dr[0].push_back(vector <int>());
    for (int i = 1; i <= n; ++i) {
        rec(i, i, dr[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)dr[i].size(); ++j) {
            sort(all(dr[i][j]));
        }
        sort(all(dr[i]));
    }
 
 
    int c[n];
 
    for (int i = 0; i < n; ++i) {
        c[i] = nxt();
    }
 
    sort(c, c + n);
 
    if (c[n - 1] != n) {
        puts("NO");
        return 0;
    }
 
    char dp[n + 1][dr[n].size()];
    clr(dp);
    dp[0][0] = 1;
    int s = 0;
 
    for (int i = 0; i < n; ++i) {
        s += 1;
        for (int j = 0; j < dr[s].size(); ++j) {
            int pos = lower_bound(all(dr[s][j]), c[i]) - dr[s][j].begin();
            if (pos != dr[s][j].size() && dr[s][j][pos] == c[i]) {
                vector <int> d = dr[s][j];
                d.erase(d.begin() + pos);
 
                for (int k = 0; k < dr[c[i] - 1].size(); ++k) {
                    if (dr[c[i] - 1][k].size() == 1) continue;
                    vector <int> q;
                    merge(all(d), all(dr[c[i] - 1][k]), back_inserter(q));
                    int p = lower_bound(all(dr[s - 1]), q) - dr[s - 1].begin();
                    if (dp[i][p]) {
                        dp[i + 1][j] = 1;
                        break;
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < dr[n].size(); ++i) {
        if (dp[n][i]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}