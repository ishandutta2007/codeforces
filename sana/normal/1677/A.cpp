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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vi left_big(n+1);
    vi right_small(n+1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) if (a[j] > a[i]) left_big[i]++;
        for (int j = i+1; j < n; j++) if (a[j] < a[i]) right_small[i]++;
    }
    
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) if (a[i] > a[j]) left_big[j]--;
        long long cur = 0;
        
        for (int j = i+1; j < n; j++) {
            cur -= left_big[j];
            if (a[i] < a[j]) {
                ans += cur;
                dbg(i, j, cur);
            }
            cur += right_small[j];
        }
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