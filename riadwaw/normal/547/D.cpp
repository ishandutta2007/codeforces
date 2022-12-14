/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <set>
#include <map>


#include <iterator>

#include <string>
#include <stdexcept>
#ifdef SPCPPL_DEBUG
	#define SPCPPL_ASSERT(condition) \
	if(!(condition)) { \
		throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
	}
#else
	#define SPCPPL_ASSERT(condition)
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
class IntegerIterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(int value): value(value) {

	}

	IntegerIterator& operator++ () {
		++value;
		return *this;
	}

	IntegerIterator operator++ (int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator-- () {
		--value;
		return *this;
	}

	IntegerIterator operator-- (int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator * () const {
		return value;
	}

	bool operator == (IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator != (IntegerIterator rhs) {
		return !(*this == rhs);
	}
private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {

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
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from, to);
}

using namespace std;
class TaskD {
public:

	string ans;
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		ans.assign(n, 'x');
		vector<int> x(n), y(n);
		map<int, set<int>> byx, byy;

		set<int> need;
		for(int i :range(n)) {
			in >> x[i] >> y[i];
			need.insert(i);
			byx[x[i]].insert(i);
			byy[y[i]].insert(i);
		}

		set<pair<int, int>> onlys;


		while(!need.empty()) {
			int del = *need.begin();
			need.erase(need.begin());

			print(del, byx, byy, x, y, 'r');
			int w = 0;
			int coord = x[del];
			while(true) {
				const set<int>& it = ((w == 0) ? byx : byy)[coord];
				if(it.empty()) {
					break;
				}
				int cur = *it.begin();
				need.erase(cur);
				print(cur, byx, byy, x, y, w == 0 ? 'b' : 'r');
				coord = (w == 0) ? y[cur] : x[cur];
				w = !w;


			}
			w = 1;
			coord = y[del];
			while(true) {
				const set<int>& it = ((w == 0) ? byx : byy)[coord];
				if(it.empty()) {
					break;
				}
				int cur = *it.begin();
				need.erase(cur);
				print(cur, byx, byy, x, y, w == 0 ? 'r' : 'b');
				coord = (w == 0) ? y[cur] : x[cur];
				w = !w;


			}
		}

		out << ans;

	}

	void print(int v, map<int, set<int>>& bx, map<int, set<int>>& by, const vector<int>& x, const vector<int>& y, char c) {
		bx[x[v]].erase(v);
		by[y[v]].erase(v);
		ans[v] = c;
	}
};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}