#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
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



#define x first
#define y second


int main()
{
    int n;
    cin >> n;
    int m = (n+1)/2;
    vector <int> mp1,mp2;
    forn(i,n)
    {
        int a,b;
        cin >> a >> b;
        mp1.pb(a);
        if (a!=b) mp1.pb(b);
        mp2.pb(a);
    }
    sort(all(mp1));
    sort(all(mp2));
    int ma = -1;
    for (int i = 0,j=0;i<(int)mp1.size();i++)
    {
        int cnt1 = 0,cnt2 = 0;
        while (i+cnt1<(int)mp1.size()&&mp1[i+cnt1]==mp1[i]) cnt1++;
        while (j+cnt2<(int)mp2.size()&&mp2[j+cnt2]==mp1[i]) cnt2++;
        if (cnt1>=m&&cnt2>ma) ma = cnt2;
        i = i + cnt1 - 1;
        j = j + cnt2;
    }
    ma = min(m,ma);
    if (ma>=0) cout << m - ma; else cout << "-1";
    return 0;
}