#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9);
const li INF64 = li(1e18);

int n;
int a[100];
int m;
int pl[20];
char t[20];
bool read() {
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    cin >> m;
    sort(a, a + n);
    reverse(a, a + n);
    n = min(n, 20);
    forn (i, m)
        cin >> t[i] >> pl[i];
}


int dp[1 << 20];

int calc(int mask, int step = 0)
{
    if (step == m)
        return 0;
    if (dp[mask] != -INF)
        return dp[mask];
    if (pl[step] == 2)
        dp[mask] = INF;
    forn (i, n)
    {
        if (mask & (1 << i))
            continue;
        if (pl[step] == 1)
            dp[mask] = max(dp[mask], calc(mask ^ (1 << i), step + 1) + (t[step] == 'p') * a[i]);
        else
            dp[mask] = min(dp[mask], calc(mask ^ (1 << i), step + 1) - (t[step] == 'p') * a[i]);
    }
    return dp[mask];
}
void solve() {
    forn (i, 1 << 20)
        dp[i] = -INF;

    cout << calc(0) << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while (read())
        solve();

    return 0;
}