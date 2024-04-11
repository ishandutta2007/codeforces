#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-9;

typedef pair<int, int> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

int n;
const int N = 100000 + 50;
int a[N];

bool read() {
    cin >> n;
    forn (i, n)
        cin >> a[i];
    return false;
}

li dp[N];

void add(int pos, li d) {
    for (int i = pos; i < N; i |= i + 1)
        dp[i] = max(dp[i], d);
}

li get(int pos) {
    li res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
        res = max(res, dp[i]);
    return res;
}

li b[N];

void solve() {
    
    sort(a, a + n);
    
    li ans = 0;

    forn (i, n) {
        li val = get(a[i] - 2);
        val = max(val, b[a[i]]);
        b[a[i]] = max(b[a[i]], val + a[i]);
        add(a[i], b[a[i]]);
        ans = max(ans, b[a[i]]);
    }

    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    read();
    solve();

    return 0;
}