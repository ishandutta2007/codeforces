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
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
map<int, vector<int>> g;
set<int> st;

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        if(st.count(a) == 0)
            st.insert(a);
        else
            st.erase(a);
        if(st.count(b) == 0)
            st.insert(b);
        else
            st.erase(b);
    }
    return true;
}

void dfs(int v, int p = -1)
{
    cout << v << ' ';
    forn (i, g[v].size())
    {
        int to = g[v][i];
        if(to == p)
            continue;
        dfs(to, v);
    }
}

void solve()
{
    int s = *st.begin();
    dfs(s);
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}