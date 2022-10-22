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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#define each(a,x) for (auto& a: x)
#define tcT template<class T

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;


typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


bool check(vi d1, vi d2, map<int,int> m1, map<int,int> m2, int k) {
    dbg(k);
    vi houses;
    int n = sz(d1);
    while (sz(houses) < n) {
        while ( !m1[d1.back()] ) d1.pop_back();
        while ( !m2[d2.back()] ) d2.pop_back();
        dbg(d1,d2);
        
        if (d1.back() >= k && d1.back() >= d2.back()) {
            if (m2[d1.back() - k]) {
                houses.push_back(d1.back());
                m1[d1.back()]--;
                m2[d1.back() - k]--;
                d1.pop_back();
            }
            else break;
        }
        else if (d2.back() >= k) {
            if (m1[d2.back() - k]) {
                houses.push_back(k - d2.back());
                m1[d2.back() - k]--;
                m2[d2.back()]--;
                d2.pop_back();
            }
            else break;
        }
        else {
            if (m2[k - d1.back()]) {
                houses.push_back(d1.back());
                m1[d1.back()]--;
                m2[k - d1.back()]--;
                d1.pop_back();
            }
            else break;
        }
    }
    
    if (sz(houses) == n) {
        ps("YES");
        int disp = max(0, - (*min_element(all(houses))));
        for (int x : houses) pr(x+disp," ");
        ps();
        ps(disp, disp+k);
        return true;
    }
    
    return false;
}

void go() {
    ints(n);
    vi d1__(n), d2__(n);
    re(d1__,d2__);
    
    sort(all(d1__)); sort(all(d2__));
    
    map<int,int> m1__;
    map<int,int> m2__;
    
    for (int i = 0; i < n; i++) m1__[d1__[i]]++;
    for (int i = 0; i < n; i++) m2__[d2__[i]]++;
    
    for (int i = 0; i < n; i++) {
        int k;
        k = abs(d1__.back() - d2__[i]);
        
        if (check(d1__, d2__, m1__, m2__, k)) return;
        
        k = d1__.back() + d2__[i];
        
        if (check(d1__, d2__, m1__, m2__, k)) return;
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