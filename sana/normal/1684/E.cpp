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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n, k;
    cin >> n >> k;
    
    set<int> s;
    
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    
    int ok = k;
    
    int mex = 0;
    for (int i = 0; ; i++) {
        if (s.count(i)) mex++;
        else if (k) {
            k--;
            mex++;
        }
        else break;
    }
    
    k = ok;
    
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mex) m[a[i]]++;
    }
    
    vi vals;
    for (auto [a,b]: m) vals.push_back(b);
    sort(all(vals));
    
    int diff = sz(vals);
    for (int x : vals) {
        if (k < x) break;
        k -= x;
        diff--;
    }
    
    ps(diff);
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