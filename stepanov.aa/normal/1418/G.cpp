#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


int n;
int e;
vector<int> a;
vector<int> b;
vector<int> d;
vector<int> mx;
vector<int> mxs;
long long summ = 0;


void get_max(vector<int>& a, int& max, int& c, int l, int r) {
	max = 0;
	c = 0;
	for (int i = l; i < r; ++i) {
		if (a[i] > max) {
			max = a[i];
			c = 1;
		}
		else if(a[i] == max){
			++c;
		}
	}
}


void plus_x(int l, int r, int x) {
	if (l < 0) {
		return;
	}
	int tl = l / e;
	int tr = (r - 1) / e;
	if (tl >= tr) {
		for (int i = l; i < r; ++i) {
			b[i] += x;
		}
		get_max(b, mx[tl], mxs[tl], tl * e, min((tl + 1) * e, (int)(a.size())));
		mx[tl] += d[tl];
		return;
	}
	for (int i = l; i < (tl + 1) * e; ++i) {
		b[i] += x;
	}
	for (int i = tr * e; i < r; ++i) {
		b[i] += x;
	}
	get_max(b, mx[tl], mxs[tl], tl * e, min((tl + 1) * e, (int)(a.size())));
	get_max(b, mx[tr], mxs[tr], tr * e, min((tr + 1) * e, (int)(a.size())));
	mx[tl] += d[tl];
	mx[tr] += d[tr];
	for (int i = tl + 1; i < tr; ++i) {
		mx[i] += x;
		d[i] += x;
	}
}


long long get_summ(int l, int r) {
	if (l < 0) {
		return 0;
	}
	long long res = 0;
	int tl = l / e;
	int tr = (r - 1) / e;
	if (tl >= tr) {
		for (int i = l; i < r; ++i) {
			if (b[i] + d[tl] == n) {
				++res;
			}
		}
		return res;
	}
	for (int i = l; i < (tl + 1) * e; ++i) {
		if (b[i] + d[tl] == n) {
			++res;
		}
	}
	for (int i = tr * e; i < r; ++i) {
		if (b[i] + d[tr] == n) {
			++res;
		}
	}
	for (int i = tl + 1; i < tr; ++i) {
		if (mx[i] == n) {
			res += mxs[i];
		}
	}
	return res;
}


int get_i(int i) {
	return b[i] + d[i / e];
}


void print_b() {
	for (int i = 0; i < n; ++i) {
		cout << get_i(i) << " ";
	}
	cout << endl;
}


int main() {
	cin >> n;
	e = ceil(sqrt(double(n)));
	a.resize(n);
	b.resize(n);
	d.resize(e);
	mx.resize(e);
	mxs.resize(e);
	for (int i = 0; i < e; ++i) {
		d[i] = 0;
		mx[i] = n;
		mxs[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = n;
	}
	vector<vector<int>> dinam(n + 1, vector<int>(4, -1));
	long long res = 0;
	for (int i = 0; i < n; ++i) {

		plus_x(dinam[a[i]][0] + 1, dinam[a[i]][1] + 1, -1);
		plus_x(dinam[a[i]][3] + 1, i + 1, -1);
		for (int j = 1; j < 4; ++j) {
			swap(dinam[a[i]][j], dinam[a[i]][j - 1]);
		}
		dinam[a[i]][3] = i;
		plus_x(dinam[a[i]][0] + 1, dinam[a[i]][1] + 1, 1);

		long long resi = get_summ(dinam[a[i]][0] + 1, dinam[a[i]][1] + 1);
		//cout << i << " " << resi << endl;
		res += resi;

		//print_b();
	}
	cout << res << endl;
	return 0;
}

/*
20
1 1 1 1 1 2 2 2 2 1 1 1 1 1 1 2 2 2 2 2
*/