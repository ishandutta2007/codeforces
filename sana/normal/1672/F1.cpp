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


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }

 
void go() {
    int n; cin >> n; 
    vi a(n); 
    REP(i, n) cin >> a[i];
    
    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    
    vi b(n);
    int t = 0;
    while (t != n) {
        vi cyc;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            cyc.push_back( it->second.back() );
        }
        
        for (int i = 0; i < sz(cyc); i++) {
            b[ cyc[(i+1) % sz(cyc)] ] = a[cyc[i]];
        }
        
        vi rem;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            it->second.pop_back();
            if (it->second.empty()) rem.push_back(it->first);
        }
        
        for (auto a : rem) mp.erase(a);
        t += sz(cyc);
    }
    
    for (auto a : b) {cout << a << " ";}
    ps();
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