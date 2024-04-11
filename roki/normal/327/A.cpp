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

int n;

vector<int> a;

int cur = 0;
int ans = 0;

inline void read()
{
    cin >> n;
    a.resize(n);
    forn (i, n)
    {
        cin >> a[i];
        cur += a[i];
    }
}

inline void solve()
{

    forn (l, n)
        for (int r = l; r < n; ++r)
        {
            int tek = cur;
            for (int i = l; i <= r; ++i)
                if(a[i] == 0)
                    tek++;
                else
                    tek--;
            ans = max(ans, tek);
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