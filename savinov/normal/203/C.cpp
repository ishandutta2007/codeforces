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

#define bublic public
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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

#define x first
#define y second

inline bool cmp (pair<i64,i64> &a , pair<i64,i64> &b)
{
    return a.x<b.x;
}

int main()
{
    i64 n,d;
    cin >> n >> d;
    i64 a,b;
    cin >> a >> b;
    vector <pair<i64,i64> > r(n);
    forn(i,n)
    {
        int q,w;
        cin >> q >> w;
        r[i].first=q*a+w*b;
        r[i].second=i+1;
    }
    sort(all(r));
    i64 s=0;
    int i;
    VI ans;
    for (i=0;i<n;i++)
    {
       if (s+r[i].first<=d)
       {
           s+=r[i].first;
           ans.pb(r[i].second);
       }
    }
    cout << (int)ans.size() << endl;
    forn(j,ans.size())
    {
        cout << ans[j] << " ";
    }
    return 0;
}