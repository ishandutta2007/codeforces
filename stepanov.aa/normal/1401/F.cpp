#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Bin_swaper {
public:
	vector<long long> d;
	int n;
	int len;
	vector<bool> reversed;
	vector<bool> swaped;

	long long pow(int x, int y) {
		long long res = 1;
		for (int i = 0; i < y; ++i) {
			res *= x;
		}
		return res;
	}


	int log(int x) {
		int res = 0;
		while (x > 1) {
			x = ceil(x / 2.0);
			++res;
		}
		return res;
	}


	Bin_swaper() {

	}


	Bin_swaper(int n) : len(pow(2, n)), d(pow(2, n + 1), 0), reversed(n + 1, false), swaped(n + 1, false) {
		this->n = n;
	}


	Bin_swaper(const vector<int> &a) {
		n = log(a.size());
		len = pow(2, n);
		d = vector<long long>(pow(2, n + 1), 0);
		reversed = vector<bool>(n + 1, false);
		swaped = vector<bool>(n + 1, false);
		build(a);
	}


	void swap(int k) {
		if (k + 1 <= n) {
			swaped[k + 1] = !swaped[k + 1];
		}
	}


	void reverse(int k) {
		reversed[k] = !reversed[k];
	}


	void build(const vector<int>& a) {
		int i = 0;
		build(1, 0, len - 1, i, a);
	}


	void build(int v, int tl, int tr, int &i, const vector<int> &a)
	{
		if (tl == tr) {
			d[v] = a[i];
			++i;
		}
		else {
			int tm = (tl + tr) / 2;
			build(2 * v, tl, tm, i, a);
			build(2 * v + 1, tm + 1, tr, i, a);
			d[v] = d[2 * v] + d[2 * v + 1];
		}
	}


	void set_item(int v, int tl, int tr, int i, int x, int rev_ind, bool rev)
	{
		rev = rev ^ reversed[rev_ind];
		if (tl == tr) {
			d[v] = x;
		}
		else {
			if (!(rev ^ swaped[rev_ind])) {
				int tm = (tl + tr) / 2;
				if (tm >= i) {
					set_item(2 * v, tl, tm, i, x, rev_ind - 1, rev);
				}
				else {
					set_item(2 * v + 1, tm + 1, tr, i, x, rev_ind - 1, rev);
				}
				d[v] = d[2 * v] + d[2 * v + 1];
			}
			else {
				int tm = (tl + tr) / 2;
				if (tm >= i) {
					set_item(2 * v + 1, tl, tm, i, x, rev_ind - 1, rev);
				}
				else {
					set_item(2 * v, tm + 1, tr, i, x, rev_ind - 1, rev);
				}
				d[v] = d[2 * v] + d[2 * v + 1];
			}
		}
	}

	void set_item(int i, int x)
	{

		set_item(1, 0, len - 1, i, x, n, 0);
	}


	long long get_summ(int v, int tl, int tr, int l, int r, int rev_ind, bool rev)
	{
		rev = rev ^ reversed[rev_ind];
		if (l > r) {
			return 0;
		}
		else if (tl == l && tr == r) {
			return d[v];
		}
		else {
			int tm = (tl + tr) / 2;
			if (!(rev ^ swaped[rev_ind])) {
				return get_summ(2 * v, tl, tm, l, min(tm, r), rev_ind - 1, rev) + get_summ(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, rev_ind - 1, rev);
			}
			else {
				return get_summ(2 * v + 1, tl, tm, l, min(tm, r), rev_ind - 1, rev) + get_summ(2 * v, tm + 1, tr, max(tm + 1, l), r, rev_ind - 1, rev);
			}
		}
	}


	long long get_summ(int l, int r) {
		return get_summ(1, 0, len - 1, l, r, n, 0);
	}


};


int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; ++i) {
		res *= x;
	}
	return res;
}


int main() {

	int n, q;
	cin >> n >> q;
	int len = pow(2, n);
	vector<int> a(len);
	for (int i = 0; i < len; ++i) {
		cin >> a[i];
	}
	Bin_swaper s(a);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, k;
			cin >> x >> k;
			--x;
			s.set_item(x, k);
		}
		else if (t == 2) {
			int k;
			cin >> k;
			s.reverse(k);
		}
		else if (t == 3) {
			int k;
			cin >> k;
			s.swap(k);
		}
		else if (t == 4) {
			int l, r;
			cin >> l >> r;
			--l;
			--r;

			cout << s.get_summ(l, r) << '\n';
		}
	}


	
	return 0;
}