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
//#include <priority_queue>

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

struct sphere
{
    int x;
    int y;
    sphere(int x,int y):x(x),y(y){}
    friend bool operator>(const sphere &a, const sphere &b)
    {
        return a.x>b.x;
    }
    friend bool operator<(const sphere &a, const sphere &b)
    {
        return a.x<b.x;
    }

};

int main()
{
    in(n);
    int a[100000];
    forn(i,n)
        a[i] = nxt();
    sort(a,a+n);
    priority_queue <sphere> q;
    forn(i,n)
    {
        int cnt = 0;
        while (i+cnt<n&&a[i]==a[i+cnt])
            cnt++;
        q.push(sphere(cnt,a[i]));
        i += cnt - 1;
    }
    int ans = 0;
    vector <pair <PII,int> > an;
    while (q.size()>2)
    {
        sphere x = q.top();
        q.pop();
        sphere y = q.top();
        q.pop();
        sphere z = q.top();
        q.pop();
        if (z.x==0)
            break;
        --x.x;--y.x;--z.x;
        ans++;
        an.pb(mp(mp(x.y,y.y),z.y));
        q.push(x);q.push(y);q.push(z);
    }
    cout << ans << endl;
    forn(i,ans)
    {
        int x = an[i].x.x;
        int y = an[i].x.y;
        int z = an[i].y;
        int s = x + y + z;
        cout << max(x,max(y,z)) << " " << s - max(x,max(y,z)) - min(x,min(y,z)) << " " << min(x,min(y,z)) << endl;
    }

    return 0;
}