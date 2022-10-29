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
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;

bool read()
{
    if (!(cin >> n))
        return false;
    return true;
}

void solve()
{
    int ans = 0;
    int cur = 0;
    forn (i, n)
    {
        int h;
        cin >> h;
        if (cur > h)
            ans += cur - h, cur = h;
        ans += h - cur, cur = h;
    }
    cout << ans  + 2 * n - 1<< endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}