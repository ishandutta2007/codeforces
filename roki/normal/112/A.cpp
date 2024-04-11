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

string a, b;

bool read()
{
    if (!(cin >> a >> b))
        return false;

    return true;
}

void solve()    
{
    int n = a.size();
    forn (i, n)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
        if (b[i] >= 'a' && b[i] <= 'z')
            b[i] -= 'a' - 'A';
        if (a[i] == b[i])
            continue;
        if (a[i] < b[i])
            cout << -1;
        else
            cout << 1;
        return;
    }
    cout << 0;
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