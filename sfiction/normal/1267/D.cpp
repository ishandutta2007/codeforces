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
	while (*sdbg != ','){cerr << *sdbg++;} cerr << "=" << h << ","; _dbg(sdbg + 1, a...);}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> &P){
	return os << "(" << P.st << "," << P.nd << ")";}
template <class T> ostream &operator <<(ostream &os, const vector<T> &v){
	os << "["; for (auto x: v) os << x << ","; return os << "]";}
template <class IT, class V = vector<typename iterator_traits<IT>::value_type>> V gr(IT b, IT e){
	return V(b, e);}
template <class T, class c = decltype(T().begin())> ostream &operator <<(ostream &os, T &v){
	return os << gr(v.begin(), v.end());}
template <class T, int I, int N, typename enable_if<I == N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<N>(val);}
template <class T, int I, int N, typename enable_if<I < N, T>::type* = nullptr> void TuplePrint(ostream &os, T val){
	os << get<I>(val) << ","; TuplePrint<T, I + 1, N>(os, val);}
template <class... Ts> ostream &operator<<(ostream &os, tuple<Ts...> t){
	os << "("; TuplePrint<tuple<Ts...>, 0, sizeof...(Ts) - 1>(os, t); return os << ")";}

#ifdef SFIC
#define eput(...) do{cerr << __LINE__;_dbg("\t| "#__VA_ARGS__, __VA_ARGS__);}while(0)
#else
#define eput(...) 218
#endif

//pd::priority_queue<int, less<int>, pairing_heap_tag>
//pd::tree<int, int, less<int>, pd::rb_tree_tag, pd::tree_order_statistics_node_update>
//constexpr int N = 1E5 + 10, M = 1E9 + 7;
//constexpr ll INF = LLONG_MAX >> 1;
//constexpr double eps = 1E-9;

const int N = 3E2 + 10;

int n;
int a[N], b[N];
int mark[N];
vector<int> c[8];
int mask[8];

int ct[N];
vector<pii> ans;

inline int getState(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	return a | b << 1 | c << 2;
}

void spread(queue<int> &Q){
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();

		int t = a[u];
		if (ct[u])
			t &= b[u];
		eput(u, t);
		for (auto &v: c[t]){
			if (mark[v])
				continue;

			ans.emplace_back(u, v);

			mark[v] = true;
			int tm = a[v] & b[v];
			if (mask[tm] == 0){
				mask[tm] = v;
				Q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		a[i] = getState();
		c[a[i]].push_back(i);

		if (a[i] == 0){
			mark[i] = true;
			mask[0] = i;
		}
	}
	for (int i = 1; i <= n; ++i){
		b[i] = getState();
	}

	fill_n(ct + 1, n, 1);
	queue<int> Q;
	mark[1] = true;
	mask[a[1] & b[1]] = 1;
	Q.push(1);
	spread(Q);

	eput(gr(mask, mask + 8));
	eput(gr(mark + 1, mark + n + 1));

	for (int i = 1; i < 8; i <<= 1){
		int u = 7 - i;
		if (mask[u] || c[u].empty())
			continue;

		bool flag = true;
		for (int j = 1; j < 8; j <<= 1)
			flag &= (j & u) != j || mask[j] != 0;

		if (!flag)
			continue;

		int u0 = c[u][0];
		for (int j = 1; j < 8; j <<= 1)
			if ((j & u) == j)
				ans.emplace_back(mask[j], u0);
		ct[u0] = 0;
		mark[u0] = true;
		mask[u] = u0;
		Q.push(u0);

		eput(a[u0], b[u0]);
	}

	eput(gr(mask, mask + 8));
	eput(gr(mark + 1, mark + n + 1));

	spread(Q);

	eput(gr(mask, mask + 8));
	eput(gr(mark + 1, mark + n + 1));

	if (find(mark + 1, mark + n + 1, 0) != mark + n + 1){
		puts("Impossible");
		return 0;
	}

	puts("Possible");
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ct[i], "\n "[i < n]);
	printf("%d\n", ans.size());
	for (auto &x: ans)
		printf("%d %d\n", x.st, x.nd);
	return 0;
}