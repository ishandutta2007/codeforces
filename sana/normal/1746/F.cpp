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
 

#define each(a,x) for (auto& a: x)
#define tcT template<class T

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;

typedef vector<int> vi;

 
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
 
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


int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }


const int MAGIC = 32;

void solve()
{
    ints(n,q);
    vi a(n); re(a);
    
    vector< vector<ll> > tree(MAGIC, vector<ll>(n+1));
    map< int, vector<int> > mp;
    
    auto get = [&](int t, int i) {
        ll s = 0;
        for (int x = i+1; x > 0; x -= x&-x) s += tree[t][x];
        return s;
    };
    
    auto add = [&](int t, int i, int delta) {
        for (int x = i+1; x <= n; x += x&-x) tree[t][x] += delta;
    };
    
    auto geth = [&](int i) {
        if (!mp.count(i)) {
            vi v(MAGIC);
            for (int j = 0; j < MAGIC; j++) v[j] = myrand(1, 1000000000);
            mp[i] = v;
            return v;
        }
        return mp[i];
    };
    
    for (int i = 0; i < n; i++) {
        vi v = geth(a[i]);
        for (int j = 0; j < MAGIC; j++) add(j, i, v[j]);
    }
    
    for (; q; q--) {
        ints(t);
        if (t == 1) {
            ints(i, x); i--;
            vi vn = geth(x);
            vi vo = geth(a[i]);
            for (int j = 0; j < MAGIC; j++) {
                add(j, i, vn[j] - vo[j]);
            }
            
            a[i] = x;
        }
        else {
            ints(l,r,k); l--; r--;
            bool ok = true;
            for (int j = 0; j < MAGIC && ok; j++) {
                ll s = get(j, r) - get(j, l-1);
                ok = (ok && s % k == 0);
            }
            
            ps(ok ? "YES" : "NO");
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}