#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
	unordered_map <int, int> ump;
	void change(ll p, int c) {
		for(; p < (1LL << 31); p += (p & (-p)))
			ump[p] += c;
	}
	int query(int p) {
		if(!p) return 0;
		int ret = 0;
		for(; p; p -= (p & (-p)))
			ret += ump[p];
		return ret;
	}
}bit;

unordered_map <int, int> ump;
int subtree_sum(int v, int now_h, int max_h) {
	/*
	int ret = 0;
	while(now_h <= max_h) {
		int l = v * (1 << (max_h - now_h));
		int r = l - 1 + (1 << (max_h - now_h));
		ret += bit.query(r) - bit.query(l - 1);
		now_h ++;
	}
	return ret;
	*/
	return ump[v];
}

double solve(int v, int now_h, int max_h, int pre) {
	//int self = bit.query(v) - bit.query(v - 1);
	int self = ump[v];
	if(now_h != max_h) {
		self -= ump[2 * v];
		self -= ump[2 * v + 1];
	}
	if(now_h == max_h)
		return max(self, pre);
	int left = subtree_sum(2 * v, now_h + 1, max_h);
	int right = subtree_sum(2 * v + 1, now_h + 1, max_h);
	if(left > right)
		return 0.5 * max(left + self, pre) +
			0.5 * solve(2 * v, now_h + 1, max_h, max(right + self, pre));
	return 0.5 * max(right + self, pre) +
		0.5 * solve(2 * v + 1, now_h + 1, max_h, max(left + self, pre));
}

int main() {
	ios :: sync_with_stdio(false);
	int h, q; cin >> h >> q;
	cout << fixed << setprecision(9);
	while(q --) {
		string s; cin >> s;
		if(s == "add") {
			int v, e; cin >> v >> e;
			//bit.change(v, e);
			for(; v; v /= 2)
				ump[v] += e;
		} else {
			cout << solve(1, 0, h, 0) << '\n';
		}
	}
	return 0;
}