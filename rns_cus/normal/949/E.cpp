#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;

vector<int> v;

vector<int> func(vector<int> a) {
	sort(a.begin(), a.end());
	int sz = unique(a.begin(), a.end()) - a.begin();
	a.resize(sz);
	for (int i = 0; i < sz; i ++) {
		if (a[i] == 0) {
			swap(a[i], a.back());
			a.pop_back();
			break;
		}
	}
	sz = a.size();
	if (sz == 0) {
		vector<int> c;
		return c;
	}
	if (sz == 1) {
		vector<int> c;
		if (a[0] == 0) return c;
		if (a[0] == 1) {
			c.push_back(1);
			return c;
		}
		if (a[0] == -1) {
			c.push_back(-1);
			return c;
		}
	}
	vector<int> l, r;
	bool odd = 0;
	for (int i = 0; i < sz; i ++) {
		if (a[i] % 2 == 0) l.push_back(a[i] / 2), r.push_back(a[i] / 2);
		else odd = 1, l.push_back((a[i] - 1) / 2), r.push_back((a[i] + 1) / 2);
	}
	vector<int> c = func(l);
	vector<int> d = func(r);
	if (c.size() < d.size()) {
		for (int i = 0; i < c.size(); i ++) c[i] *= 2;
		if (odd) c.push_back(1);
		return c;
	}
	else {
		for (int i = 0; i < d.size(); i ++) d[i] *= 2;
		if (odd) d.push_back(-1);
		return d;
	}
}

int main() {
	cin>>n;
	v.resize(n);
	for (int i = 0; i < n; i ++) scanf("%d", &v[i]);
	vector<int> ans = func(v);
	cout<<ans.size()<<endl;
	for (int x:ans) printf("%d ", x);
}