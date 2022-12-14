/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>


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



#include <algorithm>
#include <vector>


template <typename R>
void sort(R& range) {
	std::sort(range.begin(), range.end());
}

template <typename R, typename Comp>
void sort(R& range, Comp comp) {
	std::sort(range.begin(), range.end(), comp);
}

template <typename R>
void reverse(R& range) {
	std::reverse(range.begin(), range.end());
}

template <typename R, typename T>
auto lower_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value);
}

template <typename R, typename T, typename Comp>
auto lower_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value, comp);
}

template <typename R, typename T>
auto upper_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value);
}

template <typename R, typename T, typename Comp>
auto upper_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value, comp);
}

template <typename R>
auto min_element(const R& range) -> decltype(range.begin()) {
	return std::min_element(range.begin(), range.end());
}

template <typename R>
auto max_element(const R& range) -> decltype(range.begin()) {
	return std::max_element(range.begin(), range.end());
}

template <typename R>
bool next_permutation(R& range) {
	return std::next_permutation(range.begin(), range.end());
}

template <typename T>
void unique(std::vector<T>& range) {
	range.erase(std::unique(range.begin(), range.end()), range.end());
}

template <typename R>
R sorted(R range) {
	sort(range);
	return range;
}

template <typename R, typename Comp>
R sorted(R range, Comp comp) {
	sort(range, comp);
	return range;
}

template <typename R>
R reversed(R range) {
	reverse(range);
	return range;
}








#include <cstddef>


template <typename T>
std::size_t leastSignificantBit(T number) {
	SPCPPL_ASSERT(number != 0);
	for (std::size_t i = 0; ; ++i) {
		if ((number >> i) & 1) {
			return i;
		}
	}
}

template <typename T>
bool isPowerOf2(T number) {
	return number != 0 && (number & (number - 1)) == 0;
}


template <typename T, typename Operation>
class SparseTable {
public:
	explicit SparseTable(std::vector<T> elements, const Operation& operation = Operation(), const T& neutralValue = T()):
			operation(operation), neutralValue(neutralValue) {
		std::size_t n = elements.size();
		logarithms.resize(n + 1);
		for (std::size_t i = 2; i < logarithms.size(); ++i) {
			logarithms[i] = logarithms[i - 1];
			if (isPowerOf2(i)) {
				++logarithms[i];
			}
		}

		table.push_back(std::move(elements));
		table.resize(logarithms[n] + 1, std::vector<T>(n));

		for (auto i: range(static_cast<std::size_t>(1), table.size())) {
			for (std::size_t j = 0; j + (1 << i) <= n; ++j) {
				table[i][j] = this->operation(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	T getResult(std::size_t l, std::size_t r) const {
		SPCPPL_ASSERT(l <= r && r <= table[0].size());
		if (l == r) {
			return neutralValue;
		}
		auto log = logarithms[r - l];
		SPCPPL_ASSERT((1 << log) <= r - l);
		SPCPPL_ASSERT((1 << (log + 1)) >= r - l);
		return operation(table[log][l], table[log][r - (1 << log)]);
	}
private:
	std::vector<std::size_t> logarithms;
	std::vector<std::vector<T>> table;
	Operation operation;
	T neutralValue;
};





struct Max {
	template <typename T>
	T operator()(const T& l, const T& r) const {
		return std::max(l, r);
	}
};



template <typename T>
void updateMin(T& oldValue, const T& newValue) {
	if (newValue < oldValue) {
		oldValue = newValue;
	}
}

template <typename T>
void updateMax(T& oldValue, const T& newValue) {
	if (oldValue < newValue) {
		oldValue = newValue;
	}
}


using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, c, d;
		in >> n >> c >> d;
		vector<pair<int, int>> by_c, by_d;
		by_c.reserve(n);
		by_d.reserve(n);
		for (int i: range(n)) {
			int b, p;
			char t;
			in >> b >> p >> t;
			if (t == 'C') {
				by_c.push_back({p, b});
			}
			else {
				by_d.push_back({p, b});
			}
		}

		sort(by_c);
		sort(by_d);

		vector<int> c_beauty(by_c.size());
		vector<int> d_beauty(by_d.size());
		for (int i: range(by_c.size())) {
			c_beauty[i] = by_c[i].second;
		}
		for (int i: range(by_d.size())) {
			d_beauty[i] = by_d[i].second;
		}

		SparseTable<int, Max> c_sparse(c_beauty, Max(), -1000000000);
		SparseTable<int, Max> d_sparse(d_beauty, Max(), -1000000000);

		int ans = 0;
		{
			int c_pos = lower_bound(by_c, make_pair(c + 1, 0)) - by_c.begin();
			int d_pos = lower_bound(by_d, make_pair(d + 1, 0)) - by_d.begin();
			if (c_pos > 0 && d_pos > 0) {
				updateMax(ans, c_sparse.getResult(0, c_pos) + d_sparse.getResult(0, d_pos));
			}
		}
		auto solve1 = [&](vector<pair<int, int>>& by, SparseTable<int, Max>& sparse, int money) {
			for (int i: range(by.size())) {
				if (by[i].first > money) {
					break;
				}
				int rest = money - by[i].first;
				int pos = lower_bound(by, make_pair(rest + 1, 0)) - by.begin();
				//cerr << i << ' ' << pos << endl;
				if (pos > 0) {
					if (i >= pos) {
						updateMax(ans, by[i].second + sparse.getResult(0, pos));
					}
					else {
						updateMax(
								ans, by[i].second + max(
										sparse.getResult(0, i),
										sparse.getResult(i + 1, pos)
								)
						);
					}
				}
			}
		};

		solve1(by_c, c_sparse, c);
		solve1(by_d, d_sparse, d);

		out << ans << "\n";

		//cerr << "----" << endl;
	};
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}