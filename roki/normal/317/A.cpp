#pragma comment(linker, "/STACK:167177216")
 
#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
 
using namespace std;
 
const int INF = 1e9;
 
typedef long long li;
typedef long double ld;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li a, b, c;

inline void read()
{
    cin >> a >> b >> c;
}
 
inline void solve()
{
    li ans = 0;
    if(a >= c || b >= c)
    {
        cout << 0;
        return;
    }
    if(a + b < 0 && (a + b == a || a + b == b))
    {
        cout << -1;
        return;
    }
    if(a == 0 && b == 0 && c > 0)
    {
        cout << -1;
        return;
    }
    if(b < 0)
        swap(a, b);
    if(a < 0 && b > 0)
    {
        ans = -a / b;
        a += b * ans;
    }
    while(a < c && b < c)
    {
        if(a < 0 && b < 0)
        {
            cout << -1;
            return;
        }
        if(a < b)
            a = a + b;
        else
            b = a + b;
        ans++;
    }
    cout << ans << endl;
}
 
int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}