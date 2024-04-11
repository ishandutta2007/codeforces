#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
class interval {
public:
	long long l, r;
	interval() : l(0), r(0) {};
	interval(long long l_, long long r_) : l(l_), r(r_) {};
	bool operator==(const interval& iv) const { return l == iv.l && r == iv.r; }
	bool operator!=(const interval& iv) const { return l != iv.l || r != iv.r; }
	bool operator<(const interval& iv) const { return l != iv.l ? l < iv.l : r < iv.r; }
	bool operator>(const interval& iv) const { return l != iv.l ? l > iv.l : r > iv.r; }
};
class data_structure {
private:
	set<interval> s;
	long long val;
public:
	data_structure() : s(set<interval>()), val(0) {};
	long long get() const { return val; }
	void add(interval iv) {
		set<interval>::iterator it = s.lower_bound(interval(iv.r + 1, -inf));
		interval p(iv.l, iv.r);
		while(it != s.begin()) {
			--it;
			if(it->r < iv.l) break;
			p.l = min(p.l, it->l);
			p.r = max(p.r, it->r);
			val -= it->r - it->l;
			it = s.erase(it);
		}
		val += p.r - p.l;
		s.insert(p);
	}
	void erase(interval iv) {
		set<interval>::iterator it = s.lower_bound(interval(iv.r + 1, -inf));
		interval p(iv.l, iv.r);
		while(it != s.begin()) {
			--it;
			if(it->r < iv.l) break;
			p.l = min(p.l, it->l);
			p.r = max(p.r, it->r);
			val -= it->r - it->l;
			it = s.erase(it);
		}
		if(p.l < iv.l) {
			val += iv.l - p.l;
			s.insert(interval(p.l, iv.l));
		}
		if(p.r > iv.r) {
			val += p.r - iv.r;
			s.insert(interval(iv.r, p.r));
		}
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	data_structure ds;
	for(int i = 0; i < Q; ++i) {
		int l, r, tp;
		cin >> l >> r >> tp; --l;
		if(tp == 1) ds.add(interval(l, r));
		else ds.erase(interval(l, r));
		cout << N - ds.get() << '\n';
	}
	return 0;
}