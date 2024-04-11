#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
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
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-8;
char TEMPORARY_CHAR;
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;
const ll INF = 1e17;
const int N = 1 << 17;
inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){}
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

#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)

#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

bool check(string &s)
{
    if (s[0] == '-' || s[1] == '-' || s[2] != '-' || s[3] == '-' || s[4] == '-' || s[5] != '-' || s[6] == '-' || s[7] == '-' || s[8] == '-' || s[9] == '-')
        return false;
    int day, month, year;
    day = atoi(s.substr(0, 2).c_str());
    month = atoi(s.substr(3, 2).c_str());
    year = atoi(s.substr(6, 4).c_str());
    if (year > 2015 || year < 2013)
        return false;
    tm tim;
    tim.tm_hour = 0;
    tim.tm_min = 0;
    tim.tm_sec = 0;
    tim.tm_year = year - 1900;
    tim.tm_mon = month - 1;
    tim.tm_mday = day;
    mktime(&tim);
    return (tim.tm_year == year - 1900 && tim.tm_mon == month - 1 && tim.tm_mday == day);
}


int main()
{
    string s;
    cin >> s;
    MSI freq;
    forn(i, (int)s.length() - 9)
    {
        string cur = s.substr(i, 10);
        if (check(cur))
            ++freq[cur];
    }
    string most_freq;
    int ma = 0;
    fori(it, freq)
    {
        if (it -> second > ma)
        {
            most_freq = it -> first;
            ma = it -> second;
        }
    }
    cout << most_freq << endl;
    return 0;
}