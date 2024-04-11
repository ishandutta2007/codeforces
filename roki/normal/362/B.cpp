#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;
int a[10000];

bool read()
{
    if (!(cin >> n >> m))
        return false;
    forn (i, m)
        cin >> a[i];
    return true;
}


void solve()    
{
    sort(a, a + m);
    if (m > 0 && (a[0] == 1 || a[m - 1] == n))
    {
        cout << "NO";
        return;
    }
    forn (i, m - 2)
        if (a[i] + 1 == a[i + 1] && a[i] + 2 == a[i + 2])
        {
            cout << "NO";
            return;
        }
        cout << "YES";
}
    
int main()
{
#ifdef SU6
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
        read();
        solve();
    return 0;
}