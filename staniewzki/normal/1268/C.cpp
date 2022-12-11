#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

/*
 * Opis: set z dodatkowymi funkcjami
 * Uycie:
 *   insert(x) dodaje element x (nie ma emplace)
 *   find_by_order(i) zwraca iterator do i-tego elementu
 *   order_of_key(x) zwraca, ile jest mniejszych elementw,
 *   x nie musi by w secie
 *   Jeli chcemy multiseta, to uywamy par {val, id}.
 *   Przed includem trzeba da undef _GLIBCXX_DEBUG
 */

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> p(n), pos(n);
	REP(i, n) {
		cin >> p[i];
		pos[p[i] - 1] = i;
	}

	set<int> left, right;
	LL sum_left = 0, sum_right = 0;
	ordered_set<int> all;

	LL ans = 0;
	REP(i, n) {
		all.insert(pos[i]);
		ans += i - all.order_of_key(pos[i]);

		auto add = [&]() {
			if(size(left)) {
				auto it = prev(left.end());
				LL m = *it;
				if(pos[i] < m) {
					left.insert(pos[i]);
					sum_left += pos[i];
				}
				else {
					right.insert(pos[i]);
					sum_right += pos[i];
				}
			}
			else {
				left.insert(pos[i]);
				sum_left += pos[i];
			}
		
			if(size(left) > size(right) + 1) {
				auto it = prev(left.end());
				sum_left -= *it;
				sum_right += *it;
				right.emplace(*it);
				left.erase(it);
			}

			if(size(right) > size(left)) {
				auto it = right.begin();
				sum_right -= *it;
				sum_left += *it;
				left.emplace(*it);
				right.erase(it);
			}
		};

		add();

		debug(left, right);

		auto it = prev(left.end());
		LL m = *it;
		LL k = size(left);
		LL left_goal = m * k - k * (k - 1) / 2;
		debug(m, k, left_goal, sum_left);
		k = size(right);
		LL right_goal = m * k + k * (k + 1) / 2;
		debug(m, k, right_goal, sum_right);
		cout << left_goal - sum_left + sum_right - right_goal + ans << "\n";
	}
}