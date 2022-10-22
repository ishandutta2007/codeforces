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
 
 
vector<long long> fib;
 
void go() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n >= 45) {
        cout << "NO" << '\n';
        return;
    }
    
    vector< vector<int> > c(n);
    int cnt = 0;
    
    set< pair<int, int> > al;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = fib.size() - 1; j >= 0; j--) {
            if (fib[j] <= x) {
                x -= fib[j];
                c[i].push_back(j);
                al.insert({j, i});
            }
        }
        sort(all(c[i]));
    }
    
    
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (c[i][0] % 2 == 1) {
            al.erase({c[i][0], i});
            for (int j = 0; j < c[i][0]; j+=2) al.insert({j, i});
            
            bool tok = true;
            int la = -1;
            for (auto [a,b] : al) {
                if (a != la+1) tok = false;
                la = a;
            }
            ok = (ok || tok);
            
            for (int j = 0; j < c[i][0]; j+=2) al.erase({j, i});
            al.insert({c[i][0], i});
        }
    }
    
    cout << (ok ? "YES" : "NO") << '\n';
}
 
void solve()
{
    fib.push_back(1);
    fib.push_back(1);
    while (fib.back() < 1000000000) {
        fib.push_back(fib.back() + fib[fib.size() - 2]);
    }
    
     int t;
     for (cin >> t; t; t--) go();
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
    return 0;
}