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
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int n;
const int N = 1000 * 1000 + 500;
int a[N];

bool read() {
    
    if (!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

int f[N];
const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a = a + b;
    while(a < 0)
        a += MOD;
    while(a >= MOD)
        a -= MOD;
}

void inc(int pos, int d) {
    for (; pos < N; pos |= pos + 1)
        add(f[pos], d);
}

int sum(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        add(res, f[pos]);
    return res;
}

int mul(int a, int b) {
    return li(a) * b % MOD;
}

int last[N];

void solve() {

    int ans = 0;
    inc(0, 1);
    
    int l = 0;
    forn (i, n) {
        int sub = last[a[i]];
        int t = sum(a[i]);
        add(t, -sub);
        add(last[a[i]], t);
        t = mul(t, a[i]);
        add(ans, t);
        inc(a[i], t);
    }

    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}