/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <array>


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




#include <type_traits>

template <typename T, size_t N>
struct MakeVector {
	template <
			typename... Args,
			typename R = std::vector<decltype(MakeVector<T, N - 1>::make_vector(std::declval<Args>()...))>
	>
	static R make_vector(std::size_t first, Args... sizes) {
		auto inner = MakeVector<T, N - 1>::make_vector(sizes...);
		return R(first, inner);
	}
};

template <typename T>
struct MakeVector<T, 1> {
	/*
	 * This template is to fool CLion.
	 * Without it CLion thinks that make_vector always returns std::vector<T> and marks code like
	 *
	 * auto dp = make_vector<int>(n, m, 0);
	 * dp[0][0] = 1 as error because it suppose that dp[0] is int
	 *
	 * TODO: Consider removing it once https://youtrack.jetbrains.com/issue/CPP-3340 is fixed
	 */
	template <typename R = std::vector<T>>
	static R make_vector(std::size_t size, const T& value) {
		return R(size, value);
	}
};

template <typename T, typename... Args>
auto make_vector(Args... args) -> decltype(MakeVector<T, sizeof...(Args) - 1>::make_vector(args...)) {
	return MakeVector<T, sizeof...(Args) - 1>::make_vector(args...);
}

#include <algorithm>

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

#include <cassert>

using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		string s;
		in >> s;
		array<vector<int>, 3> poses;
		for (int i: range(n)) {
			if (s[i] == 'V') {
				poses[0].push_back(i);
			}
			else if (s[i] == 'K') {
				poses[1].push_back(i);
			} else {
				poses[2].push_back(i);
			}
		}
		assert(poses[0].size() + poses[1].size() + poses[2].size() == n);
		auto dp = make_vector<int>(2, poses[0].size() + 1, poses[1].size() + 1, poses[2].size() + 1, 1000000000);
		dp[0][0][0][0] = 0;

		for (int sum = 0; sum <= n; ++sum) {
			for(int b = 0; b < 2; ++b) {
				for (int i = 0; i <= poses[0].size(); ++i) {
					if (i > sum) {
						break;
					}
					for (int j = 0; j <= poses[1].size(); ++j) {
						if (i +j > sum )break;
						//for (int k = 0; k <= poses[2].size(); ++k) {
						int k = sum - i - j;
						if (k >= 0 && k <= poses[2].size()) {
							if (i != poses[0].size()) {
								int add = 0;
								int pos = poses[0][i];
								int pos0 = (int) (lower_bound(poses[0].begin(), poses[0].end(), pos) - poses[0].begin());
								add += abs(pos0 - i);
								int pos1 = (int) (lower_bound(poses[1].begin(), poses[1].end(), pos) - poses[1].begin());
								add += abs(pos1 - j);
								int pos2 = (int) (lower_bound(poses[2].begin(), poses[2].end(), pos) - poses[2].begin());
								add += abs(pos2 - k);
								updateMin(dp[1][i + 1][j][k], dp[b][i][j][k] + add);
							}
							if (j != poses[1].size() && b == 0) {
								int add = 0;
								int pos = poses[1][j];
								int pos0 = (int) (lower_bound(poses[0].begin(), poses[0].end(), pos) - poses[0].begin());
								add += abs(pos0 - i);
								int pos1 = (int) (lower_bound(poses[1].begin(), poses[1].end(), pos) - poses[1].begin());
								add += abs(pos1 - j);
								int pos2 = (int) (lower_bound(poses[2].begin(), poses[2].end(), pos) - poses[2].begin());
								add += abs(pos2 - k);
								updateMin(dp[0][i][j + 1][k], dp[b][i][j][k] + add);
							}
							if (k != poses[2].size()) {
								int add = 0;
								int pos = poses[2][k];
								int pos0 = (int) (lower_bound(poses[0].begin(), poses[0].end(), pos) - poses[0].begin());
								add += abs(pos0 - i);
								int pos1 = (int) (lower_bound(poses[1].begin(), poses[1].end(), pos) - poses[1].begin());
								add += abs(pos1 - j);
								int pos2 = (int) (lower_bound(poses[2].begin(), poses[2].end(), pos) - poses[2].begin());
								add += abs(pos2 - k);
								updateMin(dp[0][i][j][k + 1], dp[b][i][j][k] + add);
							}
						}
					}
				}
			}
		}

		out << min(dp[0].back().back().back(), dp[1].back().back().back()) / 2 << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}