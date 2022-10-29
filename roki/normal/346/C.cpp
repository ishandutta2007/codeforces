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

int n;
int c[100000];
int a, b;

bool read()
{
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> c[i];
    cin >> a >> b;
    return true;
}

void solve()    
{
    int ans = 0;
    sort(c, c + n);
    n = unique(c, c + n) - c;
    while (a > b)
    {
        int nt = a - 1;
        forn (i, n)
        {
            int cur = a - a % c[i];
            if (cur < b)
            {
                c[i--] = c[--n];
                continue;
            }
            nt = min(cur, nt);
        }
        ans++;
        a = nt;
    }
    cout << ans << endl;
}
    
int main()
{

    while(read())
        solve();
    
    return 0;
}