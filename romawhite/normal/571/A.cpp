#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100000;
const int MAX2 = 10000;
const int MAX3 = 100000;
const int BASE = 1000000000;
const int MOD = 1000000007;

Int sum(Int n)
{
    if (n < 0) return 0;
    return 1LL * (n + 1)* (n + 2) / 2;
}

Int f(Int b1, Int c1, Int s1)
{
    return sum(s1) - sum(s1 - b1 - 1) - sum(s1 - c1 - 1) + sum(s1 - b1 - c1 - 2);
}

Int solve1(int a, int b, int c, int l)
{
    int addb = a - 1 - b;
    int addc = a - 1 - c;
    if (addb < 0 || addc < 0) return 0;
    

    int minadd = a + 1 - b - c;
    if (minadd < 0) minadd = 0;
    int maxadd = l;
    if (minadd > maxadd) return 0;
    //cout << addb << ' ' << addc << ' ' << minadd << ' ' << maxadd << endl;
    //cout << f(addb , addc , maxadd) << ' ' <<  f(addb , addc , minadd - 1) << endl;
    return f(addb , addc , maxadd) - f(addb , addc , minadd - 1);
}

int main()
{   
    //freopen("in.txt","r",stdin);
    
    solve1(2,1,1,1);
    
    int a , b , c , l;
    cin >> a >> b >> c >> l;
    Int res = 0;
    FOR(i,0,l + 1)
    {
        res += solve1(a + i , b , c , l - i);
        //cout << i << ' ' << res << endl;
        res += solve1(b + i , a , c , l - i);
        //cout << i << ' ' << res << endl;
        res += solve1(c + i , b , a , l - i);
        //cout << i << ' ' << res << endl;
    }
    //cout << res << endl;
    FOR(i,0,l + 1)
    {
        int aa = a + i;
        int bb = aa;
        if (bb >= b)
        {
            int ll = l - i - (bb - b);
            ll = min(ll, aa - 1 - c);
            if (ll >= 0) res += ll + 1;
        }
    }
    FOR(i,0,l + 1)
    {
        int aa = a + i;
        int cc = aa;
        if (cc >= c)
        {
            int ll = l - i - (cc - c);
            ll = min(ll, aa - 1 - b);
            if (ll >= 0) res += ll + 1;
        }
    }
    FOR(i,0,l + 1)
    {
        int bb = b + i;
        int cc = bb;
        if (cc >= c)
        {
            int ll = l - i - (cc - c);
            ll = min(ll, bb - 1 - a);
            if (ll >= 0) res += ll + 1;
        }
    }
    
    FOR(i,0,l + 1)
    {
        int aa = a + i;
        int bb = aa;
        int cc = aa;
        if (bb >= b && cc >= c)
        {
            int ll = l - i - (bb - b) - (cc - c);
            if (ll >= 0) ++res;
        }
    }
    
    cout << res << endl;
}