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
#define tcTU tcT, class U
#define tcTUU tcT, class ...U
 
template<class T, size_t SZ> using AR = array<T,SZ>;

typedef string str;

typedef pair<int, int> pii;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcTU> void re(pair<T,U>& p);

tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }

tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n);
    array< pii, 3> ar;
    re(ar);
    pii dest;
    re(dest);
    
    bool ok = false;
    for (int i = 0; i < 3; i++) {
        if (dest.first % 2 == ar[i].first % 2 && dest.second % 2 == ar[i].second % 2) ok = true;
    }
    
    sort(all(ar));
    array<pii, 3> cn1 = { pii{1,1}, pii{1,2}, pii{2,1} };
    array<pii, 3> cn2 = { pii{1,n-1}, pii{1,n}, pii{2,n} };
    array<pii, 3> cn3 = { pii{n-1,1}, pii{n,1}, pii{n,2} };
    array<pii, 3> cn4 = { pii{n-1,n}, pii{n,n-1}, pii{n,n} };
    
    if (ar == cn1 && dest.first != 1 && dest.second != 1) ok = false;
    if (ar == cn2 && dest.first != 1 && dest.second != n) ok = false;
    if (ar == cn3 && dest.first != n && dest.second != 1) ok = false;
    if (ar == cn4 && dest.first != n && dest.second != n) ok = false;
    
    ps(ok ? "YES" : "NO");
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