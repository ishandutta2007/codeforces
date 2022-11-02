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
    PII a[1000];
    bool cmp(int i, int j)
    {
        return a[i].y<a[j].y||(a[j].y==a[i].y&&a[i].x>a[j].x);
    }

    int main()
    {
        in(n);in(k);

        int o[1000];
        int tab = 0;
        forn(i,n)
        {
            a[i].x = 2*nxt();
            a[i].y = nxt();
            if (a[i].y==1)
                tab++;
            o[i] = i;
        }
        int r = min(k-1,tab);
        sort(o,o+n,cmp);
        //forn(i,n) cout << o[i] << " ";
        ll ans = 0;
        VVI q(k);
        int p = 0;
        forn(i,r)
        {
            ans+=a[o[i]].x/2;
            q[p++].pb(o[i]+1);
        }
        int mi = a[r].x;
        For(i,r,n-1)
        {
            mi = min(mi,a[o[i]].x);
            ans+=a[o[i]].x;
            if (p<k-1)
                q[p++].pb(o[i]+1);
            else
                q[p].pb(o[i]+1);
        }
        if (tab>k-1)
            ans-=mi/2;
        if (ans&1)
            cout << ans/2 << ".5\n";
        else
            cout << ans/2 << ".0\n";
        forn(i,k)
        {
            cout << (int)q[i].size() << " ";
            fori(it,q[i])
                cout << *it << " ";
            cout << endl;
        }

        return 0;
    }