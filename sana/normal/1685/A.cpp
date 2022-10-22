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


typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(all(a));
    
    vi b;
    if (n % 2 == 1) {
        for (int i = 0; i <= n/2; i++) {
            b.push_back(a[i]);
            if (i < n/2) b.push_back(a[i+n/2+1]);
        }
    }
    else {
        for (int i = 0; i < n/2; i++) {
            b.push_back(a[i]);
            b.push_back(a[i+n/2]);
        }
    }
    
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if ( (b[i] > b[(i+1)%n]) ^ (b[i] > b[(i+n-1)%n]) ) ok = false;
    }
    for (int i = 0; i < n; i++) {
        if ( b[i] == b[(i+1)%n] ) ok = false;
    }
    
    if (ok) {
        ps("YES");
        for (int x : b) pr(x, " ");
        ps();
        return;
    }
    else ps("NO");
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