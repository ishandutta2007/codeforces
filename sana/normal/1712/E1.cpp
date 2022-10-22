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


#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;
typedef long long ll;

typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


struct query {
    int l, r, id;
    ll ans;
};

const int MAX = 212345;

void solve()
{
    int q; re(q);
    vector<query> queries(q);
    
    for (int i = 0; i < q; i++) {
        re(queries[i].l, queries[i].r); queries[i].id = i;
    }
    
    sort(all(queries), [&](query a, query b) { return a.r < b.r; });
    
    vector<long long> b(MAX);
    int nq = 0;
    for (int k = 1; k <= queries.back().r; k++) {
        // bad: (p, q, k) with p|k and q|k
        //      (2k/5, 2k/3, k)
        //      (k/2, 2k/3, k)
        
        vi div; 
        vi rdiv;
        for (int j = 1; j*j <= k; j++) {
            if (k % j == 0) {
                div.push_back(j);
                if (k/j != j && k/j != k) rdiv.push_back(k/j);
            }
        }
        reverse(all(div));
        rdiv.insert(rdiv.end(), all(div));
        for (int i = 0; i < sz(rdiv); i++) {
            for (int x = rdiv[i]; x <= MAX; x+=x&-x) b[x]+=i;
        }
        
        if (k % 2 == 0 && k % 3 == 0) {
            for (int x = k/2; x <= MAX; x+=x&-x) b[x]++;
        }
        if (k % 3 == 0 && k % 5 == 0) {
            for (int x = (k/5)*2; x <= MAX; x+=x&-x) b[x]++;
        }
        
        while (nq < q && queries[nq].r == k) {
            long long len = (queries[nq].r - queries[nq].l + 1);
            long long ans = len * (len-1) * (len-2)/6;
            for (int x = queries[nq].r; x > 0; x-=x&-x) ans-=b[x];
            for (int x = queries[nq].l-1; x > 0; x-=x&-x) ans+=b[x];
            queries[nq++].ans = ans;
        }
    }
    
    sort(all(queries), [&](query a, query b) { return a.id < b.id; });
    for (query q : queries) ps(q.ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}