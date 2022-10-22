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
typedef long long ll;
typedef pair<int, int> pii;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }

 
tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


int n,m,k;
vector<ll> dist;
vector< vector<pii> > g;

const ll INF = 1000000000000000000;

void dijkstra() {
    priority_queue< pair<ll, int> > pq;
    for (int i = 0; i < n; i++) {
        pq.push({-dist[i], i});
    }
    
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        d = -d;
        
        if (dist[v] != d) continue;
        for (auto [x, w] : g[v]) {
            if (dist[x] > dist[v] + w) {
                dist[x] = dist[v] + w;
                pq.push({-dist[x], x});
            }
        }
    }
}

struct line_type{
	long long d, k;
	line_type(long long d = 0, long long k = numeric_limits<long long>::min() / 2): d(d), k(k){ }
	long long eval(long long x){ return d * x + k; }
	bool majorize(line_type X, long long L, long long R){ return eval(L) >= X.eval(L) && eval(R) >= X.eval(R); }
};
template<bool GET_MAX = true>
struct lichao{
	lichao *l = 0, *r = 0;
	line_type S;
	lichao(): S(line_type()){ }
	~lichao(){
		delete l;
		delete r;
	}
	void mc(int i){
		if(i){ if(!r) r = new lichao(); }
		else{ if(!l) l = new lichao(); }
	}
	long long pq(long long X, long long L, long long R){
		long long ans = S.eval(X), M = L + R >> 1;
		if(X < M) return max(ans, l ? l->pq(X, L, M) : -(long long)9e18);
		else return max(ans, r ? r->pq(X, M, R) : -(long long)9e18);
	}
	long long query(long long X, long long L, long long R){
		return pq(X, L, R) * (GET_MAX ? 1 : -1);
	}
	void pp(line_type X, long long L, long long R){
		if(X.majorize(S, L, R)) swap(X, S);
		if(S.majorize(X, L, R)) return;
		if(S.eval(L) < X.eval(L)) swap(X, S);
		long long M = L + R >> 1;
		if(X.eval(M) > S.eval(M)) swap(X, S), mc(0), l->pp(X, L, M);
		else mc(1), r->pp(X, M, R);
	}
	void push(line_type X, long long L, long long R){
		if(!GET_MAX) X.d = -X.d, X.k = -X.k;
		pp(X, L, R);
	}
};

void flights() {
    // (w - v)^2 = w^2 - 2vw + v^2
    lichao<false> lc;
    for (int i = 0; i < n; i++) {
        lc.push( line_type(- 2 * i, dist[i] + i * 1ll * i), -1, n+1);
    }
    
    for (int i = 0; i < n; i++) {
        dist[i] = min(dist[i], lc.query(i, -1, n+1) + i*1ll*i);
    }
}

void solve()
{
    re(n,m,k);
    g = vector<vector<pii>>(n);
    
    for (int i = 0; i < m; i++) {
        ints(u,v,w); u--; v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    
    dist = vector<ll>(n);
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[0] = 0;
    
    for (int i = 0; i <= k; i++) {
        if (i != 0) flights();
        
        dijkstra();
    }
    
    for (ll x : dist) pr(x, " ");
    ps();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}