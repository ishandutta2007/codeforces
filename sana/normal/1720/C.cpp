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

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;


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
    ints(n,m);
    vector<string> board(n);
    re(board);
    
    bool z = false, z2 = false;
    int o = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) if (dx != 0 || dy != 0) {
                    int nx = i+dx, ny = j+dy;
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if (board[i][j] == board[nx][ny] && board[i][j]=='0') z2 = true;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == board[i+1][j] && board[i][j]=='0') z2 = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') z = true;
            else o++;
        }
    }
    
    if (z2) ps(o);
    else if (z) ps( max(0, o-1) );
    else ps(max(0, o-2));
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