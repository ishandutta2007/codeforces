#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector<int> z_function (const string & s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
 
void output_tandem (const string & s, int shift, bool left, int cntr, int l, int l1, int l2) {
	int pos;
	if (left)
		pos = cntr-l1;
	else
		pos = cntr-l1-l2-l1+1;
	cout << "[" << shift + pos << ".." << shift + pos+2*l-1 << "] = " << s.substr (pos, 2*l) << endl;
}
 
void output_tandems (const string & s, int shift, bool left, int cntr, int l, int k1, int k2) {
	for (int l1=1; l1<=l; ++l1) {
		if (left && l1 == l)  break;
		if (l1 <= k1 && l-l1 <= k2)
			output_tandem (s, shift, left, cntr, l, l1, l-l1);
	}
}
 
inline int get_z (const vector<int> & z, int i) {
	return 0<=i && i<(int)z.size() ? z[i] : 0;
}

struct Tandem {
	int shift;
	bool left;
	int cntr;
	int l;
	int k1;
	int k2;
	Tandem() {
	}
	Tandem(int shift, bool left, int cntr, int l, int k1, int k2)
		: shift(shift), left(left), cntr(cntr), l(l), k1(k1), k2(k2) {
	}
	
	bool operator < (const Tandem &other) const {
		return l < other.l;
	}
};

vector < Tandem > tandems;
 
void find_tandems (string s, int shift = 0) {
	int n = (int) s.length();
	if (n == 1)  return;
 
	int nu = n/2,  nv = n-nu;
	string u = s.substr (0, nu),
		v = s.substr (nu);
	string ru = string (u.rbegin(), u.rend()),
		rv = string (v.rbegin(), v.rend());
 
	find_tandems (u, shift);
	find_tandems (v, shift + nu);
 
	vector<int> z1 = z_function (ru),
		z2 = z_function (v + '#' + u),
		z3 = z_function (ru + '#' + rv),
		z4 = z_function (v);
	for (int cntr=0; cntr<n; ++cntr) {
		int l, k1, k2;
		if (cntr < nu) {
			l = nu - cntr;
			k1 = get_z (z1, nu-cntr);
			k2 = get_z (z2, nv+1+cntr);
		}
		else {
			l = cntr - nu + 1;
			k1 = get_z (z3, nu+1 + nv-1-(cntr-nu));
			k2 = get_z (z4, (cntr-nu)+1);
		}
		if (k1 + k2 >= l && k1 > 0) {
			if (l == 1 && cntr < nu) {
				continue;
			}
			if (cntr < nu && k1 + k2 == l && k2 == 0) {
				continue;
			}
			//output_tandems (s, shift, cntr<nu, cntr, l, k1, k2);
			tandems.push_back(Tandem(shift, cntr < nu, cntr, l, k1, k2));
		}
	}
}

const int maxL = 51000;
int t[maxL];

void update(int k) {
	for (int i = k; i < maxL; i |= (i + 1)) {
		++t[i];
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	find_tandems(s);

	//return 0;

	while (true) {
		tandems.clear();
		memset(t, 0, sizeof(t));
		find_tandems(s);

		if (tandems.empty()) {
			puts(s.c_str());
			return 0;
		}

		int l = 1000000;
		for (int i = 0; i < tandems.size(); ++i) {
			l = min(l, tandems[i].l);
		}
		l *= 2;

		if (s.size() <= 100) {
			l /= 2;
		}

		vector < pair < int, int > > t;
		for (int i = 0; i < tandems.size(); ++i) {
			if (tandems[i].l > l) {
				continue;
			}
			int l = tandems[i].l;
			/*
			void output_tandems (const string & s, int shift, bool left, int cntr, int l, int k1, int k2) {
				for (int l1=1; l1<=l; ++l1) {
					if (left && l1 == l)  break;
					if (l1 <= k1 && l-l1 <= k2)
						output_tandem (s, shift, left, cntr, l, l1, l-l1);
				}
			}
			*/

			for (int l1=tandems[i].k1; l1>=1; --l1) {
				if (tandems[i].left && l1 == l) continue;
				if (l1 <= tandems[i].k1 && l-l1 <= tandems[i].k2) {
					int pos;
					if (tandems[i].left)
						pos = tandems[i].cntr-l1;
					else
						pos = tandems[i].cntr-l-l1+1;
					t.push_back(make_pair(tandems[i].shift + pos, tandems[i].l));
					break;
				}
			}
		}

		sort(t.begin(), t.end());
		for (int i = 0; i < t.size(); ++i) {
			int a = t[i].first, b = t[i].first + 2 * t[i].second - 1;
			if (get(a, b) == 0) {
				for (int j = a; j <= a + t[i].second - 1; ++j) {
					update(j);
				}
			}
		}

		string ns = "";
		for (int i = 0; i < s.size(); ++i) {
			if (get(i, i) == 0) {
				ns += s[i];
			}
		}
		s = ns;
	}
	return 0;
}