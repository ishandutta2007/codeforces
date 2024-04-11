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


ll n, m;
ll pd[62][2][2][2][2][3];

ll rec(int x, int pa, int pb, int ca, int cb, int co) {
    //dbg(x);
    if (x == 61) {
        return (co == 0 && pa != pb);
    }
    
    ll &ret = pd[x][pa][pb][ca][cb][co];
    if (ret == -1) {
        ret = 0;
        
        for (int i = 0; i < 2; i++) {
            int nba = ( ca + i ) % 2;
            int nca = ( ca + i ) >= 2;
            int nbb = ( !!(n & (1LL<<x)) + cb + i ) % 2;
            int ncb = ( !!(n & (1LL<<x)) + cb + i ) >= 2;
            
            int nco = 1;
            int bm = !!(m&(1LL<<x));
            if (i > bm) nco = 2;
            else if (i < bm) nco = 0;
            else nco = co;
            
            ret += rec(x+1, (pa+nba)%2, (pb+nbb)%2, nca, ncb, nco);
        }
    }
    
    return ret;
}

void go() {
    re(n,m);
    dbg(n,m);
    memset(pd,-1,sizeof(pd));
    ps(rec(0, 0, 0, 0, 0, 1));
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