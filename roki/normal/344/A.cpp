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

int n;

bool read()
{
    if(!(cin >> n))
        return false;
    return true;
}

void solve()    
{
    string s;
    forn (i, n)
    {
        string p;
        cin >> p;
        s += p;
    }
    int ans = 1;
    forn (i, s.size() - 1)
    {
        if(s[i] == s[i + 1])
            ans++;
    }
    cout << ans << endl;
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