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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#define each(a,x) for (auto& a: x)
#define tcT template<class T


template<class T> using V = vector<T>; 


typedef string str;

typedef pair<int, int> pii;
typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void solve()
{
    ints(n);
    vi a(n); re(a);
    
    long long ans = 0;
    vi covered(n+1);
    
    vector< pii > vals(n+2);
    for (int i = 0; i < n; i++) vals[i] = pii{-a[i], i}; 
    vals[n] = pii{0, -1};
    vals[n+1] = pii{0, n};
    
    sort(all(vals));
    
    int last_left = 0;
    
    auto get = [&](int x) { 
        int s = 0;
        for (x++; x > 0; x -= x&-x) s += covered[x];
        return s;
    };
    
    for (int i = 0; i < n;) {
        if (vals[i].first == 0) break;
        
        int start_nxt = i;
        while (vals[i].first == vals[start_nxt].first) start_nxt++;
        
        int end_nxt = start_nxt;
        while (end_nxt < sz(vals) && vals[end_nxt].first == vals[start_nxt].first) end_nxt++;
        
        int lt_max = vals[i].second;
        int rt_max = vals[start_nxt-1].second;
        
        int affected = max(0, get(last_left) - get(lt_max));
        affected += max(0, get(rt_max) - get(last_left));
        
        dbg(-vals[i].first, lt_max, rt_max, affected, start_nxt - i, last_left);
        ans += affected + (start_nxt - i);
        
        int mandatory_left_border = min(last_left, lt_max-1);
        int mandatory_right_border = max(rt_max, last_left);
        last_left = min(mandatory_right_border, max(mandatory_left_border, vals[start_nxt].second));
        for (; i < start_nxt; i++) {
            for (int x = vals[i].second+1; x <= n; x+=(x&-x)) covered[x]++;
        }
    }
    
    ps(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}