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
 

#define each(a,x) for (auto& a: x)
#define tcT template<class T


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


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


int node[4100000][2];
array<int, 4> opt[4100000];
int used;

int new_node() {
    node[used][0] = node[used][1] = -1;
    opt[used] = array<int,4>{0,0,0,0};
    return used++;
}

int bit(int n, int k) {
    return !!(n&(1<<k));
}

int find(int a, int i) {
    int cur = 0;
    int val = 0;
    
    for (int k = 29; k >= 0; k--) {
        if (cur == -1) break;
        
        int idx = (bit(i,k)<<1) + (bit(a,k)^1);
        dbg("checking val", cur, idx);
        val = max(val, opt[cur][ idx ]);
        
        cur = node[cur][bit(a,k) == bit(i,k)];
    }
    
    return val;
}

void add(int a, int i, int val) {
    int cur = 0;
    for (int k = 29; k >= 0; k--) {
        int idx = (bit(a,k)<<1) + bit(i,k);
        dbg("adding val", val, cur, idx);
        opt[cur][idx] = max(opt[cur][idx], val);
        
        if (node[cur][bit(a,k) == bit(i,k)] == -1) {
            node[cur][bit(a,k) == bit(i,k)] = new_node();
        }
        cur = node[cur][bit(a,k) == bit(i,k)];
    }
}

void go() {
    int n; re(n);
    vi a(n); re(a);
    
    used = 0;
    new_node();
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int val = find(a[i], i) + 1;
        
        add(a[i], i, val);
        ans = max(ans, val);
    }
    
    ps(ans);
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