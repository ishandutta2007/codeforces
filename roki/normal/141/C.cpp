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

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
vector< pair<int, string> > v;

int num[100011];

inline void read()
{
    cin >> n;
    forn (i, n)
    {
        string name;
        int p;
        cin >> name >> p;
        num[p]++;
        v.pb(mp(p, name));
    }
    sort(v.begin(), v.end());
}

inline void solve()
{
    vector<pair<string, int>> h;
    int res = 0;
    forn (i, n)
    {
        if(v[i].first > i)
        {
            cout << -1;
            return;
        }
        h.insert(h.begin() + v[i].first, mp(v[i].second, n - res++));
    }
    forn (i, n)
        cout << h[i].first << ' ' << h[i].second << endl;
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