/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <array>


#include <algorithm>
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


using namespace std;
struct Value {
	array<int64_t, 10> cnt;
	Value() {
		cnt.fill(0);
	}
};

struct Update {
	array<int, 10> where;
	Update() {
		for (int i = 0; i < 10; ++i) {
			where[i] = i;
		}
	}

	bool id() const {
		for (int i: range(10)) {
			if (where[i] != i) {
				return false;
			}
		}
		return true;
	}
};

struct Merge {
	Value operator() (const Value& a, const Value& b) const {
		Value res;
		for (int i: range(10)) {
			res.cnt[i] = a.cnt[i] + b.cnt[i];
		}
		return res;
	}
};


struct MergeUpdate {
	Update operator()(const Update& a, const Update& b) const {
		if (a.id()) {
			return b;
		}
		if (b.id()) {
			return a;
		}
		Update res;

		for (int i: range(10)) {
			res.where[i] = b.where[a.where[i]];
		}
		return res;
	}
};

struct ApplyUpdate {
	Value operator() (Value old, Update update, size_t, size_t) const {
		Value res;
		for (int i: range(10)) {
			res.cnt[update.where[i]] += old.cnt[i];
		}
		return res;
	}
};
class TaskF {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, q;
		in >> n >> q;

		vector<Value> value(n);

		for (int i: range(n)) {
			string s;
			in >> s;
			reverse(s);

			int64_t pw = 1;
			for(char c: s) {
				value[i].cnt[c - '0'] += pw;
				pw *= 10;
			}
		}
		TopDownSegmentTree<Value, Merge, Update, ApplyUpdate, MergeUpdate> tree(value);

		for (int i: range(q)) {
			int t;
			in >> t;
			if (t == 1) {
				int l, r;
				in >> l >> r;
				--l;
				int x, y;
				in >> x >> y;
				Update update;
				update.where[x] = y;
				tree.update(l, r, update);
			} else {
				int l, r;
				in >> l >> r;
				--l;
				auto res = tree.getResult(l, r);
				int64_t ans = 0;
				for (auto i: range(10)) {
					//cerr << i << ' ' << res.cnt[i] << endl;
					ans += i * res.cnt[i];
				}
				out << ans << "\n";
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskF solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}