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


void solve()
{
    ints(n,m);
    vi a(n);
    re(a);
    
    long long ans = n*1ll*(n+1)/2;
    vector<long long> border(n-1);
    for (int i = 0; i < n-1; i++) if (a[i] != a[i+1]) {
        border[i] = (i+1) * 1ll * (n-(i+1)); 
        ans += border[i];
    }
    
    for (; m; m--) {
        ints(idx,x); idx--;
        
        for (int i = max(0, idx-1); i <= min(n-2, idx+1); i++) if (a[i] != a[i+1]) {
            ans -= border[i];
            border[i] = 0;
        }
        
        a[idx] = x;
        for (int i = max(0, idx-1); i <= min(n-2, idx+1); i++) if (a[i] != a[i+1]) {
            border[i] = (i+1) * 1ll * (n-(i+1)); 
            ans += border[i];
        }
        ps(ans);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}