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

const int INF = 1e9;

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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    string s,p;
    cin >> s;
    cin >> p;
    int cnt[26];
    clr(cnt);
    forn(i,p.length())
        cnt[p[i]-'a']++;
    if ((int)s.length()<(int)p.length())
    {
        cout << "0" << endl;
        return 0;
    }
    int cur[26];
    clr(cur);
    forn(i,p.length())
        if (s[i]!='?')
            cur[s[i]-'a']++;
    int ans = 0;
    forn(i,(int)s.length()-(int)p.length()+1)
    {
        bool flag = true;
        forn(j,26)
            flag&=(cur[j]<=cnt[j]);
        ans+=flag;
        if (i+(int)p.length()<(int)s.length())
        {
            if (s[i]!='?') cur[s[i]-'a']--;
            if (s[i+(int)p.length()]!='?') cur[s[i+(int)p.length()]-'a']++;
        }
    }
    cout << ans << endl;
    return 0;
}