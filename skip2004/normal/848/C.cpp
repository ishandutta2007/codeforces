#include<bits/stdc++.h>
const int maxn = 100100;
using std::cin;
using std::cout;
typedef unsigned u32;
namespace tp {
	static std::mt19937 rd(time(0));
	struct node{
		node * ls, * rs;
		u32 val, p, size, cnt;
		inline node(u32 x, u32 c){
			size = cnt = c;
			val = x; p = rd();
			ls = rs = NULL;
		}
		inline void update(){
			size = cnt;
			if(this -> ls) size += this -> ls -> size;
			if(this -> rs) size += this -> rs -> size;
		}
	};
	inline void rotaters(node *& rt){
		node * x = rt -> rs,* y = rt; rt = x;
		y -> rs = x -> ls,x -> ls = y;
		y -> update(); rt -> update();
	}
	inline void rotatels(node *& rt){
		node * x = rt -> ls,* y = rt; rt = x;
		y -> ls = x -> rs,x -> rs = y;
		y -> update(); rt -> update();
	}
	inline void ins(node *&rt, u32 val, u32 cnt){
		if(rt == NULL || rt -> val == val){
			if(rt == NULL) rt = new node(val, cnt);
			else {
				rt -> size += cnt;
				rt -> cnt += cnt;
			}
		}else{
			if(val < rt -> val){
				ins(rt -> ls, val, cnt);
				rt -> size += cnt;
				if(rt -> ls -> p > rt -> p)
					rotatels(rt);
			}else{
				ins(rt -> rs, val, cnt);
				rt -> size += cnt;
				if(rt -> rs -> p > rt -> p)
					rotaters(rt);
			}
		}
	}
	inline node * merge(node * x, node * y){
		if(x == NULL) return y;
		if(y == NULL) return x;
		if(x -> p > y -> p){
			x -> rs = merge(x -> rs,y),x -> update();
			return x;
		}else{
			y -> ls = merge(x,y -> ls),y -> update();
			return y;
		}
	}
	inline void erase(node *&x, u32 val, int cnt){
		if(x -> val == val){
			if(x -> cnt == cnt) {
				node * L = x -> ls, * R = x -> rs;
				delete x;
				x = merge(L, R);
			} else {
				x -> size -= cnt;
				x -> cnt -= cnt;
			}
			return ;
		}
		if(val < x -> val)
			erase(x -> ls, val, cnt);
		else
			erase(x -> rs, val, cnt);
		x -> update();
	}
	inline u32 less(node * x,u32 v){
		if(x == NULL) return 0;
		const u32 lssz = x -> ls == NULL ? 0 : x -> ls -> size;
		if(x -> val < v)
			return lssz + x -> cnt + less(x -> rs,v);
		else
			return less(x -> ls,v);
	}
	struct tree
	{
		node * root;
		inline void add(int pos, int v) { ins(root, pos, v); }
		inline void dec(int pos, int v) { erase(root, pos, v); }
		inline u32 ask(u32 v){ return less(root, v + 1); }
	};
}

typedef std::set<int>::iterator iter;
std::set<int> set[maxn];

struct {
	tp::tree bit[maxn];

	inline void add(int x, int y, int v) { ++ x; for(;x < maxn;x += x & -x) bit[x].add(y, v); }
	inline void dec(int x, int y, int v) { ++ x; for(;x < maxn;x += x & -x) bit[x].dec(y, v); }
	inline int ask(int x, int y) { ++ x; u32 ans = 0; for(;x;x &= x - 1) ans += bit[x].ask(y); return ans; }
} bit0;

static const int M = 1e5 + 1;
struct {
	tp::tree bit[maxn];

	inline void add(int x, int y, int v) { ++ x; for(;x;x &= x - 1) bit[x].add(M - y, v); }
	inline void dec(int x, int y, int v) { ++ x; for(;x;x &= x - 1) bit[x].dec(M - y, v); }
	inline int ask(int x, int y) { ++ x; u32 ans = 0; for(;x < maxn;x += x & -x) ans += bit[x].ask(M - y); return ans; }
} bit1;


int a[maxn];
int n, m;

int pre[maxn], suf[maxn];

inline void uptpr(int pos, int v) {
	if(1 <= pos && pos <= n) {
		if(pre[pos] != -1) bit0.dec(pre[pos], pos, pos);
		pre[pos] = v;
		if(pre[pos] != -1) bit0.add(pre[pos], pos, pos);
	}
}
inline void uptsf(int pos, int v) {
	if(1 <= pos && pos <= n) {
		if(suf[pos] != -1) bit1.dec(suf[pos], pos, pos);
		suf[pos] = v;
		if(suf[pos] != -1) bit1.add(suf[pos], pos, pos);
	}
}

inline void ins(int pos, int v)
{
	iter it = set[v].insert(pos).first;
	if(it != set[v].begin()) uptpr(pos, * std::prev(it)), uptsf(* std::prev(it), pos);
	if(it != --set[v].end()) uptpr(* std::next(it), pos), uptsf(pos, * std::next(it));
}
inline void del(int pos, int v) 
{
	uptpr(pos, -1);
	uptsf(pos, -1);
	set[v].erase(pos);
	iter it = set[v].lower_bound(pos);
	if(it != set[v].begin() && it != set[v].end()) {
		uptpr(*it, *std::prev(it));
		uptsf(*std::prev(it), *it);
	}
}

inline u32 askmax(int l, int r) {
	return bit1.ask(r + 1, l) - bit1.ask(r + 1, r + 1);
}
inline u32 askmin(int l, int r) {
	return bit0.ask(l - 1, r) - bit0.ask(l - 1, l - 1);
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) {
		pre[i] = suf[i] = -1;
		set[i].insert(0);
		set[i].insert(n + 1);
	}
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		ins(i, a[i]);
	}
	for(int i = 1, opt, l, r, p, x;i <= m;++i) 
	{
		cin >> opt;
		if(opt == 1)
		{
			cin >> p >> x;
			if(x != a[p]) {
				del(p, a[p]);
				ins(p, a[p] = x);
			}
		}
		else
		{
			cin >> l >> r;
			cout << askmax(l, r) - askmin(l, r) << '\n';
		}
	}
}