#pragma comment(linker, "/STACK:167177216")
 
#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>
 
using namespace std;
 
typedef long long li;
typedef long double ld;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li mod = 1e9 + 7;

li bp(li a, li b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return a * bp(a, b - 1) % mod;
    return bp(a * a % mod, b >> 1);
}

li a, b, n;

inline void read()
{
    cin >> a >> b >> n;
}

li f[1000001];
li ob[1000001];

bool ok (int q)
{
    while(q)
    {
        if(q % 10 != a && q % 10 != b)
            return false;
        q /= 10;
    }
    return true;
}

inline void solve()
{
    f[0] = 1;
    ob[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] * i % mod;
        ob[i] = bp(f[i], mod - 2);
    }
    
    li ans = 0;

    forn (i, n + 1)
    {
        int j = n - i;
        if(ok(j * a + i * b))
            ans = (ans + (f[n] * ob[i] % mod) * ob[n - i] % mod) % mod;
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