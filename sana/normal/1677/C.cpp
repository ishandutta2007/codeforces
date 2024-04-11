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
 

typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n; cin >> n;
    
    vi pa(n), pb(n);
    for (int i = 0; i < n; i++) {
        cin >> pa[i];
        pa[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> pb[i];
        pb[i]--;
    }
    
    vi loca(n);
    for (int i = 0; i < n; i++) loca[ pa[i] ] = i;
    
    int db = 0;
    int sn = 0;
    
    vi seen(n);
    for (int i = 0; i < n; i++) if (!seen[i]) {
        int cur = i;
        int cnt = 0;
        
        while (!seen[cur]) {
            seen[cur] = 1;
            cnt++;
            cur = loca[ pb[cur] ];
        }
        
        db += cnt/2;
    }
    
    int sm = 1;
    int bg = n;
    
    long long ans = 0;
    for (int i = 0; i < db; i++) {
        ans += 2 * (bg - sm);
        bg--; sm++;
    }
    for (int i = 0; i < sn; i++) {
        ans += (bg - sm);
        bg--; sm++;
    }
    ps(ans);
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