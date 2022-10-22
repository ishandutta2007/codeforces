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


typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n,k);
    string s; re(s);
    
    vi cnt(26);
    for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
    
    string ans = "";
    
    for (int i = 0; i < k; i++) {
        int cur = 0;
        int amt = n/k;
        
        for (int j = 0; j < 25; j++) if (cnt[cur] && amt) {
            cnt[cur]--;
            cur++;
            amt--;
        }
        
        ans += ('a' + cur);
    }
    
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