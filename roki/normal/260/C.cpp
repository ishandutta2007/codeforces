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
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, x;
int a[100000];

inline bool read()
{
    if (!(cin >> n >> x))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

inline void solve()
{
    li ans[100000];
    int minv = 1e9;
    forn (i, n)
        ans[i] = a[i], minv = min(minv, a[i]);
    li cnt = (minv - 1LL) * li(n);
    forn (i, n) 
        ans[i] -= minv - 1;
    x--;
    while(ans[x]-- != 0)
    {
        x--;
        if(x == -1)
            x = n - 1;
        cnt++;
    }
    ans[x] = cnt;
    forn (i, n)
        cout << ans[i] << ' ';
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