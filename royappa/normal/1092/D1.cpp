#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i] %= 2;
	}
	set<vector<int>> ints;
	set<vector<int>> evens;

	v.push_back(-1);
	vector<int> e = {0,v[0],1}; // left, which, len
	for (int i = 1; i < n+1; i++) {
		if (v[i] == v[i-1]) {
			e[2] = (e[2]+1)%2;
		}
		else {
			ints.insert(e);
			if (e[2]%2 == 0) {
				evens.insert(e);
			}
			e = {i, v[i], 1};
		}
	}

	while (evens.size() > 0 && ints.size() > 1) {
/*
cout << "Evens:" <<endl;
for (auto z : evens) {
	cout << z[0] << " " << z[1] << " " << z[2] << endl;
}*/
		vector<int> x = *(evens.begin());
		evens.erase(x);
		auto px = ints.find(x);
		vector<int> r = {x[0], 1-x[1], 0};
		if (px == ints.begin()) {
			r[2] = x[2];
		}
		else {
			auto p = px; p--;
			r[2] = (r[2]+(*p)[2])%2;
		}
		auto pp = px; pp++;
		if (pp != ints.end()) {
			r[2] = (r[2]+(*pp)[2])%2;
		}
		if (pp == ints.end()) {
			pp = px; pp--;
			vector<int> y = *pp;
			ints.erase(y);
			if (y[2]%2 == 0) evens.erase(y);
			ints.erase(x);
		}
		else if (px == ints.begin()) {
			pp = px;
			pp++;
			vector<int> y = *pp;
			ints.erase(y);
			if (y[2]%2 == 0) evens.erase(y);
			ints.erase(x);
		}
		else {
			pp = px;
			pp--;
			auto qq = px;
			qq++;
			vector<int> y = *pp, z = *qq;
			ints.erase(y);
			if (y[2]%2 == 0) evens.erase(y);
			ints.erase(z);
			if (z[2]%2 == 0) evens.erase(z);
			ints.erase(x);
		}
//cout << "r is " << r[0] << " " << r[1] << " " << r[2] << endl;

		ints.insert(r);
		if (r[2]%2 == 0) {
			evens.insert(r);
		}
	}
	cout << (ints.size() > 1 ? "NO" : "YES") << endl;
	exit(0);
}