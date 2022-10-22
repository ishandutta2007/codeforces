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
    cin >> n;
    vi a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> bg(n);
    vector<int> sm(n);
    
    for (int i = n-1; i >= 0; i--) {
        bg[i] = sm[i] = i+1;
        while (bg[i] != n && a[bg[i]] <= a[i]) bg[i] = bg[bg[i]];
        while (sm[i] != n && a[sm[i]] >= a[i]) sm[i] = sm[sm[i]];
    }
    
    int cnt = 0;
    int cur = 0;
    while (cur < n-1) {
        if (a[cur+1] > a[cur]) {
            int d = cur+1;
            while (bg[d] < sm[cur]) d = bg[d];
            cur = d;
            
            cnt++;
        }
        else {
            int d = cur+1;
            while (sm[d] < bg[cur]) d = sm[d];
            cur = d;
            
            cnt++;
        }
    }
    
    ps(cnt);
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