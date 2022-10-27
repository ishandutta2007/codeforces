#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = ((1<<17) + 1) * 17 + 1;
int ch[N][2], tot = 0;
vector<int> buf;
void ins(int x) {
	int rt = 0;
	for (int i = 16; i >= 0; i --) {
		int id = x>>i&1;
		if (ch[rt][id] == 0) ch[rt][id] = ++tot;
		rt = ch[rt][id];
		buf.emplace_back(rt);
	}
}

int query(int x) {
	int rt = 0, res = 0;
	for (int i = 16; i >= 0; i --) {
		int id = x>>i&1;
		if (ch[rt][id^1]) {
			res |= 1<<i; rt = ch[rt][id^1];
		} else {
			rt = ch[rt][id];
		}
	}
	return res;
}
int query_min(int x) {
	int rt = 0, res = 0;
	for (int i = 16; i >= 0; i --) {
		int id = x>>i&1;
		if (ch[rt][id]) {
			rt = ch[rt][id];
		} else {
			res |= 1<<i;
			rt = ch[rt][id^1];
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int l, r;
		cin >> l >> r;
		int n = r - l + 1;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i]; 
		}

		for (auto x: a) ins(x);
		for (auto e: a) {
			int x = e ^ l;
			//cout << "X = " << x << "\n";
			//cout << "max = " << query(x) << " min = " << query_min(x) << "\n";
			if (query(x) == r && query_min(x) == l) {
				cout << x << "\n";
				//for (auto e: a) cout << (e ^ x) <<  " ";
				//cout << "\n";
				break;
			}
		}
		buf.emplace_back(0);
		//memset(ch, 0, sizeof(ch));
		for (auto x: buf) ch[x][0] = ch[x][1] = 0; tot = 0;
		buf.clear();
	}
}

/*
1. in range
	a[i] xor x in [l, r]
2. 

*/