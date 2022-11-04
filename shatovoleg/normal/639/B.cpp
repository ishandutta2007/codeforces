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

int n, d, h;
vector<vector<int>> vertices;
vector<pii> rez;
void pe(int a, int b) {
	a++;
	b++;
	rez.pb(mp(a, b));
}

int main(int argc, char *argv[]) {
	cin >> n >> d >> h;
	

	if (d - h > h) {
		cout << -1;
		return 0;
	}

	if (n > 2 && d < 2) {
		cout << -1;
		rt;
	}
	int cnt = 0;
	vertices.resize(n);
	// cout << "Height Main Root\n";
	for (int i = 0; i < h; i++) {
		// vertices[i].pb(i + 1);
		pe(i, i + 1);
		cnt++;
	}
	int after = h + 1;
	int after2 = h + 1;
	// cout << "Diamteter Center\n";
	if (d - h > 0) {
		pe(0, after);
		after2++;
		cnt++;
	}
	for (int i = 0; i < d - h - 1; i++) {
		pe(i + after, i + after + 1);
		vertices[i + after].pb(i + after + 1);
		after2++;
		cnt++;
	}

	int middle = (d + 1) / 2 + ((d + 1) % 2);
	// cout << middle << " " << d;
	int vmid = middle - (d - h) - 1;
	int left_dist = (d - h);
	int right_dist = h;
	bool mid_found = false;
	for (int i = 0; i < n; i++) {
		if (abs(left_dist - right_dist) <= 1) {
			vmid = i;
			mid_found = true;
			break;
		}
		left_dist++;
		right_dist--;
	}
	if (!mid_found) {
		assert(false);
	}
	// cout << vmid << endl;
	// if (vmid < 0) {
	// 	vmid = after + abs(vmid);
	// }
	// cout << "Next Shit" << endl;

	for (; after2 < n; after2++) {
		pe(vmid, after2);
		cnt++;
		vertices[vmid].pb(after2);
	}
	if (rez.size() != n - 1) {
		cout << -1 << endl;
		return 0;
	}

	for (auto x : rez) {
		cout << x.x << " " << x.y << endl;
	}
	// for (int i = 0; i < vertices.size(); i++) {
	// 	for (int j = 0; j < vertices[i].size(); j++) {
	// 		cout << i + 1 << " " << vertices[i][j] + 1 << endl;
	// 	}
	// }
	rt;
}