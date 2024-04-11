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
    int n;
    cin >> n; n = 2*n;
    
    string s; cin >> s;
    
    vi pps(n+1);
    for (int i = 0; i < n; i++) {
        pps[i+1] = pps[i] + (s[i]=='(' ? 1 : -1);
    }
    dbg(pps);
    
    int ma = 0;
    for (int i = 0 ;i <= n; i++) if (pps[i] >= pps[ma]) ma = i;
    
    int bg = -1;
    int sm = n+1;
    for (int i = 0; i <= n; i++) if (pps[i] < 0) {
        bg = max(bg, i);
        sm = min(sm, i);
    }
    
    if (bg == -1) {
        ps(0);
        return;
    }
    
    int ma_l = 0;
    for (int l = 0; l < sm; l++) {
        if (pps[l] > pps[ma_l]) ma_l = l;
    }
    
    int ma_r = n;
    for (int r = bg+1; r <= n; r++) {
        if (pps[r] > pps[ma_r]) ma_r = r;
    }
    
    if (pps[ma_l] + pps[ma_r] >= pps[ma]) {
        ps(1);
        ps(ma_l+1, ma_r);
        return;
    }
    
    ps(2);
    ps(1, ma);
    ps(ma+1, n);
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