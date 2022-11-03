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

const int N = 1E5 + 10;

int a[N], b[N];

int main(){
	int n, m, na, ma;
	scanf("%d%d%d%d", &n, &m, &na, &ma);

	if (na >= m || ma >= n){
		puts("No");
		return 0;
	}

	for (int i = 1; i <= na; ++i)
		scanf("%d", a + i);
	for (int i = na + 1; i < m; ++i)
		a[i] = n;
	for (int i = 1; i <= ma; ++i)
		scanf("%d", b + i);
	for (int i = ma + 1; i < n; ++i)
		b[i] = n + m;

	int l = 1, r = 1;
	set<int> A, B;
	multiset<int> A2, B2;
	for (int i = 1; i <= n; ++i)
		A.insert(i);
	for (int i = 1; i < m; ++i){
		A.erase(a[i]);
		A2.insert(a[i]);
	}
	for (int i = 1; i <= m; ++i)
		B.insert(n + i);
	for (int i = 1; i < n; ++i){
		B.erase(b[i]);
		B2.insert(b[i]);
	}

	vector<pii> ans;
	for (int i = 2; i < n + m; ++i){
		int cur;
		if (A.empty())
			cur = *B.begin();
		else
			cur = *A.begin();

		if (cur <= n){
			ans.emplace_back(cur, b[r]);
			A.erase(cur);
			B2.erase(B2.find(b[r]));
			if (B2.find(b[r]) == B2.end())
				B.insert(b[r]);
			++r;
		}
		else{
			ans.emplace_back(cur, a[l]);
			B.erase(B.find(cur));
			A2.erase(A2.find(a[l]));
			if (A2.find(a[l]) == A2.end())
				A.insert(a[l]);
			++l;
		}
	}
	ans.emplace_back(*A.begin(), *B.begin());

	puts("Yes");
	for (auto &x: ans)
		printf("%d %d\n", x.st, x.nd);
	return 0;
}