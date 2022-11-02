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


struct team
{
    string name;
    int to,from;
    int cnt;
    int col;
    team (const string &name="", const int &to=0, const int &from=0, const int &cnt=0):name(name),to(to),from(from),cnt(cnt),col(0) {}

    friend bool operator<(const team &a,const team &b)
    {
        if (a.cnt>b.cnt) return true; else if (a.cnt<b.cnt) return false;
        if ((a.to-a.from)>(b.to-b.from)) return true; else if ((a.to-a.from)<(b.to-b.from)) return false;
        if (a.to>b.to) return true; else if (a.to<b.to) return false;
        return a.name<b.name;
    }

};

int main()
{
    //freopen("input.txt","r",stdin);
    team tm[4];
    for (int i=0;i<5;i++)
    {
        string nm1,nm2;
        cin >> nm1 >> nm2;
        int t1,t2;
        char c;
        cin >> t1 >> c >> t2;
        //cout << nm1 << " " << nm2 << endl;
        //cout << t1 <<":" <<t2 << endl;
        for (int i=0;i<4;i++)
        {
            if (tm[i].name=="") tm[i].name=nm1;
            if (tm[i].name==nm1)
            {
                tm[i].col++;
                tm[i].to+=t1;
                tm[i].from+=t2;
                if (t1>t2) tm[i].cnt+=3; else if (t1==t2) tm[i].cnt+=1;
                break;
            }
        }
        for (int i=0;i<4;i++)
        {
            if (tm[i].name=="") tm[i].name=nm2;
            if (tm[i].name==nm2)
            {
                tm[i].col++;
                tm[i].to+=t2;
                tm[i].from+=t1;
                if (t2>t1) tm[i].cnt+=3; else if (t1==t2) tm[i].cnt+=1;
                break;
            }
        }
    }
    int i1=0,i2=0;
    sort(tm,tm+4);
    for (int i=0;i<4;i++)
    {
        if (tm[i].name=="BERLAND") i1=i; else if (tm[i].col<3) i2=i;
    }
    for (int d=1;d<100;d++)
    {
        for (int y=0;y<100;y++)
        {
            int x = y+d;
            tm[i1].to+=x;
            tm[i1].from+=y;
            tm[i1].cnt+=3;
            tm[i2].to+=y;
            tm[i2].from+=x;
            sort(tm,tm+4);
            if (tm[0].name=="BERLAND"||tm[1].name=="BERLAND")
            {
                cout << x << ":" << y;
                return 0;
            }
            for (int i=0;i<4;i++)
            {
                if (tm[i].name=="BERLAND") i1=i; else if (tm[i].col<3) i2=i;
            }
            tm[i1].to-=x;
            tm[i1].from-=y;
            tm[i1].cnt-=3;
            tm[i2].to-=y;
            tm[i2].from-=x;


        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}