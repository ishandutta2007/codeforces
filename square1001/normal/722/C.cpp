#include <set>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

template<typename Type> class RMQ {
private:
	unsigned size_; std::vector<Type> dat;
	inline Type query_(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc);
	}
public:
	RMQ() : size_(0), dat(std::vector<Type>()) {};
	RMQ(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max());
	}
	template<class T>
	RMQ(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
		}
	}
	inline Type query(int l, int r) {
		return query_(l, r, 1, 0, size_);
	}
};

int n, a[100009], x; long long s[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), s[i + 1] = s[i] + a[i];
	set<int> p;
	p.insert(-1);
	p.insert(n);
	RMQ<long long> Q(n); Q.update(n - 1, -s[n]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); x--;
		set<int>::iterator it = p.lower_bound(x);
		int rp = *it;
		int lp = *(--it);
		p.insert(x);
		Q.update(rp - 1, -(s[rp] - s[x + 1]));
		Q.update(x - 1, -(s[x] - s[lp + 1]));
		printf("%lld\n", -Q.query(0, n));
	}
	return 0;
}