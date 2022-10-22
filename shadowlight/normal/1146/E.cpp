#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e5 + 7;

struct Tree {
	vector <int> t;
	int n;
	Tree(int n) : n(n), t(2 * n, 0) {}
	void add(int v, int x) {
		v += n;
		while (v > 0) {
			t[v] += x;
			v /= 2;
		}
	}
	int get(int l, int r) {
		int res = 0;
		for (l += n, r += n; l <= r; l /= 2, r /= 2) {
			if (l % 2) {
				res += t[l++];
			}
			if (r % 2 == 0) {
				res += t[r--];
			}
		}
		return res;
	}
};

int sgn(int a, int x, bool mq) {
	if (abs(a) == abs(x)) {
		return (a > 0 ? x : -x);
	}
	return (mq ? x : -x);
}

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector <int> a(n);
	set <pair <int, int> > vals;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vals.insert({abs(a[i]), i});
	}
	Tree t1(MAXN), t2(MAXN), t3(MAXN), t4(MAXN);
	vector <pair <int, bool> > qs;
	for (int i = 0; i < q; i++) {
		char s;
		int x;
		cin >> s >> x;
		qs.push_back({x, s == '<'});
	}
	vector <int> res(n, 0);
	for (int i = q - 1; i >= 0; i--) {
		int x = qs[i].first;
		bool mq = qs[i].second;
		int t = abs(x);
		if (x > 0) {
			if (mq) {
				t1.add(t, 1);
			} else {
				t2.add(t, 1);
			}
		} else if (x < 0) {
			if (mq) {
				t3.add(t, 1);
			} else {
				t4.add(t, 1);
			}
		}
		//cout << "kekos " << i << " " << x << " " << mq << "\n";
		if ((x > 0 && mq) || (x < 0 && !mq)) {
			auto it = vals.lower_bound({t, -1});
			while (it != vals.end() && (*it).first == t) {
				int f = (*it).first;
				int valt = t1.get(f + 1, MAXN - 1) + t4.get(f + 1, MAXN - 1);
				res[(*it).second] = sgn(x, (*it).first, mq) * (valt % 2 ? -1 : 1);
				//cout << i << " " << (*it).second << " " << sgn(x, (*it).first, mq)  << "\n";
				vals.erase(it++);
			}
		}
		auto it = vals.lower_bound({t + 1, -1});
		while (it != vals.end()) {
			int f = (*it).first;
			int valt = t1.get(f + 1, MAXN - 1) + t4.get(f + 1, MAXN - 1);
			res[(*it).second] = sgn(x, (*it).first, mq) * (valt % 2 ? -1 : 1);
			//cout << i << " " << (*it).second << " " << sgn(x, (*it).first, mq)  << "\n";
			vals.erase(it++);
		}
	}
	for (auto it : vals) {
		int f = it.first;
		int valt = t1.get(f + 1, MAXN - 1) + t4.get(f + 1, MAXN - 1);
		res[it.second] = a[it.second] * (valt % 2 ? -1 : 1);
		//cout << (it).second << " " << res[(it).second] << "\n";
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}