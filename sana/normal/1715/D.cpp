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
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


using namespace std;
 

#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }

 
tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void solve()
{
    ints(n,q);
    
    vector< vi > g(n*30);
    vi a(n);
    
    for (; q; q--) {
        ints(i, j, x); i--; j--;
        
        for (int k = 0; k <= 29; k++) {
            if (!(x & (1<<k))) {
                a[i] |= (1<<k);
                a[j] |= (1<<k);
            }
            else {
                g[i*30 + k].push_back(j*30 + k);
                g[j*30 + k].push_back(i*30 + k);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int k = 29; k >= 0; k--) if (!(a[i] & (1<<k))) {
            bool ok = true;
            a[i] ^= (1<<k);
            
            for (int o : g[i*30 + k]) {
                int idx = o / 30, bit = o % 30;
                if (a[idx] & (1<<bit)) ok = false; 
            }
            
            if (!ok) a[i] ^= (1<<k);
        }
    }
    
    for (int x : a) pr(x ^ ((1<<30)-1), " ");
    ps();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}