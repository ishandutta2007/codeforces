#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N;

struct Range {
	mutable int left, right, value;
	static Range with(int x) {
		Range r;
		r.left = x;
		return r;
	}
};

bool operator<(const Range& a, const Range& b) {
	return a.left < b.left;
}

typedef vector<long long> C;
long long sum_to(C* v, int ind) {
	long long res = 0;
	while (ind) {
		res += (*v)[ind];
		ind &= ind-1;
	}
	return res;
}
void incr(C* v, int ind, long long by) {
	while (ind + 1 < (int)v->size()) {
		(*v)[ind + 1] += by;
		ind |= ind+1;
	}
}
long long at(C* v, int ind) {
	return sum_to(v, ind+1) - sum_to(v, ind);
}

C linj, con;
void increase_range(int from, int to, int by) {
// cout << "increase_range " << from << ' ' << to << ' ' << by << endl;
	incr(&linj, from, by);
	incr(&linj, to, -by);
	incr(&con, from, -by * (long long)from);
	incr(&con, to, by * (long long)to);
}

long long sum_to_excl(int to) {
	return sum_to(&linj, to) * to + sum_to(&con, to);
}

int main() {
	cin.sync_with_stdio(false);
	int M;
	cin >> N >> M;
	linj.assign(N+1, 0);
	con.assign(N+1, 0);
	typedef set<Range> S;
	S s;
	for (int i = 1; i <= N; ++i) {
		Range r;
		r.left = r.right = r.value = i;
		s.insert(r);
	}
	for (int i = 0; i < M; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
// for (auto r : s) {
	// cout << r.left << ' ' << r.right << ' ' << r.value << ", ";
// }
// cout << endl;

			int l, r, x;
			cin >> l >> r >> x;
			S::iterator start = s.upper_bound(Range::with(l));
			--start;
// cout << l << ' ' << start->left << endl;
			if (start->left < l) {
				Range nr;
				nr.left = l;
				nr.right = start->right;
				nr.value = start->value;
				start->right = l - 1;
				s.insert(nr);
				++start;
// cout << "cut start " << start->left << ' ' << start->right << ' ' << start->value << endl;
			}
			S::iterator end = s.upper_bound(Range::with(r));
			--end;
			if (end->right > r) {
				Range nr;
				nr.left = r + 1;
				nr.right = end->right;
				nr.value = end->value;
				end->right = r;
				s.insert(nr);
			}
			S::iterator it = start;
			Range nr;
			nr.left = l;
			nr.right = r;
			nr.value = x;
			++end;
			while (it != end) {
				int dif = it->value - x;
				if (dif < 0) dif = -dif;
				it->value = x;
				increase_range(it->left-1, it->right-1 + 1, dif);
				s.erase(it++);
			}
			s.insert(nr);
		}
		else {
			int l, r;
			cin >> l >> r;
			long long res = sum_to_excl(r) - sum_to_excl(l-1);
			cout << res << endl;
		}
	}
	return 0;
}