#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

map<int, int> m;
int n;
int ans = 0;

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
    {
        int b;
        cin >> b;
        if(b)
        {
            m[b]++;
            if(m[b] == 2)
                ans++;
            if(m[b] > 2)
            {
                ans = -1;
                break;
            }
        }
    }
    return true;
}

void solve()
{
    cout << ans << endl;
}

int main()
{
    read();
    solve();
    return 0;
}