#include<bits/stdc++.h>
const int N = 300005;
using std::cin;
using std::cout;
struct pt { int x, y, c, id; };
std::vector<pt> o;
int n;
int cc;
std::vector<int> ans;

inline void update(const std::vector<int> & z) {
	if(z.size() > ans.size()) ans = z;
}
inline bool cmpx(const pt & x, const pt & y) { return x.x < y.x; }
inline bool cmpy(const pt & x, const pt & y) { return x.y < y.y; }
inline bool check00(int k, std::vector<int> per) {
	int i = 0, ids = 0;
	for(int w : per) {
		int rem = k;
		for(;i < (int) o.size();++i) {
			if(o[i].c == w) {
				rem -= 1;
				++ ids;
				if(!rem) {
					for(int p = o[i].x;i < (int) o.size() && o[i].x == p;++i);
					break;
				}
			}
		}
	}
	return ids == k * 3;
}
inline std::vector<int> check01(int k, std::vector<int> per) {
	int i = 0;
	static std::vector<int> ids;
	ids.clear();
	for(int w : per) {
		int rem = k;
		for(;i < (int) o.size();++i) {
			if(o[i].c == w) {
				rem -= 1;
				ids.push_back(o[i].id);
				if(!rem) {
					for(int p = o[i].x;i < (int) o.size() && o[i].x == p;++i);
					break;
				}
			}
		}
	}
	return ids;
}
inline void calc0() {
	for(int c = 0;c < 2;++c) {
		std::vector<int> per = {1, 2, 3};
		sort(o.begin(), o.end(), cmpx);
		do {
			int l = ans.size() / 3, r = n / 3 + 1;
			if(!check00(ans.size() / 3, per)) continue;
			for(;l + 1 < r;) {
				int mid = (l + r) >> 1;
				if(check00(mid, per)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			update(check01(l, per));

		} while(next_permutation(per.begin(), per.end()));
		for(pt & x : o) std::swap(x.x, x.y);
	}
}
inline bool check10(std::vector<pt> & p, int k, std::vector<int> per) {
	int cnt = k, ret = 0;
	int py = -1;
	for(const pt x : p) {
		if(x.c == per[0]) cnt -= 1, ++ret;
		if(cnt == 0) {
			py = x.y;
			break;
		}
	}
	int i = 0;
	for(int w : {per[1], per[2]}) {
		int rem = k;
		for(;i < (int) o.size();++i) if(o[i].y > py) {
			if(o[i].c == w) {
				rem -= 1;
				++ret;
				if(!rem) {
					for(int p = o[i].x;i < (int) o.size() && o[i].x == p;++i);
					break;
				}
			}
		}
	}
	return ret == k * 3;
}
inline std::vector<int> check11(std::vector<pt> & p, int k, std::vector<int> per) {
	int cnt = k;
	static std::vector<int> ret;
	ret.clear();
	int py = -1;
	for(const pt x : p) {
		if(x.c == per[0]) cnt -= 1, ret.push_back(x.id);
		if(cnt == 0) {
			py = x.y;
			break;
		}
	}
	int i = 0;
	for(int w : {per[1], per[2]}) {
		int rem = k;
		for(;i < (int) o.size();++i) if(o[i].y > py) {
			if(o[i].c == w) {
				rem -= 1;
				ret.push_back(o[i].id);
				if(!rem) {
					for(int p = o[i].x;i < (int) o.size() && o[i].x == p;++i);
					break;
				}
			}
		}
	}
	return ret;
}
inline int calc1() {
	for(int i = 0;i < 4;++i) {
		sort(o.begin(), o.end(), cmpx);
		std::vector<pt> p = o;
		sort(p.begin(), p.end(), cmpy);
		std::vector<int> per = {1, 2, 3};
		sort(o.begin(), o.end(), cmpx);
		do {
			int l = ans.size() / 3, r = n / 3 + 1;
			if(!check10(p, ans.size() / 3, per)) continue;
			for(;l + 1 < r;) {
				int mid = (l + r) >> 1;
				if(check10(p, mid, per)) {
					l = mid;
				} else {
					r = mid;
				}
			}
			update(check11(p, l, per));

		} while(next_permutation(per.begin(), per.end()));

		for(int i = 0;i < n;++i) {
			o[i].x = n - 1 - o[i].x;
			std::swap(o[i].x, o[i].y);
		}
	}
	return 0;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n, o.resize(n);
	std::vector<int> ox, oy;
	int p = 0;
	for(int i = 0;i < n;++i) {
		cin >> o[i].x >> o[i].y >> o[i].c;
		ox.push_back(o[i].x);
		oy.push_back(o[i].y);
		o[i].id = i + 1;
		if((p >> o[i].c & 1) == 0) {
			p |= 1 << o[i].c;
			ans.push_back(o[i].id);
		}
	}
	calc0();
	calc1();
	cout << ans.size() << '\n';
}