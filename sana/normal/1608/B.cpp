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
 

#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n,a,b);
    
    if (abs(a-b) > 1 || a+b > n-2) {
        ps(-1);
        return;
    }
    
    vi x(n-1);
    x[0] = (a > b) ? 1 : -1;
    
    for (int i = 1; i < n-1; i++) {
        if (a+b > 0) {
            x[i] = -x[i-1];
            if (x[i] == -1) b--;
            else a--;
        }
        else x[i] = x[i-1];
    }
    
    vi p(n);
    p[0] = 0;
    int sm = 0, bg = 0;
    for (int i = 1; i < n; i++) {
        if (x[i-1] == 1) p[i] = ++bg;
        else p[i] = --sm;
    }
    for (int i = 0; i < n; i++) p[i] -= sm-1;
    
    for (int x : p) pr(x, " ");
    ps();
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