#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

//vector<string> names = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
//map<string, int> mapping;
vector<string> a;
set<int> u, l;
set<pair<int, bool>> ul;
vector<bool> ini;
vector<bool> t;
vector<int> buf;

void build_tree(int v, int l, int r) {
	if (l == r - 1) {
		t[v] = ini[l];
		return;
	}
	int mid = (l + r) / 2;
	build_tree(2 * v + 1, l, mid);
	build_tree(2 * v + 2, mid, r);
	t[v] = t[2 * v + 1] || t[2 * v + 2];
}

void upd(int v) {
	if (buf[v] == -1) {
		return;
	}
	if (2 * v + 2 < buf.size()) {
		buf[2 * v + 1] = buf[2 * v + 2] = buf[v];
	}
	t[v] = buf[v];
	buf[v] = -1;
}

int where(int v, int l, int r) {
	if (l == r - 1) {
		if (!t[v]) {
			return -1;
		}
		return l;
	}
	upd(2 * v + 1);
	upd(2 * v + 2);
	int mid = (l + r) / 2;
	if (t[2 * v + 2]) {
		return where(2 * v + 2, mid, r);
	} else {
		return where(2 * v + 1, l, mid);
	}
}

void set_seg(int v, int l, int r, int L, int R, bool x) {
	upd(v);
	if (r <= L || R <= l) {
		return;
	}
	if (L <= l && r <= R) {
		buf[v] = x;
		upd(v);
		return;
	}
	int mid = (l + r) / 2;
	set_seg(2 * v + 1, l, mid, L, R, x);
	set_seg(2 * v + 2, mid, r, L, R, x);
	t[v] = t[2 * v + 1] || t[2 * v + 2];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    /*forn (i, names.size()) {
    	mapping[names[i]] = i;
    }*/
    int n;
    cin >> n;
    a.resize(n);
    ini.resize(n);
    bool lock = false;
    ul.insert({-1, false});
    ul.insert({n, true});
    forn (i, n) {
    	string s;
    	cin >> s;
    	a[i] = s;
    	if (s == "unlock") {
    		lock = false;
    		ul.insert({i, false});
    	} else if (s == "lock") {
    		lock = true;
    		ul.insert({i, true});
    	} else {
    		ini[i] = !lock;
    	}
    }
    int tree_sz = 1;
    while (tree_sz < n * 2) {
    	tree_sz *= 2;
    }
    t.resize(tree_sz);
    buf.assign(tree_sz, -1);
    build_tree(0, 0, n);
    int tmp = where(0, 0, n);
    if (tmp == -1) {
    	cout << "blue\n";
    } else {
	    cout << a[tmp] << '\n';
	}
    int q;
    cin >> q;
    while (q--) {
    	int i;
    	cin >> i;
    	i--;
    	if (a[i] == "unlock") {
    		auto it = ul.lower_bound({i, false});
    		it--;
    		if (it->second) {
    			it++;
    			it++;
    			set_seg(0, 0, n, i, it->first, false);
    			it--;
    		} else {
    			set_seg(0, 0, n, i, i + 1, true);
    			it++;
    		}
    		ul.erase(it);
    	} else if (a[i] == "lock") {
    		auto it = ul.lower_bound({i, false});
    		it--;
    		if (!it->second) {
    			it++;
    			it++;
    			set_seg(0, 0, n, i, it->first, true);
    			it--;
    		} else {
    			it++;
    		}
    		ul.erase(it);
    	}
    	string s;
    	cin >> s;
    	a[i] = s;
    	if (s == "unlock") {
    		ul.insert({i, false});
    		auto it = ul.lower_bound({i, false});
    		it--;
    		if (it->second) {
    			it++;
    			it++;
    			set_seg(0, 0, n, i + 1, it->first, true);
    		} else {
    			set_seg(0, 0, n, i, i + 1, false);
    		}
    	} else if (s == "lock") {
    		ul.insert({i, true});
    		auto it = ul.lower_bound({i, false});
    		it--;
    		if (!it->second) {
    			it++;
    			it++;
    			set_seg(0, 0, n, i, it->first, false);
    		}
    	}
    	int tmp = where(0, 0, n);
	    if (tmp == -1) {
	    	cout << "blue\n";
	    } else {
		    cout << a[tmp] << '\n';
		}
    }
    return 0;
}