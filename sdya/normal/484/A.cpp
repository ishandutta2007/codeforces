#include <iostream>
#include <map>

using namespace std;

struct State {
	long long left, right;
	int bit;
	
	State() {}
	
	State(long long left, long long right, int bit)
		: left(left), right(right), bit(bit) {}
	
	bool operator < (const State& other) const {
		return make_pair(make_pair(left, right), bit) 
			< make_pair(make_pair(other.left, other.right), other.bit);
	}
};

map < State, pair < long long, int > > M;

pair < long long, int > calc(long long left, long long right, int bit) {
	State current(left, right, bit);
	if (M.count(current)) {
		return M[current];
	}
	if (right == 0) {
		return M[current] = make_pair(0, 0);
	}
	if (bit < 0) {
		return M[current] = make_pair(0, 0);
	}
	
	pair < long long, int > best = make_pair(0, 0);
	if ((1LL << bit) - 1LL >= left) {
		long long nright = right;
		if (nright & (1LL << bit)) {
			nright = (1LL << bit) - 1LL;
		}
		pair < long long, int > current = calc(left, nright, bit - 1);
		best = current;
	}
	
	if (right >= (1LL << bit)) {
		long long nleft = left;
		if (nleft & (1LL << bit)) {
			nleft -= (1LL << bit);
		} else {
			nleft = 0;
		}
		
		long long nright = right - (1LL << bit);
		pair < long long, int > current = calc(nleft, nright, bit - 1);
		current.first += (1LL << bit);
		++current.second;
		
		if (current.second > best.second) {
			best = current;
		}
	}
	
	return M[current] = best;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		if (i % 10 == 0) {
			M.clear();
		}
		long long l, r;
		cin >> l >> r;
		pair < long long, int > res = calc(l, r, 61);
		cout << res.first << endl;
	}
	return 0;
}