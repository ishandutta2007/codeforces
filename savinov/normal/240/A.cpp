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

const int N = 1 << 16;

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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    in(m);
    in(k);
    bool like[m];
    clr(like);
    forn(i, k)
        like[nxt() - 1] = true;
    in(n);
    int mi[n], ma[n];
    int big_min = -1;
    forn(i, n)
    {
        string s;
        cin >> s;
        in(d);
        VI act;
        mi[i] = 0;
        ma[i] = d;
        int unset = 0;
        SI rem;
        forn(j, m)
            rem.insert(j);
        while (d--)
        {
            in(cur);
            cur--;
            if (cur >= 0)
            {
                if (like[cur])
                    ++mi[i];
                rem.erase(cur);
            }
            else
                ++unset;
        }
        int rem_liked = 0;
        int rem_unliked = 0;
        fori(it, rem)
        {
            if (like[*it])
                rem_liked++;
            else
                rem_unliked++;
        }
        ma[i] = mi[i];
        ma[i] += min(rem_liked, unset);
        mi[i] += max(unset - rem_unliked, 0);

        if (mi[i] > big_min)
            big_min = mi[i];
    }
    forn(i,n)
    {
        if (ma[i] < big_min)
        {
            puts("1");
            continue;
        }
        int status = 0;
        forn(j, n)
            if (i != j)
                if (ma[j] > mi[i])
                    status = 2;
        cout << status << endl;
    }
    return 0;
}