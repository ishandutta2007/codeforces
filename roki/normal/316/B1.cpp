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
#define pb push_back
#define mp make_pair

int n, x;

vector<int> nextto;
vector<int> bef;

inline void read()
{
    cin >> n >> x;
    x--;
    nextto = vector<int> (n, -1);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        a--;
        bef.pb(a);
        if(a != -1)
            nextto[a] = i;
    }
}

int dp[30001];

inline void solve()
{
    int gpos, gsz;
    vector<int> sz;
    vector<bool> u(n, false);
    for (int i = 0; i < n; ++i)
    {
        if(bef[i] == -1)
        {
            int cur = i;
            int pos = 1;
            while(i != -1)
            {
                u[i] = true;
                if(i == x)
                {
                    gpos = pos;
                    gsz = sz.size();
                }
                i = nextto[i];
                pos++;
            }
            sz.pb(pos - 1);
            i = cur;
        }
    }
    dp[0] = 1;
    for (int j = 0; j < sz.size(); ++j)
    {
        if(j == gsz)
            continue;
        for (int i = n; i >= 0; --i)
            if(dp[i])
                dp[i + sz[j]] = 1;
    }
    for (int i = 0; i < n; ++i)
        if(dp[i])
            cout << i + gpos << endl;
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