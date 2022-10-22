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
 

#define all(x) begin(x), end(x)


typedef vector<int> vi;
 

void go() {
    int n, m; 
    cin >> n >> m;
    
    vi a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(all(a));
    
    vi inters(m);
    for (int i = 0; i < m-1; i++) {
        inters[i] = a[i+1] - a[i] - 1;
    }
    inters[m-1] = (a[0]+n) - a[m - 1] - 1;
    
    sort(all(inters));
    int safe = 0;
    
    int day = 0;
    for (int i = m-1; i >= 0; i--) {
        int cur_size = inters[i] - day*2;
        
        if (cur_size >= 3) {
            safe += cur_size - 1; 
            day += 2;
        }
        else if (cur_size >= 1) {
            safe += 1;
            day += 1;
        }
    }
    
    cout << n-safe << '\n';
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