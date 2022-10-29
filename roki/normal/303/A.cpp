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
    if(n % 2 == 0)
    {
        cout << -1;
        return;
    }
    vector<int> a(n), b(n), c(n);
    forn (i, n)
        a[i] = i, b[i] = (i + 1) % n;
    forn (i, n)
        printf("%d ", a[i]);
    cout << endl;
    forn (i, n)
        printf("%d ", b[i]);
    cout << endl;
    forn (i, n)
        printf("%d ", (a[i] + b[i]) % n);
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