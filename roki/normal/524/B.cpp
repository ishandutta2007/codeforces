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
 
const int N = 1005;
 
int n, w[N], h[N];
 
bool read() {
    if (!(cin >> n))
        return false;
    forn(i, n) {
        cin >> w[i] >> h[i];
    }
    return true;
}
 
void solve() {
    li res = 1e10;
    for (int H = 0; H <= 1000; ++H) {
        bool good = true;
        li W = 0;
 
        forn(i, n) {
            if (min(w[i], h[i]) > H) {
                good = false;
                break;
            }
 
            if (max(w[i], h[i]) <= H)
                W += min(w[i], h[i]);
            else
                W += max(w[i], h[i]);
        }
 
        if (good)
            res = min(res, W * H);
    }
 
    cout << res << endl;
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