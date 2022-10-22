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

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;


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


void go() {
    ints(n,k); k--;
    vector<ll> a(n); re(a);
    
    vector< pair<ll, ll> > vl, vr;
    pair<ll, ll> reml, remr;
    {
        ll cur = 0;
        ll curmin = 0;
        for (int i = k-1; i >= 0; i--) {
            cur += a[i];
            curmin = min(curmin, cur);
            if (cur >= 0) {
                vl.push_back({cur, curmin});
                cur = 0;
                curmin = 0;
            }
        }
        reml.first = cur; reml.second = curmin;
    }
    {
        ll cur = 0;
        ll curmin = 0;
        for (int i = k+1; i < n; i++) {
            cur += a[i];
            curmin = min(curmin, cur);
            if (cur >= 0) {
                vr.push_back({cur, curmin});
                cur = 0;
                curmin = 0;
            }
        }
        remr.first = cur; remr.second = curmin;
    }
    
    reverse(all(vl));
    reverse(all(vr));
    
    ll cur = a[k];
    while ((!vl.empty() && cur + vl.back().second >= 0) || 
           (!vr.empty() && cur + vr.back().second >= 0)) {
        
        if (!vl.empty() && cur + vl.back().second >= 0) {
            cur += vl.back().first;
            vl.pop_back();
        }
        
        if (!vr.empty() && cur + vr.back().second >= 0) {
            cur += vr.back().first;
            vr.pop_back();
        }
    }
    
    if (vl.empty() && cur + reml.second >= 0) {
        ps("YES");
        return;
    }
    if (vr.empty() && cur + remr.second >= 0) {
        ps("YES");
        return;
    }
    ps("NO");
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