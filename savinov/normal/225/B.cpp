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


typedef long double ld;
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }



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

const ll INF = 1e17;

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-'))
    {}
    char neg = 0;
    if (TEMPORARY_CHAR == '-')
    {
        neg = 1;
        TEMPORARY_CHAR = getchar();
    }

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }

    if (neg)
        a = -a;
}
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    int k;
    ll s;
    cin >> s >> k;
    vector <long long> ans;
    if (k >= 31)
    {
        long long dva = 1;
        while (s)
        {
            if (s & 1ll)
                ans.pb(dva);
            dva<<=1ll;
            s>>=1ll;
        }
        ans.pb(0);
    }
    else
    {
        ll f[10000];
        ll sum = 0;
        int i;
        f[0] = 0;
        for(i = 1; sum <= 1000000000ll; ++i)
        {
            if (i < k)
                f[i] = 0;
            if (i == k)
                f[i] = 1;
            if (i > k)
                f[i] = sum;
            sum += f[i];
            if (i > k)
                sum -= f[i - k];
            //cout << f[i] << endl;
        }
        ford(j,i)
        {
            if (s >= f[j] && f[j])
            {
                s -= f[j];
                ans.pb(f[j]);
            }
        }
        ans.pb(0);
    }
    cout << (int)ans.size() << endl;
    forn(i,ans.size())
        cout << ans[i] << " ";
    return 0;
}