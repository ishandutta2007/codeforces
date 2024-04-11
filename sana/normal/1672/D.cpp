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
    
    vi a(n), b(n);
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> b[i];
    
    multiset<int> remove;
    
    int aloc = n-1;
    int la = -1;
    for (int i = n-1; i >= 0; i--) {
        if (b[i] == la) {
            remove.insert(la);
            continue;
        }
        
        while (a[aloc] != b[i]) {
            auto it = remove.find(a[aloc]);
            if (it == remove.end()) {
                ps("NO");
                return;
            }
            remove.erase(it);
            aloc--;
        }
        
        la = b[i];
        aloc--;
    }
    
    ps("YES");
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