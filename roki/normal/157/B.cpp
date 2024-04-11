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
vector<ld> a;

bool read()
{
    if (!(cin >> n))
        return false;
    a.resize(n);
    forn (i, n)
        cin >> a[i];
}

void solve() 
{
    sort(a.rbegin(), a.rend());
    ld ans = 0;
    forn (i, n)
        ans += (i & 1 ? -1 : 1) * M_PI * a[i] * a[i];
    cout << fixed << setprecision(10) << ans << endl;
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