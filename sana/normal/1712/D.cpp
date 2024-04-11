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


#define each(a,x) for (auto& a: x)
#define tcT template<class T

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


int check(vi a,  int diam) {
    int n = sz(a);
    
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (2*a[i] < diam) {
            a[i] = 1000000000;
            ret++;
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        if ( min(a[i], a[i+1]) >= diam) return ret;
    }
    
    for (int i = 0; i < n; i++) if (a[i] >= diam) return ret+1;
    
    return ret+2;
}

void go() {
    ints(n,k);
    vi a(n); re(a);
    
    int st = 1, ed = 1000000000;
    while (st < ed) {
        int m = (st+ed+1)/2;
        if (check(a, m) <= k) st=m;
        else ed = m-1;
    }
    
    ps(st);
}

void solve()
{
    ints(t);
    for (; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}