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

#define bit(a, pos) ((a >> pos) & 1)

int main()
{
    string s;
    cin >> s;
    in(n);
    if (s.find('1') == string::npos)
    {
        puts("NO");
        return 0;
    }
    if (n == 1)
    {
        puts("YES");
        cout << s.find('1') + 1 << endl;
        return 0;
    }
    char can[n + 1][11][19];
    int p[n][11][19];
    clr(can);
    for(int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            for(int cur = 1; cur <= 9; ++cur)
            {
                if (s[cur - 1] == '0') continue;
                can[i][cur][9 - cur] = 1;
            }
            continue;
        }
        if (i & 1)
        {
            for(int cur = 1; cur <= 10; ++cur)
            {
                if (s[cur - 1] == '0') continue;
                for(int balance = 1; balance <= 9; ++balance)
                {
                    if (balance - cur >= 0) continue;
                    if (balance - cur < -9) continue;
                    for(int prev = 1; prev <= 10; ++prev)
                    {
                        if (prev == cur) continue;
                        if (s[prev - 1] == '0') continue;
                        if (can[i - 1][prev][balance + 9])
                        {
                            can[i][cur][balance + 9 - cur] = 1;
                            p[i][cur][balance + 9 - cur] = prev;
                        }
                    }
                }
            }
        }
        else
        {
            for(int cur = 1; cur <= 10; ++cur)
            {
                if (s[cur - 1] == '0') continue;
                for(int balance = -1; balance >= -9; --balance)
                {
                    if (balance + cur <= 0) continue;
                    if (balance + cur > 9) continue;
                    for(int prev = 1; prev <= 10; ++prev)
                    {
                        if (prev == cur) continue;
                        if (s[prev - 1] == '0') continue;
                        if (can[i - 1][prev][balance + 9])
                        {
                            can[i][cur][balance + 9 + cur] = 1;
                            p[i][cur][balance + 9 + cur] = prev;
                        }
                    }
                }
            }
        }
    }
    for(int last = 1; last <= 10; ++last)
    {
        for(int balance = -9; balance <= 9; ++balance)
        {
            if (can[n][last][balance + 9])
            {
                puts("YES");
                vector <int> ans;
                while(n)
                {
                    ans.pb(last);
                    int nv = p[n][last][balance + 9];
                    if (n & 1)
                        balance += last;
                    else
                        balance -= last;
                    last = nv;
                    --n;
                }
                reverse(all(ans));
                for(int i = 0; i < (int)ans.size(); ++i)
                {
                    cout << ans[i];
                    if (i == ans.size() - 1)
                        cout << "\n";
                    else
                        cout << " ";
                }
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}