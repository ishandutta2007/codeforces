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
 

void go() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    if (n < m) {
        cout << "NO" << '\n';
        return;
    }
    
    if (a.substr(a.size() - b.size() + 1, b.size() - 1) != b.substr(1)) {
        cout << "NO" << '\n';
        return;
    }
    
    if (std::find(a.begin(), a.begin() + (n - m + 1), b[0]) == (a.begin() + (n - m + 1))) {
        cout << "NO" << '\n';
        return;
    }
    
    cout << "YES" << '\n';
    return;
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