/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>


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




#include <cstddef>

namespace impl {

template <typename T, typename U, typename V>
void matrixMultiplication(const T& lhs, const U& rhs, V& res) {
	const auto& a = lhs;
	auto b = rhs.transposed();
	for (std::size_t i = 0; i < lhs.rows(); ++i) {
		for (std::size_t j = 0; j < rhs.columns(); ++j) {
			for (std::size_t k = 0; k < rhs.rows(); ++k) {
				res[i][j] += a[i][k] * b[j][k];
			}
		}
	}
}

} // namespace impl



#include <type_traits>

template <typename T, typename = std::true_type>
struct IdentityHelper;

template <typename T>
struct IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template <typename T>
T identity() {
	return IdentityHelper<T>::identity();
}


template <typename T, typename N, typename M>
class Matrix {
public:
	explicit Matrix(const T& value = T()) {
		for (int i: range(6)) {
			value[i].fill(value);
		}
	}

	std::size_t rows() const {
		return N::value;
	}

	std::size_t columns() const {
		return M::value;
	}

	std::array<T, 6>& operator[](std::size_t index) {
		SPCPPL_ASSERT(index < rows());
		return value[index];
	}

	const std::array<T, 6>& operator[](std::size_t index) const {
		SPCPPL_ASSERT(index < rows());
		return value[index];
	}

	Matrix& operator*=(const Matrix<T, M, M>& rhs) {
		return *this = *this * rhs;
	}

	Matrix& operator+=(const Matrix& rhs) {
		for (std::size_t i = 0; i < rows(); ++i) {
			for (std::size_t j = 0; j < columns(); ++j) {
				value[i][j] += rhs.value[i][j];
			}
		}
		return *this;
	}

	Matrix operator-() const {
		Matrix copy = *this;
		for (int i = 0; i < rows(); ++i) {
			for (int j = 0; j < columns(); ++j) {
				copy[i][j] = -copy[i][j];
			}
		}
		return copy;
	}

	Matrix operator-=(const Matrix& rhs) {
		return *this += -rhs;
	}

	Matrix<T, M, N> transposed() const {
		Matrix<T, M, N> res;
		for (std::size_t i = 0; i < rows(); ++i) {
			for (std::size_t j = 0; j < columns(); ++j) {
				res[j][i] = value[i][j];
			}
		}
		return res;
	}

private:
	std::array<std::array<T, 6>, 6> value;

	template <typename U, typename V, typename W>
	friend bool operator==(const Matrix<U, V, W>& lhs, const Matrix<U, V, W>& rhs);
};

template <typename T, typename N, typename M>
bool operator==(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs) {
	return lhs.value == rhs.value;
}

template <typename T, typename N, typename M, typename K>
Matrix<T, N, K> operator*(const Matrix<T, N, M>& lhs, const Matrix<T, M, K>& rhs) {
	Matrix<T, N, K> res;
	impl::matrixMultiplication(lhs, rhs, res);
	return res;
}

template <typename T, typename N, typename M>
Matrix<T, N, M> operator+(Matrix<T, N, M> lhs, const Matrix<T, N, M>& rhs) {
	Matrix<T, N, M> copy = std::move(lhs);
	return copy += rhs;
}

template <typename T, typename N, typename M>
Matrix<T, N, M> operator-(Matrix<T, N, M> lhs, const Matrix<T, N, M>& rhs) {
	Matrix<T, N, M> copy = std::move(lhs);
	return copy -= rhs;
}

template <typename T, typename N>
struct IdentityHelper<Matrix<T, N, N>> {
	static Matrix<T, N, N> identity() {
		Matrix<T, N, N> res;
		for (std::size_t i = 0; i < N::value; ++i) {
			res[i][i] = ::identity<T>();
		}
		return res;
	}
};

template <typename T, std::size_t n, std::size_t m>
using FixedSizeMatrix = Matrix<T, std::integral_constant<std::size_t, n>, std::integral_constant<std::size_t, m>>;

#include <vector>

#include <algorithm>

template <typename T>
void update_min(T& oldValue, const T& newValue) {
	if (newValue < oldValue) {
		oldValue = newValue;
	}
}

template <typename T>
void update_max(T& oldValue, const T& newValue) {
	if (oldValue < newValue) {
		oldValue = newValue;
	}
}


using namespace std;

int inf = 1000000000;

struct M {
	std::array<int, 5>& operator[](size_t x) {
		return value[x];
	}

	const std::array<int, 5>& operator[](size_t x) const {
		return value[x];
	}

	std::array<std::array<int, 5>, 5> value;
};

int shift = 1 << 18;
vector<M> tree;

void fill(M& x, char c) {
	for (int i: range(5)) {
		for (int j: range(5)) {
			x[i][j] = inf;
		}
	}
	for (int o: range(5)) {
		x[o][o] = 1;
		if (o == 0 && c == '2') {
			x[o][o + 1] = 0;
		}
		else if (o == 1 && c == '0') {
			x[o][o + 1] = 0;
		}
		else if (o == 2 && c == '1') {
			x[o][o + 1] = 0;
		}
		else if (o == 3 && c == '7') {
			x[o][o + 1] = 0;
		}
		else if (c == '6' && o >= 3) {
		}
		else {
			x[o][o] = 0;
		}
	}
}

M mul(const M& a, const M& b) {
	M res;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			res[i][j] = inf;
			for (int k = 0; k < 5; ++k) {
				update_min(res[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return res;
}

using V = array<int, 5>;

V mul(const M& m, const V& v) {
	V res;
	res.fill(inf);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			update_min(res[i], m[j][i] + v[j]);
		}
	}
	return res;
}

V query(int l, int r, const V& v) {
	if (l + 1 == r) {
		return mul(tree[l], v);
	}

	if (l & 1) {
		V nv = mul(tree[l], v);
		++l;
		return query(l, r, nv);
	} else if (r & 1) {
		V nv = query(l, r - 1, v);
		return mul(tree[r - 1], nv);
	}
	return query(l / 2, r / 2, v);
}

class TaskE {
public:
	void solve(std::istream& in, std::ostream& out) {

		int n, q;
		in >> n >> q;
		tree.resize(2 * shift);
		string s;
		in >> s;
		for (int i: range(n)) {
			fill(tree[i + shift], s[i]);
		}

		for (int i = shift - 1; i >= 1; --i) {
			tree[i] = mul(tree[2 * i], tree[2 * i + 1]);
		}

		for (int i: range(q)) {
			int l, r;
			in >> l >> r;
			--l;
			auto res = query(l + shift, r + shift, array<int, 5>{{0, inf, inf, inf, inf}});
			if (res[4] == inf) {
				out << -1 << "\n";
			} else {
				out << res[4] << "\n";
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskE solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}