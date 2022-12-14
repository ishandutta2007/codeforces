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
	explicit IntegerIterator(int value): value(value) {

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

	bool operator==(IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) {
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




#include <assert.h>



#include <type_traits>

template <typename T>
T identity();

//FIXME: remove {} when CPP-1825 fixed.
template <typename T, typename Enable = std::true_type>
struct impl__IdentityHelper {
};

template <typename T>
struct impl__SampleIdentityHelper {
	static T identity(const T&) {
		return ::identity<T>();
	}
};

template <typename T>
struct impl__IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template <typename T>
T identity(const T& sample) {
	return impl__SampleIdentityHelper<T>::identity(sample);
}

template <typename T>
T identity() {
	return impl__IdentityHelper<T>::identity();
}



/**
* ax + by = result
*/
template <typename T>
T extendedGcd(T a, T b, T& x, T& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = extendedGcd(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}

template <int mod>
class Zn {
	static_assert(mod > 0, "Mod has to be positive integer");
public:

	/**
	* Not to be used
	*/
	Zn(): value(0) {
	}

	/**
	* Instead of ctor, to allow not to normalize in ctor
	*/
	static Zn valueOf(int value) {
		int x = value % mod;
		if (x < 0) {
			x += mod;
		}
		return Zn(x);
	}

	static Zn valueOf(long long value) {
		int x = static_cast<int>(value % mod);
		if (x < 0) {
			x += mod;
		}
		return Zn(x);
	}

	static Zn rawValueOf(int value) {
		SPCPPL_ASSERT(value >= 0 && value < mod);
		return Zn(value);
	}

	Zn& operator=(int rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator=(long long rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}

	Zn& operator+=(int rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator+=(long long rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod;
		}
		return *this;
	}

	Zn& operator-=(int rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator-=(long long rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		long long result = static_cast<long long>(value) * static_cast<long long>(rhs.value);
		value = static_cast<int>(result % mod);
		return *this;
	}

	Zn& operator*=(int rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn& operator*=(long long rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn operator-() const {
		if (value == 0) {
			return *this;
		}
		else {
			return Zn(mod - value);
		}
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	Zn& operator/=(int rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	Zn& operator/=(long long rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	bool operator==(const Zn& rhs) const {
		return value == rhs.value;
	}

	Zn inversed() const {
		SPCPPL_ASSERT(value != 0);

		int x, y;
		int gcd = extendedGcd(value, mod, x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		if (x < 0) {
			x += mod;
		}
		return Zn(x);
	}

	template <int m>
	friend std::ostream& operator<<(std::ostream&, const Zn<m>& zn);

	template <int m>
	friend std::istream& operator>>(std::istream&, Zn<m>& zn);

	int intValue() const {
		return value;
	}

private:
	/**
	* No normalization performed
	*/
	explicit Zn(int value): value(value) {
	}

	int value;
};

template <int m>
bool operator==(const Zn<m>& lhs, int rhs) {
	return lhs == Zn<m>::valueOf(rhs);
}

template <int m>
bool operator==(int lhs, const Zn<m>& rhs) {
	return rhs == lhs;
}
template <int m>
bool operator==(const Zn<m>& lhs, long long rhs) {
	return lhs == Zn<m>::valueOf(rhs);
}

template <int m>
bool operator==(long long lhs, Zn<m>& rhs) {
	return rhs == lhs;
}

template <int m>
bool operator!=(const Zn<m>& lhs, const Zn<m>& rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(const Zn<m>& lhs, int rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(int lhs, const Zn<m>& rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(const Zn<m>& lhs, long long rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(long long rhs, const Zn<m>& lhs) {
	return !(lhs == rhs);
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(int lhs, const Zn<m>& rhs) {
	return rhs + lhs;
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(long long lhs, const Zn<m>& rhs) {
	return rhs + lhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(int lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) - rhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(long lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) - rhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(int lhs, const Zn<m>& rhs) {
	return rhs * lhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(long long lhs, const Zn<m>& rhs) {
	return rhs * lhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(int lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) / rhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(long long lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) / rhs;
}

template <int m>
std::ostream& operator<<(std::ostream& stream, const Zn<m>& zn) {
	return stream << zn.value;
}

template <int m>
std::istream& operator>>(std::istream& stream, Zn<m>& zn) {
	long long value;
	stream >> value;
	zn.value = static_cast<int>(value % m);
	return stream;
}

template <int m>
struct impl__IdentityHelper<Zn<m>> {
	static Zn<m> identity() {
		return Zn<m>::valueOf(1);
	}
};




#include <numeric>

template <typename R>
auto prefixSums(const R& range) -> std::vector<typename R::value_type> {
	std::vector<typename R::value_type> result(
			static_cast<std::size_t>(
					std::distance(std::begin(range), std::end(range)) + 1
			)
	);
	std::partial_sum(std::begin(range), std::end(range), result.begin() + 1);
	return result;
}






template <typename T>
T gcd(T a, T b) {
	while (b) {
		T tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


template <typename T>
class Rational {
public:
	Rational(): numerator(0), denominator(1) {
	}

	Rational(T numerator): numerator(numerator), denominator(1) {
	}

	Rational(T numerator, T denominator): numerator(numerator), denominator(denominator) {
		SPCPPL_ASSERT(denominator != 0);
		normalize();
	}

	Rational& operator+=(const Rational& rhs) {
		return *this = *this + rhs;
	}

	Rational& operator-=(const Rational& rhs) {
		return *this = *this - rhs;
	}

	Rational& operator*=(const Rational& rhs) {
		numerator *= rhs.numerator;
		denominator *= rhs.denominator;
		normalize();
		return *this;
	}

	Rational operator-() const {
		return Rational(-numerator, denominator);
	}

	Rational& operator/=(const Rational& rhs) {
		SPCPPL_ASSERT(rhs.numerator != 0);
		numerator *= rhs.denominator;
		denominator *= rhs.numerator;
		normalize();
		return *this;
	}

	bool operator==(const Rational& rhs) const {
		return numerator == rhs.numerator && denominator == rhs.denominator;
	}

	const T& getNumerator() const {
		return numerator;
	}

	const T& getDenominator() const {
		return denominator;
	}

private:
	void normalize() {
		T g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;

		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}

	T numerator, denominator;

	template <typename U>
	friend Rational<U> operator+(const Rational<U>& lhs, const Rational<U>& rhs);
};


template <typename T>
Rational<T> operator+(const Rational<T>& lhs, const Rational<T>& rhs) {
	T g = gcd(lhs.denominator, rhs.denominator);
	return Rational<T>(
			lhs.numerator * (rhs.denominator / g) + rhs.numerator * (lhs.denominator / g),
			lhs.denominator / g * rhs.denominator
	);
}

template <typename T>
Rational<T> operator-(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs + (-rhs);
}

template <typename T>
Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Rational<T> operator/(const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Rational<T>& rational) {
	return stream << rational.getNumerator() << '/' << rational.getDenominator();
}

template <typename T>
struct impl__IdentityHelper<Rational<T>> {
	static Rational<T> identity() {
		return Rational<T>(1);
	}
};

template <typename T>
bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() == lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator!=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() < lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator>(const Rational<T>& lhs, const Rational<T>& rhs) {
	return rhs < lhs;
}

template <typename T>
bool operator<=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs < rhs);
}



using namespace std;

class TaskE {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		vector<int64_t> v(n);
		for (int i: range(n)) {
			in >> v[i];
			v[i];
		}
		sort(v);

		Rational<int64_t> bestAns{0, 1};
		int bestCenter = 0;
		int bestSize = 0;

		int curSize = 0;

		pref = prefixSums(v);
		this->v = v;

		for (int center = 1; center < n - 1; ++center) {
			while(curSize > (n - center - 1)) {
				--curSize;
			}
			auto curAns = get(center, curSize);
			while (curSize > 0) {
				auto nextAns = get(center, curSize - 1);
				if (nextAns > curAns) {
					--curSize;
					curAns = nextAns;
				} else {
					break;
				}
			}
			while (curSize < center && curSize < (n - center - 1)) {
				auto nextAns = get(center, curSize + 1);
				if (nextAns > curAns) {
					++curSize;
					curAns = nextAns;
				} else {
					break;
				}
			}

			if (curAns > bestAns) {
				bestAns = curAns;
				bestSize = curSize;
				bestCenter = center;
			}

		}

		out << bestSize * 2 + 1 << "\n";
		out << v[bestCenter];
		for (int k: inclusiveRange(1, bestSize)) {
			out << ' ' << v[bestCenter - k] << ' ' << v[v.size() - k];
		}
	}

	vector<int64_t> pref;
	vector<int64_t> v;

	Rational<int64_t> get(int center, int curSize) {
		size_t n = v.size();
		return Rational<int64_t>(pref[n] - pref[n - curSize] + pref[center] - pref[center - curSize] + v[center], 2 * curSize + 1) - Rational<int64_t>(v[center], 1);
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