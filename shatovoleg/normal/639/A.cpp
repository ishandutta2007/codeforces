#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <fstream>
#include <array>
#include <list>
#include <functional>


#define print cout,
#define scan cin,
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mt make_tuple
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define rt return 0
#define elif else if
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i > -1; i--)
#define fk(i, begin, n, k) for (int i = begin; i < n; i += k)
#define fall(x, seq) for (auto &x : seq)
#define u2a(seq, function) \
for (auto &x : seq) {  \
	x = function(x);   \
}
#define ifhas(tf, x, map) \
\
auto x = map.find(tf);    \
\
if(x != map.end())
#define ifnhas(tf, map) if (map.find(tf) == map.end())
#define fe for_each

using namespace std;

// I/O Stream Manager
namespace Smart_IO_Stream {

	template <class T_First, class T_Second>
	ostream& operator<<(ostream& os, const pair<T_First, T_Second> &p) {
		os << p.first << " " << p.second;
		return os;
	}

	template <class T>
	ostream& operator<<(ostream& os, const vector<T> &v) {
		f(i, v.size() - 1)
		{
			os << v[i] << " ";
		}
		if (!v.empty()) {
			os << v[v.size() - 1];
		}
		return os;
	}

	template <class T>
	ostream& operator<<(ostream& os, const vector<vector<T>> &v) {
		f(i, v.size() - 1)
		{
			os << v[i];
			os << endl;
		}
		if (!v.empty()) {
			os << v[v.size() - 1];
		}
		return os;
	}


	template <class T_First, class T_Second>
	istream& operator>>(istream& is, pair<T_First, T_Second>& p) {
		is >> p.first >> p.second;
		return is;
	}

	template <class T>
	istream& operator>>(istream& is, vector<T>& v) {
		f(i, v.size())
		{
			is >> v[i];
		}
		return is;
	}

	template<class T>
	istream &operator,(istream &is, T &obj) {
		is >> obj;
		return is;
	}

	template<class T>
	ostream &operator,(ostream &os, const T &obj) {
		return (os << obj << " ");
	}
	

	enum OutSymb {
		nl, ptr, 
	};

	ostream &operator,(ostream &os, OutSymb s) {
		switch (s) {
			case nl:
				os << endl;
				break;
			case ptr:
				os << "-> ";
				break;
			default:
				break;
		}
		return os;
	}
}// namespace Smart_IO_Stream


void set_accuracy(int accure) {
	cout << setprecision(accure) << fixed;
}

namespace defython {
	// vector<xrange> xrange::xranges = vector<xrange>();
	template <class T>
	long long sum(vector<T>& v) {
		long long rez = 0;
		fall(x, v) {
			rez += x;
		}
		return rez;
	}

	template <class T>
	T max(vector<T>& v) {
		if (v.size() == 0) {
			return NULL;
		}
		T assume_max = v[0];
		fall(x, v) {
			if (assume_max < x) {
				assume_max = x;
			}
		}
		return assume_max;
	}

}// namespace defython

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef vector<int> vi;
	typedef pair<int, int> pii;
	typedef vector<vector<pair<int, int>>> vvpii;
	typedef vector<vector<pair<bool, int>>> vvpbi;
}

using namespace Smart_IO_Stream;
using namespace typedefs;


int main(int argc, char *argv[]) {
	int n, k, q;
	scan n, k, q;
	vector<int> friend_factor(n);
	cin >> friend_factor;
	auto cmp = [](pii a, pii b) {
		return a.y < b.y;
	};
	priority_queue<pii, vector<pii>, decltype(cmp)> deque(cmp);
	for (int query_id = 0; query_id < q; query_id++) {
		int qtype, id;
		scan qtype, id;
		if (qtype == 1) {
			pii p = mp(id - 1, friend_factor[id - 1]);
			deque.push(p);
		} else {
			id--;
			vector<pii> deleted;
			bool find = false;
			for (int i = 0; i < k; i++) {
				if (deque.empty()) {
					break;
				}
				deleted.pb(deque.top());
				deque.pop();
				if (deleted.back().first == id) {
					find = true;
					cout << "YES" << endl;
					break;
				}
			}
			if (!find) {
				cout << "NO" << endl;
			}
			for (pii p : deleted) {
				deque.push(p);
			}
		}
	}
	rt;
}