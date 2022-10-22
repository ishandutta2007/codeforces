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
 

typedef string str;


typedef vector<int> vi;
 

#define ts to_string
str ts(char c) { return str(1,c); }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }


void go() {
    int rows, cols; cin >> rows >> cols;
    
    string board;
    cin >> board;
    
    vi ans(rows*cols);
    
    vi col_is_serious(cols);
    int serious_cols = 0;
    for (int i = 0; i < rows*cols; i++) {
        int cur_col = (i % cols);
        if (board[i] == '1') {
            if (!col_is_serious[cur_col]) {
                col_is_serious[cur_col] = 1;
                serious_cols++;
            }
        }
        
        ans[i] += serious_cols;
    }
    
    vi row_is_serious(rows*cols);
    
    int last_1 = -2*cols;
    for (int i = 0; i < rows*cols; i++) {
        if (board[i] == '1') last_1 = i;
        row_is_serious[i] = (last_1 > i - cols);
    }
    
    vi tot_rows(cols);
    
    for (int i = 0; i < rows*cols; i++) {
        tot_rows[i % cols] += row_is_serious[i];
        ans[i] += tot_rows[i % cols];
        pr(ans[i], " \n"[i==rows*cols-1]);
    }
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}