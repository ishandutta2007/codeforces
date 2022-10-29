#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
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

int n, k;

inline bool read()
{
    if(!(cin >> n >> k))
        return false;
    return true;
}

inline void solve()
{
    vector<int> ans[30];
    set<int> s;
    forn (i, n * k)
        s.insert(i + 1);
    forn (i, k)
    {
        int a;
        cin >> a;
        ans[i].pb(a);
        s.erase(a);
    }
    forn (i, k)
    {
        while(ans[i].size() < n)
        {
            ans[i].pb(*s.begin());
            s.erase(s.begin());
        }
    }
    forn (i, k)
    {
        forn (j, n)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(read())
        solve();
    return 0;
}