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
#include <stack>

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
    in(n);
    string name1,name2,name3;
    int k1m=0,k2m=0,k3m=0;
    forn(i,n)
    {
        in(t);
        string name;
        cin >> name;
        string tmp;
        int k1=0,k2=0,k3=0;
        forn(j,t)
        {
            cin >> tmp;
            int i = 1;
            bool flag1 = true;
            bool flag2 = true;
            int c = tmp[0];
            int prev = tmp[0];
            while (i<8)
            {
                if (!(i==2||i==5))
                {
                    flag1&=(tmp[i]==c);
                    flag2&=(tmp[i]<prev);
                    prev = tmp[i];
                }
                i++;
            }
            if (flag1)
                k1++;
            else if (flag2)
                k2++;
            else k3++;
        }
        if (k1>k1m)
        {
            name1 = name+", ";
            k1m=k1;
        }
        else if (k1==k1m)
        {
            name1+=name+", ";
        }
        if (k2>k2m)
        {
            name2 = name+", ";
            k2m=k2;
        }
        else if (k2==k2m)
        {
            name2+=name+", ";
        }
        if (k3>k3m)
        {
            name3 = name+", ";
            k3m=k3;
        }
        else if (k3==k3m)
        {
            name3+=name+", ";
        }
    }
    
    cout << "If you want to call a taxi, you should call: " << name1.substr(0,name1.length()-2) << "." << endl;
    cout << "If you want to order a pizza, you should call: " << name2.substr(0,name2.length()-2) << "."<< endl;
    cout << "If you want to go to a cafe with a wonderful girl, you should call: " << name3.substr(0,name3.length()-2) << "." << endl;
        
    return 0;
}