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
 

#define all(x) begin(x), end(x)


#define each(a,x) for (auto& a: x)
#define tcT template<class T


template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;

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


void go() {
    ints(n);
    vi a(n); re(a);
    
    int m = *min_element(all(a));
    int l = 2*m-1;
    
    ll ans = 0;
    for (int x : a) ans += (x+l-1) / l;
    
    ps(ans - n);
}

void solve()
{
    int t;
    for (re(t); t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}