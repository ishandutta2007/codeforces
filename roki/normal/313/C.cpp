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
#define pb push_baack
#define mp make_pair

int n;
vector<int> v;

inline void read()
{
    scanf("%d", &n);
    v.resize(n);
    forn (i, n)
        scanf("%d", &v[i]);
    sort(v.rbegin(), v.rend());
}

inline void solve()
{
    li ans = 0;
    li sum = 0;
    int l = 0, r = 1;
    while(l < n)
    {
        while(l < r)
        {
            sum += v[l];
            l++;
        }
        ans += sum;
        r *= 4;
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