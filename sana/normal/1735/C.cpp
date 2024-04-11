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


typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


void go() {
    ints(n);
    string s; re(s);
    
    vi cc(26);
    for (int i = 0; i < 26; i++) cc[i] = i;
    
    int conn = 0;
    
    string ans = "";
    vi to(26,-1);
    vi fr(26,-1);
    for (int i = 0; i < n; i++) {
        int cur = (s[i]-'a');
        if (to[cur] == -1) {
            int cur_cc = cc[cur];
            for (int j = 0; j < 26; j++) if (fr[j]==-1 && (conn == 25 || cc[j] != cc[cur])) {
                fr[j] = cur;
                to[cur] = j;
                conn++;
                for (int k = 0; k < 26; k++) if (cc[k] == cur_cc) cc[k] = cc[j];
                break;
            }
        }
        ans += ('a' + to[cur]);
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