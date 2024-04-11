#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;
#define elseif else if
const int maxn = 100200;
int q;
int opt[maxn], t[maxn], s[maxn], l[maxn], r[maxn], v[maxn];
std::vector<int> vec;

const int EEEE = -1e9 - 10;
inline int idx(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
struct mes {
	ll sum, max_pre, min_pre;
};

mes tree[maxn << 2];
int tag[maxn << 2];
int len[maxn << 2];

inline void put(int cur, int v) {
	tag[cur] = v;
	tree[cur].sum = (ll) len[cur] * v;
	if(v >= 0) {
		tree[cur].max_pre = (ll) len[cur] * v;
		tree[cur].min_pre = 0;
	} else {
		tree[cur].max_pre = 0;
		tree[cur].min_pre = (ll) len[cur] * v;
	}
}

inline void pushdown(int cur) {
	if(tag[cur] != -EEEE) {
		put(cur << 1, tag[cur]);
		put(cur << 1 | 1, tag[cur]);
		tag[cur] = -EEEE;
	}
}
inline mes merge(const mes & x, const mes & y) {
	return (mes) {
		x.sum + y.sum, 
		std::max(x.max_pre, x.sum + y.max_pre),
		std::min(x.min_pre, x.sum + y.min_pre),
	};
}
inline void update(int cur) {
	tree[cur] = merge(tree[cur << 1], tree[cur << 1 | 1]);
}
inline void build(int cur, int l, int r) {
	if(l == r) {
		len[cur] = vec[l + 1] - vec[l];
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
	len[cur] = len[cur << 1] + len[cur << 1 | 1];
	update(cur);
}
inline void make(int cur, int ql, int qr, int v, int l = 0, int r = vec.size() - 2) {
	if(ql <= l && r <= qr) return put(cur, v);
	int mid = l + r >> 1;
	pushdown(cur);
	if(ql <= mid) make(cur << 1, ql, qr, v, l, mid);
	if(mid < qr) make(cur << 1 | 1, ql, qr, v, mid + 1, r);
	update(cur);
}

inline double go(int cur, int pos, ll & v, int l = 0, int r = vec.size() - 2) {
	if(r < pos) return -1;
	if(pos <= l) {
		ll max = v + tree[cur].max_pre, min = v + tree[cur].min_pre;
		if((max > 0 && min > 0) || (max < 0 && min < 0)) {
			v += tree[cur].sum;
			return -1;
		}
	}
	if(l == r) return vec[l] + (double) -v / tag[cur];
	int mid = l + r >> 1;
	pushdown(cur);
	double left = go(cur << 1, pos, v, l, mid);
	if(left >= 0) return left;
	return go(cur << 1 | 1, pos, v, mid + 1, r);
}
std::map<int, int> map;

inline double calc(int l, ll v) {
	return go(1, l, v);
}

main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> q;
	vec.push_back(2e9);
	vec.push_back(2e9 - 1);
	for(int i = 1;i <= q;++i) {
		cin >> opt[i];
		if(opt[i] == 1) {
			cin >> t[i] >> s[i];
			vec.push_back(t[i]);
		}
		if(opt[i] == 2) {
			cin >> t[i];
		}
		if(opt[i] == 3) {
			cin >> l[i] >> r[i] >> v[i];
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	build(1, 0, vec.size() - 2);
	map[vec.back()] = 2333;
	for(int i = 1;i <= q;++i) {
		if(opt[i] == 1) {
			map[t[i]] = s[i];
			make(1, idx(t[i]), idx(map.upper_bound(t[i]) -> first) - 1, s[i]);
		} elseif(opt[i] == 2) {
			auto iter = map.find(t[i]);
			make(1, idx(t[i]), idx(map.upper_bound(t[i]) -> first) - 1, iter == map.begin() ? 0 : prev(iter) -> second);
			map.erase(iter);
		} elseif(opt[i] == 3) {
			auto iter = map.lower_bound(l[i]);
			if(!v[i]) {
				printf("%d\n", l[i]);
				continue;
			}
			l[i] = iter == map.end() ? int(2e9) : iter -> first;
			double ans = calc(idx(l[i]), v[i]);
			printf("%.10lf\n", ans <= r[i] + 1e-8 ? ans : -1);
		}
	}
}