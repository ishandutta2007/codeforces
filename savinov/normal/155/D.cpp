#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define out(x) cout << (x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;
char TEMPORARY_CHAR;
// Types
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while ((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0')
    {}

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }
}

#define x first
#define y second

int main()
{
    const int N = 100000;
    int lp[N+1];
    int dp[N+1];
    clr(lp);
    vector<int> pr;

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            dp[i] = 1;
            pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
    {
        lp[i * pr[j]] = pr[j];
        dp[i * pr[j]] = i;
    }

    }
    int on[N+1];
    clr(on);
    in(n);
    in(m);
    forn(i,m)
    {
        string tmp;
        cin >> tmp;
        in(p);
        int ok = 0;
        int t = p;
        if (tmp=="+")
        {
            if (on[p]==p)
            {
                cout << "Already on\n";
                continue;
            }
            while (!ok&&t!=1)
            {
                ok = on[lp[t]];
                t = dp[t];
            }
            if (ok)
            {
                cout << "Conflict with " << ok << endl;
                continue;
            }
            cout << "Success\n";
            t=p;
            on[p] = p;
            while (t!=1)
            {
                on[lp[t]]=p;
                t = dp[t];
            }
        }
        else
        {

            if (on[p]!=p)
            {
                cout << "Already off\n";
                continue;
            }
            cout << "Success\n";
            on[p] = 0;
            while (t!=1)
            {
                on[lp[t]]=0;
                t = dp[t];
            }
        }
    }
    return 0;
}