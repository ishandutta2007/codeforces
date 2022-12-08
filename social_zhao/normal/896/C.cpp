#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define int long long
#define IT set<node>::iterator
using namespace std;

inline long long qpow(int a, int b, int p) {
	long long res = 1, base = a % p;
	while(b) {
		if(b & 1) res = (res * base) % p;
		base = (base * base) % p;
		b >>= 1;
	}
	return res;
}

const int N = 1e5 + 5;
long long n, m, seed, vmax, mod = 1e9 + 7, a[N];
struct node {
	int lft, rht;
	mutable long long val;
	node (int l, int r = -1, long long v = 0): lft(l), rht(r), val(v) {}
	bool operator < (node a) const {
		return lft < a.lft;
	}
};
set<node> s;

inline int rnd() {
    long long ret = seed;
    seed = (seed * 7 + 13) % mod;
    return ret;
}

inline IT split(int pos) {
	IT it = s.lower_bound(node(pos));
	if(it != s.end() && it -> lft == pos) return it;
	--it;
	int l = it -> lft, r = it -> rht;
	long long v = it -> val;
	s.erase(it);
	s.insert(node(l, pos - 1, v));
	return s.insert(node(pos, r, v)).first;
}

inline void assign(int l, int r, long long v) {
	IT itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(node(l, r, v));
}

inline void add(int l, int r, long long v) {
	IT itr = split(r + 1), itl = split(l);
	while(itl != itr) itl -> val += v, itl++;
}

inline long long kth(int l, int r, int k) {
	vector< pair<long long, int> > v;
	IT itr = split(r + 1), itl = split(l);
	while(itl != itr) v.push_back(make_pair(itl -> val, itl -> rht - itl -> lft + 1)), ++itl;
	sort(v.begin(), v.end());
	for(vector<pair<long long, int> >::iterator it = v.begin(); it != v.end(); ++it) {
		k -= it -> second;
		if(k <= 0) return it -> first; 
	}
}

inline long long sum(int l, int r, int k, long long y) {
	IT itr = split(r + 1), itl = split(l);
	long long res = 0;
	while(itl != itr) {
		res += qpow(itl -> val, k, y) * (itl -> rht - itl -> lft + 1);
		res %= y;
		itl++;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> seed >> vmax;
	for(register int i = 1; i <= n; i++) s.insert(node(i, i, rnd() % vmax + 1));
	for(register int i = 1; i <= m; i++) {
		long long opt = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1, x, y;
		if(l > r) swap(l, r);
		if(opt == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if(opt == 4) y = rnd() % vmax + 1;
		//cout << opt << " " << l << " " << r << " " << x << " " << y << endl;
		if(opt == 1) add(l, r, x);
		else if(opt == 2) assign(l, r, x);
		else if(opt == 3) cout << kth(l, r, x) << endl;
		else cout << sum(l, r, x, y) << endl;
	}
	return 0;
}