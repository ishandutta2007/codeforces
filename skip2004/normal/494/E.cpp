#include<bits/stdc++.h>
#define pb emplace_back
const int maxn = 100100;
using std::cin;
using std::cout;
int n, m, k;
int a[maxn], b[maxn], c[maxn], d[maxn];
std::vector<int> vec0, vec1;

std::vector<std::pair<int, int>> vector[maxn];

inline int find(std::vector<int>& vec, int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
inline int prev(int n) {
	return n ^ (n >> 1);
}
inline int conv(int a, int b) {
	int res = 0;
	for(int i = 0;i < 30;++i) if(b >> i & 1) {
		res ^= (a & (1 << i) - 1) ^ __builtin_parity(a >> i) << i;
	}
	return res;
}
inline int getsg(int l, int r) {
	return prev(r) ^ prev(l - 1);
}

int tree[maxn << 3], tag[maxn << 3];

inline void update(int cur, int l, int r) {
	if(tag[cur]) {
		tree[cur] = getsg(l, r);
	} else {
		tree[cur] = tree[cur << 1] ^ tree[cur << 1 | 1];
	}
}

inline void upt(int ql, int qr, int v, int cur = 1, int l = 0, int r = vec1.size() - 2){ 
	if(ql <= l && r <= qr) {
		tag[cur] += v;
	} else {
		int mid = l + r >> 1;
		if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	}
	update(cur, vec1[l], vec1[r + 1] - 1);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;

	for(int i = 0;i < m;++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		++ c[i], ++ d[i];
		vec0.pb(a[i]);
		vec0.pb(c[i]);
		vec1.pb(b[i]);
		vec1.pb(d[i]);
	}
	sort(vec0.begin(), vec0.end()), vec0.erase(unique(vec0.begin(), vec0.end()), vec0.end());
	sort(vec1.begin(), vec1.end()), vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());

	for(int i = 0;i < m;++i) {
		a[i] = find(vec0, a[i]);
		c[i] = find(vec0, c[i]);
		b[i] = find(vec1, b[i]);
		d[i] = find(vec1, d[i]);
		vector[a[i]].pb(b[i], d[i]);
		vector[c[i]].pb(d[i], b[i]);
	}
	int res = 0;
	for(int i = 0;i < (int) vec0.size();++i) {
		for(auto j : vector[i]) {
			if(j.first < j.second) {
				upt(j.first, j.second - 1, 1);
			} else {
				upt(j.second, j.first - 1, -1);
			}
		}
		if(i + 1 != (int) vec0.size()) {
			res ^= conv(tree[1], getsg(vec0[i], vec0[i + 1] - 1));
		}
	}
//	cout << res << '\n';
	cout << (conv(res, 1 << std::__lg(k)) ? "Hamed" : "Malek") << '\n';
}