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
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

typedef pair<ld, ld> pt;
#define ft first
#define sc second
#define x first
#define y second

const int N = 100 * 1000 + 50;
int n;
li k;
int a[N];

bool read() {
    if (!(cin >> n >> k))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

li p[N];
vector<li> b[N * 4];

void build(int v, int l, int r) {

    forn (i, r - l + 1) 
        b[v].pb(p[l + i]);
    sort(all(b[v]));

    if (l == r)
        return;

    int mid = (l + r) >> 1;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid + 1, r);
}

int get(int v, int l, int r, int lq, int rq, li val) {
    if (lq == l && rq == r)
        return b[v].end() - lower_bound(b[v].begin(), b[v].end(), val);
    int mid = (l + r) >> 1;
    if (rq <= mid)
        return get(2 * v + 1, l, mid, lq, rq, val);
    if (lq > mid)
        return get(2 * v + 2, mid + 1, r, lq, rq, val);
    return get(2 * v + 1, l, mid, lq, mid, val) + get(2 * v + 2, mid + 1, r, mid + 1, rq, val);
}

bool ok(li x) {
    li cnt = 0;
    forn (i, n) {
        li val = x + p[i];
        if (i + 1 < n)
            cnt += get(0, 0, n - 1, i + 1, n - 1, val);
        if (p[i] >= x)
            cnt++;
    }
    return cnt >= k;
}

void solve() {
    
    forn (i, n) {
        if (i)
            p[i] += p[i - 1];
        p[i] += a[i];
    }
        
    build(0, 0, n - 1);

    li l = -1e18, r = 1e18;

    while(r - l > 1) {
        li mid = (r + l) >> 1;
        if (ok(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
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