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

int n, m;

int cnt[100];
bool u[100][26];

inline void read()
{
    cin >> n >> m;
    forn (i, n)
        forn (j, m)
        {
            char c;
            cin >> c;
            if(!u[j][c - 'A'])
                u[j][c - 'A'] = true, cnt[j]++;
        }
}

inline void solve()
{
    li mod = 1e9 + 7;
    li ans = 1;
    forn (i, m)
        ans = ans * cnt[i] % mod;
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