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
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;

bool read()
{
    if(!(cin >> n >> m))
        return false;
    return true;
}

int nt[300001];

int getNext(int v)
{
    return nt[v] != v ? nt[v] = getNext(nt[v]) : v;
}

void solve()
{
    vector<int> ans(n, 0);
    forn (i, n + 1)
        nt[i] = i;
    forn (I, m)
    {
        int l, r, w;
        cin >> l >> r >> w;
        l--, r--, w--;
        for (int i = getNext(l); i <= r; i = getNext(i))
            if(i != w)
                ans[i] = w + 1, nt[i] = i + 1;
            else
                i++;
    }
    forn (i, n)
        cout << ans[i] << ' ';
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