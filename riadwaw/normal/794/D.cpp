/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>


#include <iterator>


#include <string>
#include <stdexcept>

#ifndef SPCPPL_ASSERT
	#ifdef SPCPPL_DEBUG
		#define SPCPPL_ASSERT(condition) \
		if(!(condition)) { \
			throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
		}
	#else
		#define SPCPPL_ASSERT(condition)
	#endif
#endif


/**
* Support decrementing and multi-passing, but not declared bidirectional(or even forward) because
* it's reference type is not a reference.
*
* It doesn't return reference because
* 1. Anyway it'll not satisfy requirement [forward.iterators]/6
*   If a and b are both dereferenceable, then a == b if and only if *a and
*   b are bound to the same object.
* 2. It'll not work with reverse_iterator that returns operator * of temporary which is temporary for this iterator
*
* Note, reverse_iterator is not guaranteed to work  now too since it works only with bidirectional iterators,
* but it's seems to work at least on my implementation.
*
* It's not really useful anywhere except iterating anyway.
*/
template <typename T>
class IntegerIterator: public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(T value): value(value) {

	}

	IntegerIterator& operator++() {
		++value;
		return *this;
	}

	IntegerIterator operator++(int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator--() {
		--value;
		return *this;
	}

	IntegerIterator operator--(int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator*() const {
		return value;
	}

	bool operator==(IntegerIterator rhs) const {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) const {
		return !(*this == rhs);
	}

private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin <= end);
	}

	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}

	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}

private:
	T begin_;
	T end_;
};

template <typename T>
class ReversedIntegerRange {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin >= end);
	}

	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}

	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}

private:
	T begin_;
	T end_;
};

template <typename T>
IntegerRange<T> range(T to) {
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	return IntegerRange<T>(from, to);
}

template <typename T>
IntegerRange<T> inclusiveRange(T to) {
	return IntegerRange<T>(0, to + 1);
}

template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
	return IntegerRange<T>(from, to + 1);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	return ReversedIntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from) {
	return ReversedIntegerRange<T>(from + 1, 0);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from, T to) {
	return ReversedIntegerRange<T>(from + 1, to);
}

#include <set>
#include <cassert>
#include <queue>
#include <map>

using namespace std;

class TaskD {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		vector<vector<int>> g(n);
		set<pair<int, int>> edges;
		vector<int> ans(n, 0);
		for (int i: range(m)) {
			int a, b;
			in >> a >> b;
			--a, --b;
			g[a].push_back(b);
			g[b].push_back(a);
			edges.insert({a, b});
			edges.insert({b, a});
		}

		int root = 0;
		for (int i: range(n)) {
			if (g[i].size() > g[root].size()) {
				root = i;
			}
		}


		int end = 0;
		for (int i: range(n)) {
			if (g[i].size() < g[end].size()) {
				end = i;
			}
		}

		auto go = [&]() {
			if (g[end].size() + 1 == n) {
				return;
			}
			for (int plus: g[root]) {
				for (int minus: g[root]) {
					if (plus == minus) {
						continue;
					}

					if (edges.count({plus, minus})) {
						continue;
					}
					//cerr << root << ' ' << plus << ' ' << minus << endl;


					vector<int> used(n);
					used[root] = 1;
					queue<int> q;
					q.push(root);
					for (int other: g[root]) {
						used[other] = 1;
						q.push(other);
						if (other == plus) {
							ans[other] += 1;
						}
						else if (other == minus) {
							ans[other] -= 1;
						} else {
							if (edges.count({other, plus})) {
								ans[other] += 1;
							}
							if (edges.count({other, minus})) {
								ans[other] -= 1;
							}
						}
					}

					while (!q.empty()) {
						int v = q.front();
						q.pop();
						for (int to: g[v]) {
							if (used[to] != 0) {
								continue;
							}
							if (ans[v] < 0) {
								ans[to] = ans[v] - 1;
							}
							else {
								ans[to] = ans[v] + 1;
							}
							q.push(to);
							used[to] = true;
						}
					}

					return;
				}
}{
				assert(false);
			}


		};


		go();


		map<int, int> cnt;
		for (auto x: ans) {
			++cnt[x];
		}
		for (auto p: edges) {
			if (abs(ans[p.first] - ans[p.second]) > 1) {
				out << "NO\n";
				return;
			}
		}


		int64_t goodEdges = 0;
		for (auto p: cnt) {
			goodEdges += p.second * (p.second - 1LL) / 2;
			if (cnt.count(p.first + 1)) {
				goodEdges += p.second * 1LL * cnt[p.first + 1];
			}
		}
		if (goodEdges != m) {
			out << "NO\n";
			return;
		}

		out << "YES\n";
		for (auto x: ans) {
			out << x + 1000000 << " ";
		}


	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}