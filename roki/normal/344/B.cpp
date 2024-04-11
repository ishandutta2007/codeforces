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
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int a, b, c;

bool read()
{
    if(!(cin >> a >> b >> c))
        return false;
    return true;
}

void solve()    
{
    for (int i = 0; i <= a; ++i)
    {
        int j = b - i;
        int k = c - j;
        if(k + i == a && j >= 0 && k >= 0)
        {
            cout << i << ' ' << j << ' ' << k << endl;
            return;
        }
    }
    cout << "Impossible";
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