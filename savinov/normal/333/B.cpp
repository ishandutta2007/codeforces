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

char can[8][8];

bool check(const vector <int> & a)
{
    for(int i : a)
        for(int j : a)
            if (!can[i][j]) return false;
    return true;
}

int main()
{
    memset(can, 1, sizeof(can));
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
        {
            if ((j ^ i) == 1) can[i][j] = 0;
            if (j == (i + 3) % 8) can[i][j] = 0;
            if (j == (i + 5) % 8) can[i][j] = 0;
        }
    in(n); in(m);
    char banned_rows[n], banned_cols[n];
    clr(banned_rows);
    clr(banned_cols);
    while(m--)
    {
        banned_rows[nxt() - 1] = 1;
        banned_cols[nxt() - 1] = 1;
    }
    int ans = 0;
    for(int i = 1; i < n / 2; ++i)
    {
        int best = 0;
        int an = 255;
        if (banned_rows[i]) an ^= 1, an ^= 1 << 3;
        if (banned_rows[n - 1 - i]) an ^= 1 << 4, an ^= 1 << 7;
        if (banned_cols[i]) an ^= 1 << 1, an ^= 1 << 6;
        if (banned_cols[n - 1 - i]) an ^= 1 << 2, an ^= 1 << 5;
        for(int mask = 0; mask < 256; ++mask)
        {
            vector<int> bits;
            int cur = mask & an;
            for(int j = 0; j < 8; ++j)
                if (bit(cur, j)) bits.pb(j);
            if (check(bits))
                remax(best, bits.size());
        }
        ans += best;
    }
    if (n & 1)
        ans += !banned_cols[n / 2] || !banned_rows[n / 2];
    cout << ans << endl;
    return 0;

}