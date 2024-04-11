#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ve vector

typedef int64_t ll;
typedef ve< int > vi;

struct Func {
	ll l, a, b;
	Func(ll l_ = 0, ll a_ = 0, ll b_ = 0) : l(l_), a(a_), b(b_) {}
};

typedef ve< Func > vf;

int n;
ll k;
ve< ll > a;

void
get_funcs(int val, vf &func)
{
	func.clear();
	ll k;
	for (ll k = 1; 1ll * k * k <= val; ++k) {
		ll dv = (val + k - 1) / k;
		func.emplace_back(k, dv, -val);
	}
	for (; k >= 1; --k) {
		ll lb = (val + k - 1) / k;
		if (func.empty() || func.back().l != lb) {
			func.emplace_back(lb, k, -val);
		}
	}
}

void merge_all(const ve< vf > &funcs, int l, int r, vf &f) {
	if (l == r - 1) {
		f = funcs[l];
		return;
	}
	int mid = (l + r) / 2;
	vf fl, fr;
	merge_all(funcs, l, mid, fl);
	merge_all(funcs, mid, r, fr);
	f.clear();
	ve< ll > bord;
	int l_sz = fl.size(), r_sz = fr.size();
	for (int l_ptr = 0, r_ptr = 0; l_ptr < l_sz || r_ptr < r_sz; ) {
		ll next_b = -1;
		if (l_ptr < l_sz && (r_ptr == r_sz || fl[l_ptr].l <= fr[r_ptr].l)) {
			next_b = fl[l_ptr].l;
		} else {
			next_b = fr[r_ptr].l;
		}
		if (l_ptr < l_sz && fl[l_ptr].l == next_b) {
			++l_ptr;
		}
		if (r_ptr < r_sz && fr[r_ptr].l == next_b) {
			++r_ptr;
		}
		bord.push_back(next_b);
	}
	f.resize(bord.size());
	for (int i = 0; i < bord.size(); ++i) {
		f[i].l = bord[i];
	}
	for (int i = 0, l_ptr = 0; i < bord.size(); ++i) {
		while (l_ptr < l_sz && fl[l_ptr].l <= f[i].l) ++l_ptr;
		f[i].a += fl[l_ptr - 1].a;
		f[i].b += fl[l_ptr - 1].b;
	}
	for (int i = 0, r_ptr = 0; i < bord.size(); ++i) {
		while (r_ptr < r_sz && fr[r_ptr].l <= f[i].l) ++r_ptr;
		f[i].a += fr[r_ptr - 1].a;
		f[i].b += fr[r_ptr - 1].b;
	}
}

int
main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ve< vf > funcs(n);
	for (int i = 0; i < n; ++i) {
		get_funcs(a[i], funcs[i]);
		/*
		for (int pk = 0; pk < funcs[i].size(); ++pk) {
			const auto &v = funcs[i][pk];
			cerr << v.l << ' ' << v.a << ' ' << v.b << '\n';
		}
		cerr << "----" << endl;
		*/
	}
	vf res_f;
	merge_all(funcs, 0, funcs.size(), res_f);
	ll ans = 1ll;
	for (int i = 0; i < res_f.size(); ++i) {
		// cerr << res_f[i].l << ' ' << res_f[i].a << ' ' << res_f[i].b << '\n';
		ll lb = res_f[i].l;
		ll val = (k - res_f[i].b) / res_f[i].a;
		// cerr << lb << ' ' << val << '\n';
		if (val >= lb && (i == res_f.size() - 1 || val < res_f[i + 1].l)) {
			ans = max(ans, val);
		}
	}
	cout << ans << '\n';
	return 0;
}