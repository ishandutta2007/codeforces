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

int n, k;
const int N = 2 * 100 * 1000 + 500;
li a[N];

bool read() {

    if (!(cin >> n >> k))
        return false;
    forn (i, n)
        cin >> a[i];

    return true;
}

void solve() {
    li prv = 0;
    li cur = 1;
    li m = n;

    forn (i, n) {
        li d = prv - (m - cur) * a[i] * (cur - 1);
        if (d < k) {
            cout << i + 1 << endl;
            m--;
        } else {
            prv += a[i] * (cur - 1);
            cur++;
        }
    }
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