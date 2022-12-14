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



#include <functional>


#include <cstddef>







#include <utility>

template <typename T>
constexpr auto hasBegin(int) -> decltype(std::begin(std::declval<T>()), true) {
	return true;
}

template <typename T>
constexpr bool hasBegin(...) {
	return false;
}

template <typename T>
using IsContainer = std::integral_constant<bool, hasBegin<T>(0)>;



#include <type_traits>

template <bool b, typename T = void>
using enable_if_t = typename std::enable_if<b, T>::type;



template <typename T, typename Merge>
class SegmentTreeBase {
protected:
	SegmentTreeBase(std::size_t n, const T& defaultValue = T(), const Merge& merge = Merge()):
			n(n),
			defaultValue(defaultValue),
			shift(calculateShift(n)),
			values(shift << 1, defaultValue),
			merge(merge) {

	}

	template <typename R, typename = enable_if_t<IsContainer<R>::value>>
	SegmentTreeBase(const R& range, const T& defaultValue = T(), const Merge& merge = Merge()) :
			SegmentTreeBase(
					static_cast<std::size_t>(std::distance(std::begin(range), std::end(range))),
					defaultValue,
					merge
			) {
		std::copy(std::begin(range), std::end(range), values.begin() + shift);
		for (std::size_t index: downrange(shift, static_cast<std::size_t>(1))) {
			recalculate(index);
		}
	}

	static std::size_t calculateShift(std::size_t n) {
		std::size_t result = 1;
		while (result < n) {
			result <<= 1;
		}
		return result;
	}

	void recalculate(std::size_t index) {
		values[index] = merge(values[2 * index], values[2 * index + 1]);
	}

	std::size_t n;
	T defaultValue;
	std::size_t shift;
	std::vector<T> values;
	Merge merge;
};


template <typename T, typename Merge, typename Update, typename ApplyUpdate, typename MergeUpdates>
class TopDownSegmentTree: protected SegmentTreeBase<T, Merge> {
	typedef std::size_t size_t;
public:
	template <typename R>
	TopDownSegmentTree(
			const R& range,
			const T& defaultValue = T(),
			const Merge& merge = Merge(),
			const Update& defaultUpdate = Update(),
			const ApplyUpdate& applyUpdate = ApplyUpdate(),
			const MergeUpdates& mergeUpdates = MergeUpdates()
	):
			SegmentTreeBase<T, Merge>(range, defaultValue, merge),
			defaultUpdate(defaultUpdate),
			updates(shift << 1, defaultUpdate),
			applyUpdate(applyUpdate),
			mergeUpdates(mergeUpdates) {

	}

	void update(size_t l, size_t r, const Update& update) {
		SPCPPL_ASSERT(l <= r && r <= n);
		return internalUpdate(1, 0, shift, l, r, update);
	}

	T getResult(size_t l, size_t r) {
		SPCPPL_ASSERT(l <= r && r <= n);
		return internalGet(1, 0, shift, l, r);
	}

protected:
	typedef SegmentTreeBase<T, Merge> Base;
	using Base::n;
	using Base::defaultValue;
	using Base::shift;
	using Base::values;
	using Base::merge;
private:

	void internalUpdate(size_t v, size_t vl, size_t vr, size_t l, size_t r, const Update& update) {
		if (r <= vl || l >= vr) {
			return;
		}
		if (l <= vl && vr <= r) {
			values[v] = applyUpdate(values[v], update, vl, vr);
			updates[v] = mergeUpdates(updates[v], update);
			return;
		}
		push(v, vl, vr);
		size_t vm = vl + (vr - vl) / 2;
		internalUpdate(2 * v, vl, vm, l, r, update);
		internalUpdate(2 * v + 1, vm, vr, l, r, update);
		this->recalculate(v);
	}

	T internalGet(size_t v, size_t vl, size_t vr, size_t l, size_t r) {
		if (r <= vl || l >= vr) {
			return defaultValue;
		}
		if (l <= vl && vr <= r) {
			return values[v];
		}
		push(v, vl, vr);
		size_t vm = vl + (vr - vl) / 2;
		return merge(
				internalGet(2 * v, vl, vm, l, r),
				internalGet(2 * v + 1, vm, vr, l, r)
		);
	}

	void push(size_t v, size_t vl, size_t vr) {
		size_t vm = vl + (vr - vl) / 2;
		values[2 * v] = applyUpdate(values[2 * v], updates[v], vl, vm);
		updates[2 * v] = mergeUpdates(updates[2 * v], updates[v]);
		values[2 * v + 1] = applyUpdate(values[2 * v + 1], updates[v], vm, vr);
		updates[2 * v + 1] = mergeUpdates(updates[2 * v + 1], updates[v]);

		updates[v] = defaultUpdate;
	}

	Update defaultUpdate;
	std::vector<Update> updates;
	ApplyUpdate applyUpdate;
	MergeUpdates mergeUpdates;
};


template <typename T>
struct SumUpdateApplier {
	T operator()(const T& value, const T& update, std::size_t l, std::size_t r) const {
		return value + update * (r - l);
	}
};

template <typename T>
class TopDownSumSegmentTree:
		public TopDownSegmentTree<T, std::plus<T>, T, SumUpdateApplier<T>, std::plus<T>> {
public:
	template <typename R>
	TopDownSumSegmentTree(
			const R& range,
			const T& zero = T()
	): TopDownSegmentTree<T, std::plus<T>, T, SumUpdateApplier<T>, std::plus<T>>(range, zero) {
	}

};



#include <algorithm>

struct Max {
	template <typename T>
	T operator()(const T& l, const T& r) const {
		return std::max(l, r);
	}
};


using namespace std;

class TaskC {
	int testNumber = 0;
public:
	void solve(std::istream& in, std::ostream& out) {
		//out << "Case #" << ++testNumber << ": ";
		//cerr << "Running test: " << testNumber << endl;
		//
		int n;
		in >> n;

		vector<int> push(n, -2);

		struct Update {
			int operator()(int value, int update, std::size_t l, std::size_t r) const {
				return value + update;
			}
		};

		TopDownSegmentTree<int, Max, int, Update, std::plus<int>> tree(vector<int>(n), -1000000000);

		for (int i: range(n)) {
			int p, t;
			in >> t >> p;
			if (p == 1) {
				int x;
				in >> x;
				push[t - 1] = x;
				tree.update(0, t, 1);
			} else {
				tree.update(0, t, -1);
			}
			if (tree.getResult(0, n) <= 0) {
				out << -1 << "\n";
				continue;
			}
			int r = n;
			int l = 0;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (tree.getResult(m, n) <= 0) {
					r = m;
				} else {
					l = m;
				}
			}
			out << push[l] << "\n";
		}

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