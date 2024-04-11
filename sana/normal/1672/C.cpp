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
 

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

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
    REP(i,n) cin >> a[i];
    
    int cnt = 0;
    int loc = -1;
    int la = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || a[i] != a[la]) {
            if (i-la >= 2) {
                if (loc==-1) {
                    if (i-la <= 3) {
                        cnt += i-la-2;
                        loc = i-1;
                    }
                    else {
                        cnt += i-la-3;
                        loc = i-2;
                    }
                }
                else {
                    cnt += (i-loc-2);
                    loc = i-2;
                }
            }
            la = i;
        }
    }
    
    ps( cnt );
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