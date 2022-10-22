#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 200200;
int n, m;
int a[N], x[N];
std::unordered_map<int, int> map;

inline int ask0(int id, u32 l) ;
inline int ask1(int id, u32 l) ;

inline int gr(int id, int l) { return std::upper_bound(x + 1, x + n + 1, x[id] + l) - x - 1; }
inline int gl(int id, int l) { return std::lower_bound(x + 1, x + n + 1, x[id] - l) - x; }

inline int ask0(int id, u32 l) {
	int tid = gr(id, l);
	const int dis = x[tid] - x[id];
	if(gl(tid, l - dis) != id) return ask1(tid, l - dis);
	if(tid == id) return id;

	l %= dis * 2u;
	if(l < dis) return ask0(id, l);
	else return ask1(tid, l - dis);
}

inline int ask1(int id, u32 l) {
	int tid = gl(id, l);
	const int dis = x[id] - x[tid];
	if(gr(tid, l - dis) != id) return ask0(tid, l - dis);
	if(tid == id) return id;
	l %= dis * 2u;
	if(l < dis) return ask1(id, l);
	else return ask0(tid, l - dis);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
		x[i] = a[i];
		map[a[i]] = i;
	}
	std::sort(x + 1, x + n + 1);
	rep(i, 1, m) {
		int pos, l;
		cin >> pos >> l;
		cout << map[x[ask0(std::lower_bound(x + 1, x + n + 1, a[pos]) - x, l)]] << '\n';
	}
}