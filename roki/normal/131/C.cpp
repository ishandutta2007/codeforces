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

int a, b, c;

inline void read()
{
    cin >> a >> b >> c;
}

li C[100][100];

inline void solve()
{
    forn (i, 100)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    li ans = 0;
    for (int i = 4; i < c; ++i)
    {
        int j = c - i;
        if(j > b || i > a)
            continue;
        ans += C[a][i] * C[b][j];
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