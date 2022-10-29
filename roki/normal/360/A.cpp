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
vector< vector<int> > zapr;

bool read()
{
    if (!(cin >> n >> m))
        return false;
    zapr.resize(m);
    forn (i, m)
    {
        forn (j, 4)
        {
            int a;
            cin >> a;
            zapr[i].pb(a);
        }
        zapr[i][1]--;
        zapr[i][2]--;
    }
    return true;
}

void solve()
{
    vector<int> ans(n, 1e9);
    for (int i = m - 1; i >= 0; --i)
    {
        if (zapr[i][0] == 1)
        {
            for (int j = zapr[i][1]; j <= zapr[i][2]; ++j)
                ans[j] = min(1000000000, ans[j] - zapr[i][3]);
        }
        else
        {
            for (int j = zapr[i][1]; j <= zapr[i][2]; ++j)
                ans[j] = min(ans[j], zapr[i][3]);
        }
    }
    vector<int> check (ans);
    bool ok = true;
    forn (i, m)
    {
        if (zapr[i][0] == 1)
        {
            for (int j = zapr[i][1]; j <= zapr[i][2]; ++j)
                ans[j] += zapr[i][3];
        }
        else
        {
            int res = -1e9;
            for (int j = zapr[i][1]; j <= zapr[i][2]; ++j)
                res = max(res, ans[j]);
            if (res != zapr[i][3] || res > 1e9)
                ok = false;
        }
    }
    if (ok)
    {
        cout << "YES" << endl;
        forn (i, n)
        cout << check[i] << ' ';
    }
    else
        cout << "NO" << endl;
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