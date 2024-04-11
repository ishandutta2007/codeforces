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


typedef string str;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n); n <<= 1;
    string s; cin >> s;
    
    int ans = 0;
    vector<int> st = {0};
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (st.back() == 0) {
                st.back() = 1;
                ans++;
            }
            st.push_back(0);
        }
        else st.pop_back();
    }
    
    ps(ans);
}

void solve()
{
    int t;
    for (cin >> t ;t;t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}