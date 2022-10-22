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


void go() {
    ints(n);
    vi a(n); re(a);
    
    array<int, 2> cnt;
    cnt[0]=cnt[1] =0;
    for (int i = 0; i < n; i++) {
        cnt[abs(a[i])%2]++;
    }
    
    int s = (cnt[1]/2);
    cnt[1]%=2;
    cnt[0]%=2;
    
    s += cnt[1];
    s %= 2;
    ps( (s == 0 || (cnt[0]&&cnt[1])) ? "Alice" : "Bob");
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