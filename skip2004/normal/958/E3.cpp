#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
struct T { int x, y, id; };
typedef std::vector<T> vec;
int n;
int to[maxn];
T node;
inline bool cmp(const T & x, const T & y) {
	return (x.x - node.x) * (y.y - node.y) - (y.x - node.x) * (x.y - node.y) > 0;
}
inline void clear(vec & v) { vec().swap(v); }
inline void solve(vec & v) {
	if(v.empty()) return ;
	T * min = &v.back();
	for(T & i : v) if(i.x < min -> x || (i.x == min -> x && i.y < min -> y))
		min = &i;
	node = *min;
	std::swap(v.front(), * min);
	sort(v.begin() + 1, v.end(), cmp);
	int cnt = 0, can_pos = -1;
	for(int i = 1;i < v.size();++i) {
		if(((node.id > n) ^ (v[i].id > n)) && cnt == 0) {
			if(can_pos == -1 || std::abs((can_pos * 2 - (int) v.size()) > std::abs(i * 2 - (int) v.size()))) {
				can_pos = i;
			}
		}
		cnt += v[i].id > n ? 1 : - 1;
	}
	vec v0, v1;
	to[node.id] = v[can_pos].id;
	to[v[can_pos].id] = node.id;
	if(can_pos << 1 < v.size()) {
		for(int i = 1;i < can_pos;++i) v0.push_back(v[i]);
		solve(v0);
		for(int i = can_pos + 1;i < v.size();++i) v1.push_back(v[i]);
		clear(v0); clear(v);
		solve(v1);
	} else {
		for(int i = can_pos + 1;i < v.size();++i) v1.push_back(v[i]);
		solve(v1);
		for(int i = 1;i < can_pos;++i) v0.push_back(v[i]);
		clear(v1); clear(v);
		solve(v0);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	vec vc;
	rep(i, 1, n + n) {
		T x;
		x.id = i;
		cin >> x.x >> x.y;
		vc.push_back(x);
	}
	solve(vc);
	rep(i, 1, n) {
		cout << to[i] - n << '\n';
	}
}