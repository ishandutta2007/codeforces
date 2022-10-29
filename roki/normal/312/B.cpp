#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
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

ld a, b, c, d;

inline void read()
{
    cin >> a >> b >> c >> d;
}

inline void solve()
{
    ld prob = 1;
    ld ans = 0;
    forn (i, 100000)
    {
        if(i & 1)
            prob *= 1 - c / d;
        else
        {
            ans += prob * a / b;
            prob *= 1 - a / b;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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