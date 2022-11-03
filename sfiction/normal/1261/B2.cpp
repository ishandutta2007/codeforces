#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pd __gnu_pbds
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T> using il = initializer_list<T>;

template <class T> inline void mini(T &l, T r){l = min(l, r);}
template <class T> inline void maxi(T &l, T r){l = max(l, r);}

template <class T> void _dbg(const char *sdbg, T &&h){cerr << sdbg << "=" << h << "\n";}
template <class T, class ...R> void _dbg(const char *sdbg, T h, R... a){
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";
}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";
}
template <class it> auto gr(it b, it e){
    return vector<typename remove_const<typename remove_reference<decltype(*b)>::type>::type>(b, e);
}
template <class T, class c = decltype(T().begin())> ostream &operator <<(ostream &os, T &v){
	return os << gr(all(v));
}
template <class T, int I, int N> void TuplePrint(ostream &os, T val){
	if constexpr (I < N)
		(os << get<I>(val) << ",", TuplePrint<T, I + 1, N>(os, val));
	else
		os << get<N>(val);
}
template <class... Ts> ostream &operator<<(ostream &os, tuple<Ts...> t){
	os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";
}

#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif

//constexpr int N = 1E5 + 10, M = 1E9 + 7;
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;
//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>

int main(){
	int n;
	scanf("%d", &n);
	vector<pii> a;
	for (int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		a.emplace_back(-x, i);
	}
	sort(all(a));
	
	int m;
	scanf("%d", &m);
	vector<vector<pii>> b(n);
	for (int i = 0; i < m; ++i){
		int x, k;
		scanf("%d%d", &x, &k);
		b[x - 1].emplace_back(k, i);
	}

	vector<int> ans(m);
	pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update> c;
	for (int i = 0; i < n; ++i){
		c.insert(make_pair(a[i].nd, -a[i].st));
		for (auto &x: b[i])
			ans[x.nd] = c.find_by_order(x.st - 1)->nd;

		eput(c);
		eput(b[i]);
		eput(il<int>{1, 2, 3, 4, 5});
	}

	auto tt = make_tuple(1, "23423", 19.0);
	eput(tt);

	for (auto &x: ans)
		printf("%d\n", x);
	return 0;
}