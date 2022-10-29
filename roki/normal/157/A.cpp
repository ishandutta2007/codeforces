#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second

const int INF = 1e9;

int n;
int a[35][35];

bool read()
{
    if (!(cin >> n))
        return false;
    forn (i, n)
        forn (j, n)
        cin >> a[i][j];
}

void solve() 
{
    int ans = 0;
    forn (i, n)
        forn (j, n)
        {
            int cur = 0;
            forn (k, n)
                cur += a[k][j] - a[i][k];
            if (cur > 0)
                ans++;
        }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    while(read())
        solve();

    return 0;
}