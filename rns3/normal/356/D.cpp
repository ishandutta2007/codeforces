#include <bits/stdc++.h>
using namespace std;

struct Bitset {

	int sz, len;
	vector <unsigned int> v;

	Bitset(int szz) {
		len = szz;
		sz = szz + 31 >> 5;
		v.clear();
		v.resize(sz, 0);
	}

	Bitset operator >>= (int x) {
		int d = x >> 5, r = x & 31;
		int en = sz - d - 1ll;
		for (int i = 0; i < en; i ++) v[i] = (v[i+d] >> r) | ((v[i+d+1ll] & ((1ll << r) - 1ll)) << 32 - r);
		v[en] = v[en+d] >> r;
		for (int i = en + 1ll; i < sz; i ++) v[i] = 0;
	}

	Bitset operator <<= (int x) {
		int d = x >> 5, r = x & 31;
        for (int i = sz - 1ll; i >= d; i --) v[i] = v[i-d];
        for (int i = d - 1ll; i >= 0; i --) v[i] = 0;
        if (r) {
			for (int i = sz - 1ll; i >= 1ll; i --) v[i] = ((v[i] & (((unsigned int)(1ll) << 32 - r) - 1ll)) << r) | (v[i-1ll] >> 32 - r);
			v[0] = (v[0] & (((unsigned int)(1ll) << 32 - r) - 1ll)) << r;
        }
		/*
		for (int i = sz - 1ll; i > d; i --) v[i] = ((v[i-d] & ((1ll << 32 - r) - 1ll)) << r) | (v[i-d-1ll] >> 32 - r);
		v[d] = (v[0] & ((1ll << 32 - r) - 1ll)) << r;
		for (int i = d - 1ll; i >= 0; i --) v[i] = 0;
		*/
	}

	Bitset operator | (const Bitset &b) {
		Bitset rlt = Bitset(len);
		for (int i = 0; i < sz; i ++) rlt.v[i] = v[i] | b.v[i];
		return rlt;
	}

	Bitset operator & (const Bitset &b) {
		Bitset rlt = Bitset(len);
		for (int i = 0; i < sz; i ++) rlt.v[i] = v[i] & b.v[i];
		return rlt;
	}

	Bitset operator ^ (const Bitset &b) {
		Bitset rlt = Bitset(len);
		for (int i = 0; i < sz; i ++) rlt.v[i] = v[i] ^ b.v[i];
		return rlt;
	}

	vector <int> get() {
		vector <int> rlt;
		for (int i = 0; i < sz; i ++) if (v[i]) {
			for (int j = 0; j < 32; j ++) if (v[i] & (1ll << j)) rlt.push_back((i << 5) | j);
		}
		return rlt;
	}

	bool bit(int x) {
		return v[x>>5] & (1ll << (x & 31));
	}

	void print(int x) {
		for (int i = 0; i < x; i ++) printf("%d ", bit(i)); puts("");
	}
};

#define N 70707

int n, s, a[N], id[N], in[N];
bool vis[N];
set <int> st[N];

bool cmp(int i, int j) {
	return a[i] != a[j] ? a[i] < a[j] : !vis[i] && vis[j];
}

int main() {
//	freopen("d.in", "r", stdin);
	Bitset val = Bitset(N), nwb = Bitset(N), tmp = Bitset(N);
	scanf("%d %d", &n, &s);
	int I = 0;
	for (int i = 1ll; i <= n; i ++) {
		scanf("%d", &a[i]);
		if (a[i] > s) return puts("-1"), 0;
		if (a[i] > a[I]) I = i;
	}
	vis[I] = 1ll;
	s -= a[I];
	val.v[0] = 1ll;
	for (int i = 1ll; i <= n && s; i ++) if (!vis[i] && a[i] <= s) {
		tmp = val;
		tmp <<= a[i];
		nwb = val ^ (val | tmp);
		val = val | tmp;
		vector <int> v = nwb.get();
		for (int j = 0; j < v.size(); j ++) {
			if (v[j] <= s) st[i].insert(v[j]);
		}
	}
	if (!val.bit(s)) return puts("-1"), 0;
	for (int i = n; i >= 1ll; i --) {
		if (st[i].find(s) != st[i].end()) {
			s -= a[i];
			vis[i] = 1ll;
		}
	}
	for (int i = 1ll; i <= n; i ++) id[i] = i;
	sort(id + 1ll, id + n + 1ll, cmp);
	for (int i = 1ll; i <= n; i ++) {
		if (!vis[id[i]]) {
			in[id[i+1ll]] = id[i];
		}
	}
	for (int i = 1ll; i <= n; i ++) {
		printf("%d ", a[i] - a[in[i]]);
		if (in[i]) printf("1 %d\n", in[i]);
		else puts("0");
	}
	return 0;
}