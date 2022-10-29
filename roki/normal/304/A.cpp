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

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;

inline void read()
{
    cin >> n;
}

inline void solve()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            int a = sqrt(i * i - j * j + 0.0);
            if(a > 0 && a <= j && a * a + j * j == i * i)
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