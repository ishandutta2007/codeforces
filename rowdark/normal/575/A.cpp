#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, TN = N << 1;

struct Matrix {
	int a[2][2];

	Matrix(int type = 0) {
		memset(a, 0, sizeof(a));
		if (type) {
			a[0][0] = a[1][1] = 1;
		}
	}

	const int* operator[] (const int &i) const {
		return a[i];
	}

	int* operator[] (int i) {
		return a[i];
	}
};

long long k, p;

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ret;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ret[i][j] = ((long long)a[i][0] * b[0][j] + (long long)a[i][1] * b[1][j]) % p;
		}
	}
	return ret;
}

Matrix pow(Matrix &a, long long n) {
	Matrix ret(1);
	while (n) {
		if (n & 1) {
			ret = ret * a;
		}
		a = a * a;
		n >>= 1;
	}
	return ret;
}

Matrix fibo(const int &si, const int &si1) {
	Matrix ret;
	ret[1][0] = 1;
	ret[0][1] = si;
	ret[1][1] = si1;
	return ret;
}

int n, m;

int s[N];

Matrix ma[TN];

inline int getID(int l, int r) {
	return l + r | l != r;
}

void init(int l, int r) {
	if (l == r) {
		ma[getID(l, r)] = fibo(s[l], s[l + 1]);
		return;
	}
	int m = l + r >> 1;
	init(l, m), init(m + 1, r);
	ma[getID(l, r)] = ma[getID(l, m)] * ma[getID(m + 1, r)];
}

Matrix getMa(int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return ma[getID(l, r)];
	}
	int m = l + r >> 1;
	if (b <= m) {
		return getMa(l, m, a, b);
	} else if (m < a) {
		return getMa(m + 1, r, a, b);
	} else {
		return getMa(l, m, a, b) * getMa(m + 1, r, a, b);
	}
}

map<long long, int> tr;

int getPos(long long pos) {
	if (tr.count(pos)) {
		return tr[pos];
	} else {
		return s[pos % n];
	}
}

Matrix getNormal(long long l, long long r) {
	Matrix ret;
	if (r - l >= n) {
		long long k = (r - l) / n, re = (r - l) % n;
		Matrix A = getMa(0, 2 * n - 1, l % n, l % n + n - 1);
		ret = pow(A, k);
		if (re)  {
			ret = ret * getMa(0, 2 * n - 1, r % n + n - re, r % n + n - 1);
		}
	} else {
		if (l % n < r % n) {
			ret = getMa(0, 2 * n - 1, l % n, r % n - 1);
		} else {
			ret = getMa(0, 2 * n - 1, l % n, r % n + n - 1);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> p;
	if (p == 1) {
		cout << 0 << endl;
		return 0;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		s[i + n] = s[i];
	}
	s[n * 2] = s[0];
	init(0, 2 * n - 1);
	
	cin >> m;

	for (int i = 0; i < m; ++i) {
		long long pos;
		int val;
		cin >> pos >> val;
		tr[pos] = val;
	}

	vector<pair<long long, Matrix> > abnormal;
	for (map<long long, int>::iterator it = tr.begin(); it != tr.end(); ++it) {
		if (!(abnormal.size() && abnormal.back().first == it->first - 1)) {
			if (it->first - 1 < k - 1) {
				abnormal.push_back(make_pair(it->first - 1, fibo(getPos(it->first - 1), it->second)));
			}
		}
		if (it->first < k - 1) {
			abnormal.push_back(make_pair(it->first, fibo(it->second, getPos(it->first + 1))));
		}
	}
	if (k) {
		abnormal.push_back(make_pair(k - 1, fibo(getPos(k - 1), getPos(k))));
	}
	Matrix cur(1);
	for (int i = 0; i < (int)abnormal.size(); ++i) {
		long long last = i ? abnormal[i - 1].first + 1 : 0ll;
		if (abnormal[i].first > last) {
			cur = cur * getNormal(last, abnormal[i].first);
		}
		cur = cur * abnormal[i].second;
	}
	cout << cur[1][0] << endl;
	/*
	int f0 = 0, f1 = 1;
	for (int i = 0; i < k; ++i) {
		int nf1 = ((long long)f0 * getPos(i) + (long long)f1 * getPos(i + 1)) % p;
		f0 = f1, f1 = nf1;	
	}
	cout << f0 << endl;
	*/
	return 0;
}