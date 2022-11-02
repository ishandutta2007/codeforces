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
struct proc
{
    string name;
    vector <int> typ;
};

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    getchar();
    vector <proc> pr(n);
    for (int i=0;i<n;i++)
    {
        string tmp;
        getline(cin,tmp);
        int j=0;
        while (tmp[j]==' ') j++;
        while (tmp[j]!=' ') j++;
        while (tmp[j]==' ') j++;
        while (tmp[j]!=' '&&tmp[j]!='(')
        {
            pr[i].name+=tmp[j];
            j++;
        }
        while (tmp[j]!='(') j++;
        j++;
        while (tmp[j]!=')')
        {
            while (tmp[j]==' '||tmp[j]==',') j++;
            string T;
            while (tmp[j]!=' '&&tmp[j]!=')'&&tmp[j]!=',')
            {
                T+=tmp[j];
                j++;
            }
            if (T!="")
            {
                if (T=="T") pr[i].typ.pb(0);
                if (T=="int") pr[i].typ.pb(1);
                if (T=="double") pr[i].typ.pb(2);
                if (T=="string") pr[i].typ.pb(3);
            }
        }
    }
    map <string,int> vars;
    int m;
    cin >> m;
    getchar();
    for (int i=0;i<m;i++)
    {
        string tmp;
        getline(cin,tmp);
        int j=0;
        while (tmp[j]==' ') j++;
        string T1,T2;
        while (tmp[j]!=' ')
        {
            T1+=tmp[j];
            j++;
        }
        while (tmp[j]==' ') j++;
        while (j<(int)tmp.length()&&tmp[j]!=' ')
        {
            T2+=tmp[j];
            j++;
        }
        if (T1=="int") vars[T2]=1;
        if (T1=="double") vars[T2]=2;
        if (T1=="string") vars[T2]=3;
    }
    int k;
    cin >> k;
    getchar();
    for (int i=0;i<k;i++)
    {
        string tmp;
        getline(cin,tmp);
        vector <int> tp;
        string nm;
        int j=0;
        while (tmp[j]==' ') j++;
        while (tmp[j]!=' '&&tmp[j]!='(')
        {
            nm+=tmp[j];
            j++;
        }
        while (tmp[j]!='(') j++;
        j++;
        while (tmp[j]!=')')
        {
            while (tmp[j]==' '||tmp[j]==',') j++;
            string T;
            while (tmp[j]!=' '&&tmp[j]!=')'&&tmp[j]!=',')
            {
                T+=tmp[j];
                j++;
            }
            if (T!="")
            {
                tp.pb(vars[T]);
                //cout << T << endl;
            }
        }
        //cout << endl;
        int ans=0;
        for (j=0;j<(int)pr.size();j++)
        {
            if (pr[j].name==nm)
            {
                if (pr[j].typ.size()==tp.size())
                {
                    int y=0;
                    for (int p=0;p<(int)tp.size();p++)
                    {
                        if (pr[j].typ[p]==0||pr[j].typ[p]==tp[p]) y++;
                    }
                    if (y==(int)tp.size()) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}