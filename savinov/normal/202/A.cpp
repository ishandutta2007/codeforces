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


int main()
{
    string s;
    cin >> s;
    int len = (int)s.length();
    string ans = "";
    int nm = 1 << len;
    for (int i=0;i<nm;i++)
    {
        string tmp = "";
        int t = i;
        for (int j=0;j<len;j++)
        {
            if (t&1) tmp+=s[j];
            t>>=1;
        }
        bool flag = true;
        for (int j=0;j<(int)tmp.length();j++)
        {
            flag&=(tmp[j]==tmp[(int)tmp.length()-j-1]);
        }
        flag&=(tmp>ans);
        if (flag) ans = tmp;
    }
    cout << ans;
    return 0;
}