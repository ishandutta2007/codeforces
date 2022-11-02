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
template <typename T>
T gcd(T a, T b) {
    while (b > 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

bool isDelim(char c) {
    return c == '.' || c == '@';
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int prev_delim[s.length()];
    int next_point[s.length()];
    int next_non_alpha[s.length()];
    int next_non_alnum[s.length()];

    int prev_d = -1;

    int cnt_al[s.length() + 1];
    clr(cnt_al);

    for (int i = 0; i < (int)s.length(); ++i) {
        prev_delim[i] = prev_d;
        if (isDelim(s[i])) {
            prev_d = i;
        }
        cnt_al[i + 1] = cnt_al[i] + (bool)isalpha(s[i]);
    }

    int next_p = s.length(), next_na = s.length(), next_nal = s.length();

    for (int i = (int)s.length() - 1; i >= 0; --i) {
        next_non_alpha[i] = next_na;
        next_non_alnum[i] = next_nal;
        next_point[i] = next_p;

        if (s[i] == '.') {
            next_p = i;
        }
        if (!isalpha(s[i])) {
            next_na = i;
        }
        if (!isalnum(s[i])) {
            next_nal = i;
        }
    }

    long long ans = 0;

    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '@' && next_point[i] != s.length()  && next_point[i] != i + 1 && next_point[i] == next_non_alnum[i]) {
            int prev = prev_delim[i] + 1;
            long long cl = cnt_al[i] - cnt_al[prev];
            long long cr = next_non_alpha[next_point[i]] - next_point[i] - 1;
            ans += cl * cr;
        }
    }
    cout << ans << endl;

    return 0;
}