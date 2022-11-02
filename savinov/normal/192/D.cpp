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
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long LL;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

#define x first
#define y second

VI a,pos;

bool op(int i,int j)
{
    return a[i]>a[j];
}

int main()
{
    int n,k;
    cin >> n >> k;
    a.resize(n);
    pos.resize(n);
    LL s;
    cin >> s;
    forn(i,n)
    {
        pos[i]=i;
        cin >> a[i];
    }
    sort(pos.begin(),pos.end()-1,op);
    VI pos2(n-1);
    forn(i,n-1)
    {
        pos2[pos[i]]=i;
    }
    vector <LL> psum(n);
    psum[0]=0;
    forn(i,n-1)
    {
        psum[i+1]=psum[i]+a[pos[i]];
        //cout << pos2[i] << " ";
    }
    forn(i,n-1)
    {
        LL sm=0;
        if (pos2[i]>k-1)
        {
            sm=psum[k-1]+(LL)a[i];
        }
        else
        {
            sm=psum[k];
        }
        if (sm>s)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << n;
    return 0;
}