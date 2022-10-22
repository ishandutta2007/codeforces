#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>
 
 
using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

typedef vector<int> vi;
 

void go() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    
    set<int> b = {0};
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (b.count(c ^ a[i])) {
            b = {0};
            c = 0;
            continue;
        }
        
        ans++;
        c ^= a[i];
        b.insert(c);
    }
    
    cout << ans << '\n';
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}