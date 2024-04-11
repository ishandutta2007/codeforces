#include<bits/stdc++.h>
#define int long long
#define IT set<node>::iterator
using namespace std;

inline int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
struct node {
	int lft, rht;
	mutable bool val;
	node (int l, int r = 0, int v = 0): lft(l), rht(r), val(v) {}
	bool operator < (node a) const {
		return lft < a.lft;
	}
};
set<node> s;
int n, m;

inline IT split(int pos) {
	IT it = s.lower_bound(node(pos));
	if(it != s.end() && it -> lft == pos) return it;
	--it;
	int l = it -> lft, r = it -> rht, val = it -> val;
	s.erase(it);
	s.insert(node(l, pos - 1, val));
	return s.insert(node(pos, r, val)).first;
}

inline void assign(int l, int r, int val) {
	IT itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(node(l, r, val));
}

inline void reverse(int l, int r) {
	IT itr = split(r + 1), itl = split(l);
	while(itl != itr) itl -> val ^= 1, itl++;
}

inline int query(int l, int r) {
	IT itr = split(r + 1), itl = split(l);
	while(itl != itr) {
		if(itl -> val == 0) break;
		itl++;
	}
	return itl -> lft;
}

signed main() {
	m = get();
	s.insert(node(1, 1e18, 0));
	while(m--) {
		int opt = get(), l = get(), r = get();
		switch(opt) {
			case 1: assign(l, r, 1); break;
			case 2: assign(l, r, 0); break;
			case 3: reverse(l, r);
		}
		printf("%lld\n", query(1, 1e18));
	}
	return 0;
}