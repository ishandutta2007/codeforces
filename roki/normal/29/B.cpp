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
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

ld l, d, v, g, r;

bool read()
{
    if(!(cin >> l >> d >> v >> g >> r))
        return false;
    return true;
}

void solve()
{
    ld ans = l / v;
    ld t = d / v;
    int q = t / (g + r);
    t -= q * (g + r);
    if(t >= g - 1e-8)
        ans += r - t + g;
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}