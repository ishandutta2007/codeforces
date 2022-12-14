/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>


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

#include <vector>

using namespace std;

class TaskD {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		int LG = 19;
		vector<vector<int>> parents(1);
		vector<int64_t> w(1);
		vector<vector<int64_t>> sums(1);
		auto INF = 2000000000000000000LL;
		sums[0].resize(LG, INF);
		parents[0].resize(LG, -1);
		int64_t last = 0;
		for (int _: range(q)) {
			int64_t t, p,q;
			in >> t >> p >> q;
			p ^= last;
			q ^= last;
			if (t == 2) {
				//cerr << "calc " << p << " " << q << endl;
				--p;
				int ans = 0;
				if (q < w[p]) {
					last = 0;
					out << "0\n";
					continue;
				}
				ans = 1;
				q -= w[p];
				for (int i: downrange(LG)) {
					if (parents[p][i] != -1 && sums[p][i] <= q) {
						q -= sums[p][i];
						p = parents[p][i];
						ans += 1 << i;
					}
				}
				out << ans << "\n";
				last = ans;
			} else {
				//cerr << "add " << p << " " << q << endl;
				--p;
				w.push_back(q);
				int parent = p;
				if (w[parent] < q) {
					for (int i: downrange(LG)) {
						if (parents[parent][i] != -1 && w[parents[parent][i]] < q) {
							parent = parents[parent][i];
						}
					}
					parent = parents[parent][0];
				}
				//cerr << "parent " << parent << endl;
				parents.push_back(vector<int>(LG, -1));
				parents.back()[0] = parent;
				sums.push_back(vector<int64_t>(LG, INF));
				sums.back()[0] = parent == -1 ? INF : w[parent];
				for (int i: range(1, LG)) {
					if (parents.back()[i - 1] == -1) {
						break;
					}
					parents.back()[i] = parents[parents.back()[i - 1]][i - 1];
					sums.back()[i] = min(INF, sums.back()[i - 1] + sums[parents.back()[i - 1]][i - 1]);
				}

			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}