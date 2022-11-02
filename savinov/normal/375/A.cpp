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

int main()
{
    string s;
    cin >> s;
    int cnt[10];
    clr(cnt);
    for(char c : s)
    {
        cnt[c - '0']++;
    }
    cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;

    int mod = 0;

    for(int i = 9; i >= 1; --i)
    {
        for(int j = 0; j < cnt[i]; ++j)
        {
            mod = (mod * 10 + i) % 7;
        }
    }

    mod = (mod * 10000) % 7;

    mod = (7 - mod) % 7;

    s = "1689";
    do
    {
        int mo = 0;
        for(char c : s)
        {
            mo = (mo * 10 + (c - '0')) % 7;
        }
        if (mo == mod)
        {
            for(int i = 9; i > 0; --i)
            {
                for(int j = 0; j < cnt[i]; ++j)
                {
                    putchar(i + '0');
                }
            }

            cout << s;

            for(int j = 0; j < cnt[0]; ++j)
            {
                putchar('0');
            }
            puts("");
            return 0;
        }
    }while(next_permutation(all(s)));


    return 0;
}