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
    ll k, x, n, m;
    cin >> k >> x >> n >> m;

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            for(int c = 0; c * 2 <= n - __builtin_popcount(i); ++c)
            {
                for(int d = 0; d * 2 <= m - __builtin_popcount(j); ++d)
                {
                    ll cnt[k];
                    cnt[0] = c;
                    cnt[1] = d;
                    int q[k];
                    q[0] = i;
                    q[1] = j;
                    for(int p = 2; p < k; ++p)
                    {
                        cnt[p] = cnt[p - 2] + cnt[p - 1];
                        if (((q[p - 2]) & 1) && (q[p - 1] & 2)) cnt[p]++;
                        q[p] = 0;
                        if ((q[p - 2] & 2)) q[p] |= 2;
                        if ((q[p - 1] & 1)) q[p] |= 1;
                    }
                    if (cnt[k - 1] == x)
                    {
                        string s, t;
                        if (i & 2)
                        {
                            s += 'C';
                        }
                        for(int v = 0; v < c; ++v)
                        {
                            s += "AC";
                        }
                        if (i & 1)
                        {
                            while(s.length() + 1 < n)
                                s += 'X';
                            s += 'A';
                        }
                        else
                        {
                            while(s.length() < n)
                                s += 'X';
                        }

                        if (j & 2)
                        {
                            t += 'C';
                        }
                        for(int v = 0; v < d; ++v)
                        {
                            t += "AC";
                        }
                        if (j & 1)
                        {
                            while(t.length() + 1 < m)
                                t += 'X';
                            t += 'A';
                        }
                        else
                        {
                            while(t.length() < m)
                                t += 'X';
                        }

                        cout << s << endl;
                        cout << t << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Happy new year!" << endl;
    return 0;
}