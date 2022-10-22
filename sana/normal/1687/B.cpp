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
 

#define all(x) begin(x), end(x)


typedef string str;


#define ts to_string
str ts(char c) { return str(1,c); }

str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

int m;

int query(vector<int> v) {
    string s(m, '0');
    for (int x : v) s[x] = '1';

    ps('?', s);
    cout.flush();
    
    int x;
    cin >> x;
    return x;
}

void solve()
{
    int _;
    cin >> _ >> m;
    
    vector< pair<int, int> > ed(m);
    for (int i = 0; i < m; i++) {
        ed[i].first = query( vector<int>{i} );
        ed[i].second = i;
    }
    
    sort(all(ed));
    
    vector<int> span;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        span.push_back(ed[i].second);
        int t = query(span);
        
        if (t != cur + ed[i].first) span.pop_back();
        else cur = t;
    }
    
    ps("!", cur);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}