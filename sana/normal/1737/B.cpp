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
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


void go() {
    ll a, b;
    re(a,b);
    
    ll lowsq, hisq;
    {
        ll st = 0, ed = 1000000000LL;
        while (st < ed) {
            ll m = (st+ed)/2;
            if (m*m < a) st = m+1;
            else ed = m;
        }
        lowsq = st; 
    }
    {
        ll st = 0, ed = 1000000000LL;
        while (st < ed) {
            ll m = (st+ed+1)/2;
            if (m*m > b) ed = m-1;
            else st = m;
        }
        hisq = st; 
    }    
    
    ll ans = (hisq - lowsq) * 3;
    
    if (lowsq != 1) {
        if ((lowsq-1)*(lowsq-1) >= a) ans++;
        if ((lowsq-1)*(lowsq) >= a) ans++;
        if ((lowsq-1)*(lowsq+1) >= a) ans++;
    }
    if ((hisq)*(hisq) <= b) ans++;
    if ((hisq)*(hisq+1) <= b) ans++;
    if ((hisq)*(hisq+2) <= b) ans++;
    
    ps(ans);
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