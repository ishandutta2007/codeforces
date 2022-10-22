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
 

#define sz(x) (int)(x).size()


#define each(a,x) for (auto& a: x)
#define tcT template<class T

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;

typedef vector<int> vi;

 
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


ll ha(vi& card) {
    ll x = 0;
    for (int i = 0; i < sz(card); i++) {
        x = (x*3) + card[i];
    }
    return x;
}

void solve()
{
    ints(n,k);
    
    vector< vi > cards(n, vi(k));
    re(cards);
    
    vector<ll> has(n);
    for (int i = 0; i < n; i++) has[i] = ha(cards[i]);
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> al;
        vi myc(k);
        
        map<ll, int> cnt;
        ll pa = 0;
        for (int j = 0; j < n; j++) if (j != i) {
            for (int kk = 0; kk < k; kk++) {
                if (cards[j][kk] == cards[i][kk]) myc[kk] = cards[j][kk];
                else myc[kk] = ((cards[j][kk]+1) ^ (cards[i][kk]+1))-1;
            }
            
            pa += cnt[ ha(myc) ];
            cnt[has[j]]++;
        }
        
        dbg(n,i,pa);
        ans += pa*(pa-1)/2;
    }
    
    ps(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}