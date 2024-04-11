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

const int N = 1E2 + 10;

int a[N * 2][N * 2];

bool query(int x, int y){
	if (x == y)
		return false;

	if (a[x][y] == 0){
		printf("? %d %d\n", x, y);
		fflush(stdout);
		char s[2];
		scanf("%s", s);
		a[x][y] = s[0] == '>' ? 1 : -1;
		a[y][x] = -a[x][y];
	}
	return a[x][y] < 0;
}

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; ++i)
			fill_n(a[i] + 1, n * 2, 0);

		vector<int> s(n * 2);
		iota(all(s), 1);
		vector<pii> p;
		vector<int> c;
		int rem = n;
		while (rem > 0){
			eput(s);
			eput(p);

			while (s.size() >= 2){
				int u = s.back();
				s.pop_back();
				int v = s.back();
				s.pop_back();
				if (!query(u, v))
					swap(u, v);

				p.emplace_back(u, v);
			}
			if (rem == 1 && s.size() == 1){
				p.emplace_back(s.back(), -1);
				s.pop_back();
			}
			
			eput(p);

			int m = p.size();
			c.resize(m);
			iota(all(c), 0);
			sort(all(c), [&](int l, int r){return query(p[l].st, p[r].st);});

			for (int i = 0; rem > 0 && i < m && 2 * (m - i) > n; ++i, --rem)
				p[c[i]].st = -1;
			for (int i = 0; i < p.size(); ++i)
				if (p[i].st == -1){
					if (p[i].nd != -1)
						s.push_back(p[i].nd);
					
					p[i] = p.back();
					p.pop_back();
					--i;
				}
		}

		eput(s);
		eput(p);

		puts("!");
		fflush(stdout);
	}
	return 0;
}