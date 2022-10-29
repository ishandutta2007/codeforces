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

int n;

inline bool read()
{
    if(!(cin >> n))
        return false;
    return true;
}

inline void solve()
{
    set<int> s;
    queue<pair<int, pair<int, int>>> q;
    forn (i, 10)
        forn (j, 10)
        if(i != j)
            q.push(mp(0, mp(i, j)));
    while(!q.empty())
    {
        li v = q.front().first;
        int c[] = {q.front().second.first, q.front().second.second};
        q.pop();
        forn (i, 2)
        {
            li nt = v * 10 + c[i];
            if(nt > n || nt == v)
                continue;
            q.push(mp(nt, mp(c[0], c[1])));
        }
        s.insert(v);
    }
    cout << s.size() - 1 << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(read())
        solve();
    return 0;
}