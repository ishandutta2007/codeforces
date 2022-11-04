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

#define nl "\n"
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
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
#define rt return 0
#define elif else if
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i > -1; i--)
#define fk(i, begin, n, k) for (int i = begin; i < n; i += k)
#define fall(x, seq) for (auto& x : seq)
#define u2a(seq, function) \
    for (auto& x : seq) {  \
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
ostream& operator<<(ostream& os, pair<T_First, T_Second>& p)
{
    os << p.first << " " << p.second;
    return os;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
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
ostream& operator<<(ostream& os, vector<vector<T> >& v)
{
    f(i, v.size() - 1)
    {
        os << v[i];
        os << nl;
    }
    if (!v.empty()) {
        os << v[v.size() - 1];
    }
    return os;
}


template <class T_First, class T_Second>
istream& operator>>(istream& is, pair<T_First, T_Second>& p)
{
    is >> p.first >> p.second;
    return is;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v)
{
    f(i, v.size())
    {
        is >> v[i];
    }
    return is;
}
}// namespace Smart_IO_Stream

void set_accuracy(int accure)
{
    cout << setprecision(accure) << fixed;
}

namespace defython {
// vector<xrange> xrange::xranges = vector<xrange>();
template <class T>
long long sum(vector<T>& v)
{
    long long rez = 0;
    fall(x, v)
    {
        rez += x;
    }
    return rez;
}

template <class T>
T max(vector<T>& v)
{
    if (v.size() == 0) {
        return NULL;
    }
    T assume_max = v[0];
    fall(x, v)
    {
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
typedef vector<vector<pair<int, int> > > vvpii;
typedef vector<vector<pair<bool, int> > > vvpbi;
}

using namespace Smart_IO_Stream;
using namespace typedefs;



int main(int argc, char *argv[]) {
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<int> boxes(n + 1);
	boxes[0] = -1;
	for (int i = 0; i < n; i++) {
		cin >> boxes[i + 1];
	}
	sort(boxes.begin(), boxes.end());
	vector<int> first_free(boxes.size());
	int bcnt = boxes.size();
	first_free[bcnt - 1] = boxes[bcnt - 1] + 1;
	for (int i = boxes.size() - 2; i > -1; i--) {
		if (boxes[i] + 1 == boxes[i + 1]) {
			first_free[i] = first_free[i + 1];
		} else {
			first_free[i] = boxes[i] + 1;
		}
	}
	vector<int> prev(boxes.size(), -1);
	int over_token = 0;
	for (int i = 1; i < boxes.size(); i++) {
		// cout << over_token << " ";
		int razg_need = boxes[i] - boxes[i - 1] - 2;
		if (razg_need >= s) {
			while ((over_token + 1 < boxes.size()) 
				&& (first_free[over_token + 1] - boxes[i] + 1 <= d)) {
				prev[over_token + 1] = i;
				over_token++;
			}
		}
		if (over_token < i) {
			cout << "IMPOSSIBLE";
			rt;
		}
	}
	// cout << nl;
	// cout << prev;
	vector<pair<string, int>> way;
	int cur = m;
	int iter = bcnt - 1;
	while (prev[iter] != -1) {
		if (cur - boxes[iter] - 1 >= 1) {
			way.pb(mp("RUN", cur - boxes[iter] - 1));
		}
		int place_past = boxes[iter] + 1;
		iter = prev[iter];
		way.pb(mp("JUMP", place_past - boxes[iter] + 1));
		cur = boxes[iter] - 1;
		iter--;
	}
	way.pb(mp("RUN", cur));
	reverse(way.begin(), way.end());
	for (auto x : way) {
		cout << x << endl;
	}
	rt;
}