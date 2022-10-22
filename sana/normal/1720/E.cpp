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


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


int a[510][510];
int al[251000];
int tmp[251000];

void solve()
{
    memset(al,0,sizeof(al));
    
    ints(n,k);
    int df = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            re(a[i][j]);
            if (++al[ a[i][j] ] == 1) df++;
        }
    }
    
    if (df <= k) {
        ps(k-df);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        memcpy(tmp, al, sizeof(al));
        int tdf = df;
        int bx = i, by = n-1;
        int xr = i, yr = n-1;
        
        for (int d = 0; d <= min(bx, by); d++) {
            for (int x = 0; x < d; x++) if (--tmp[ a[bx - x][by - d] ] == 0) tdf--;
            for (int x = 0; x <= d; x++) if (--tmp[ a[bx - d][by - x] ] == 0) tdf--;
            
            while (tdf < k-1) {
                for (int x = 1; x <= d; x++) if (++tmp[ a[bx - x][by] ] == 1) tdf++;
                for (int x = 0; x <= d; x++) if (++tmp[ a[bx][by - x] ] == 1) tdf++;
                bx--; by--;
                d--;
            }
            
            if (tdf == k || tdf == k-1) {
                ps(1);
                return;
            }
            
            xr--; yr--;
        }
    }
    
    for (int j = 0; j < n; j++) {
        memcpy(tmp, al, sizeof(al));
        int tdf = df;
        int bx = n-1, by = j;
        int xr = n-1, yr = j;
        
        for (int d = 0; d <= min(bx, by); d++) {
            for (int x = 0; x < d; x++) if (--tmp[ a[bx - x][by - d] ] == 0) tdf--;
            for (int x = 0; x <= d; x++) if (--tmp[ a[bx - d][by - x] ] == 0) tdf--;
            
            while (tdf < k-1) {
                for (int x = 1; x <= d; x++) if (++tmp[ a[bx - x][by] ] == 1) tdf++;
                for (int x = 0; x <= d; x++) if (++tmp[ a[bx][by - x] ] == 1) tdf++;
                bx--; by--;
                d--;
            }
            
            if (tdf == k || tdf == k-1) {
                ps(1);
                return;
            }
            
            xr--; yr--;
        }
    }
    
    ps(2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}