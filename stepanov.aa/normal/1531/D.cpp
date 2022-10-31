#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <set>


using namespace std;


#define ll long long
#define all(a) a.begin(), a.end()
#define pb push_back


struct SGT {
	int n;
	vector<int> t;
	vector<int> dt;


	void add_to_seg(int v, int x) {
		dt[v] += x;
		t[v] += x;
	}


	void upd(int v) {
		t[v] = min(t[v + v], t[v + v + 1]);
	}


	void push(int v) {
		add_to_seg(v + v, dt[v]);
		add_to_seg(v + v + 1, dt[v]);
		dt[v] = 0;
	}


	void add(int v, int tl, int tr, int l, int r, int x) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			add_to_seg(v, x);
			return;
		}
		int tm = (tl + tr) / 2;
		push(v);
		add(v + v, tl, tm, l, r, x);
		add(v + v + 1, tm + 1, tr, l, r, x);
		upd(v);
	}

	void add(int l, int r, int x) {
		add(1, 0, n - 1, l, r, x);
	}


	void build(int _n) {
		n = 1;
		while (n < _n) {
			n = (n << 1);
		}
		t.resize(n + n + n);
		dt.resize(n + n + n);
		if (n != _n) {
			add(_n, n - 1, 1);
		}
	}


	int get_last(int v, int tl, int tr) {
		if (tl == tr) {
			return tl;
		}
		int tm = (tl + tr) / 2;
		push(v);
		if (t[v + v + 1] == 0) {
			return get_last(v + v + 1, tm + 1, tr);
		}
		else {
			return get_last(v + v, tl, tm);
		}
	}

	int get_last() {
		return get_last(1, 0, n - 1);
	}
};


struct cmnd {
	bool lck;
	int i;

	cmnd(int i) : i(i) {}
	cmnd(int i, bool lck) : i(i), lck(lck) {}
};


bool operator<(const cmnd& c1, const cmnd& c2) {
	return c1.i < c2.i;
}


int n;
SGT sgt;
vector<string> cmnds;
set<cmnd> a;


void add_cmnd(cmnd c) {
	auto [it, _] = a.insert(c);
	int r = n;
	++it;
	if (it != a.end()) {
		r = it->i;
	}
	--it;
	if (it != a.begin()) {
		--it;
		if (it->lck) {
			sgt.add(c.i, r - 1, -1);
		}
		++it;
	}
	if (c.lck) {
		sgt.add(c.i, r - 1, 1);
	}
	else {
		sgt.add(c.i, c.i, 1);
	}
}


void del_cmnd(int i) {
	auto it = a.find(cmnd(i));
	int r = n;
	++it;
	if (it != a.end()) {
		r = it->i;
	}
	--it;
	if (it->lck) {
		sgt.add(i, r - 1, -1);
	}
	else {
		sgt.add(i, i, -1);
	}
	if (it == a.begin()) {
		a.erase(it);
	}
	else {
		a.erase(it--);
		if (it->lck) {
			sgt.add(i, r - 1, 1);
		}
	}
}


bool is_command(string &s) {
	return (s == "lock") || (s == "unlock");
}


void set_val(int i, string s) {
	if (is_command(cmnds[i])) {
		del_cmnd(i);
	}
	cmnds[i] = s;
	if (is_command(s)) {
		cmnd c(i);
		if (s == "lock") {
			c.lck = true;
		}
		else if (s == "unlock") {
			c.lck = false;
		}
		add_cmnd(c);
	}
}


string get_res() {
	int i = sgt.get_last();
	return cmnds[i];
}


int32_t main() {
	cin >> n;
	n += 1;
	sgt.build(n);
	cmnds.resize(n, string("blue"));
	for (int i = 1; i < n; ++i) {
		string s;
		cin >> s;
		set_val(i, s);
	}
	int t;
	cin >> t;
	cout << get_res() << "\n";
	while (t--) {
		int i;
		string s;
		cin >> i >> s;
		set_val(i, s);
		cout << get_res() << "\n";
	}
	return 0;
}