#ifdef LOCAL
    #include <iostream>
    #include <cstring>
    #include <cmath>
    #include <vector>
    #include <set>
    #include <map>
    #include <cstdio>
    #include <cmath>
    #include <iomanip>
    #include <sstream>
    #include <cassert>
    #include <queue>
#else
    #include <bits/stdc++.h>
#endif

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
    while (b > 0) { 
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    in(k); in(n1); in(n2); in(n3); in(t1); in(t2); in(t3);

    priority_queue<int, VI, greater<int> > q[3];

    int curTime = 0;

    int ans = 0;

    while (k--) {
        for (int i = 0; i < 3; ++i) {
            while (!q[i].empty() && q[i].top() <= curTime) {
                q[i].pop();
            }
        }
        int T1 = q[0].size() == n1 ? q[0].top() : curTime;
        int T2 = q[1].size() == n2 ? q[1].top() : curTime;
        int T3 = q[2].size() == n3 ? q[2].top() : curTime;

        int pushTime = max(T1, max(T2 - t1, T3 - t1 - t2));

        if (q[0].size() == n1) {
            q[0].pop();
        }
        if (q[1].size() == n2) {
            q[1].pop();
        }
        if (q[2].size() == n3) {
            q[2].pop();
        }

        q[0].push(pushTime + t1);
        q[1].push(pushTime + t1 + t2);
        ans = max(ans, pushTime + t1 + t2 + t3);
        q[2].push(pushTime + t1 + t2 + t3);

        curTime = pushTime;
    }
    cout << ans << endl;
    return 0;
}