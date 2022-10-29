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

int n, m;

vector<int> a;

inline void read()
{
    cin >> n >> m;
    a.resize(n);
    forn (i, n)
        cin >> a[i];
}

inline void solve()
{
    li sum;
    li fib[1000];
    li mod = 1e9;
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 1000; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    forn (i, m)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int q, w;
            cin >> q >> w;
            q--;
            a[q] = w;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            sum = 0;
            l--, r--;
            for (int j = l; j <= r; ++j)
                sum = (sum + fib[j - l] * a[j]) % mod;
            cout << sum << endl;
        }
    }
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