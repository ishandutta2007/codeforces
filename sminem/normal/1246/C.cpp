#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ull * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n, m;
string a[2005];
int rt[2005][2005], ct[2005][2005];

mint dp[2][2005][2005], sm[2][2005][2005];

void wrt(int i, int j, int k, mint v) {
	dp[i][j][k] = v;
	sm[i][j][k] = sm[i][j+i][k+(1^i)] + v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			rt[i][j] = rt[i+1][j];
			ct[i][j] = ct[i][j+1];
			if (a[i][j] == 'R')
				rt[i][j]++, ct[i][j]++;
		}
	}

	if (a[n-1][m-1] == 'R') {
		cout << "0\n";
		return 0;
	}

	if (n == 1 && m == 1) {
		cout << "1\n";
		return 0;
	}

	wrt(0, n-1, m-1, 1);
	wrt(1, n-1, m-1, 1);
	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>=0; j--) {
			if (i == n-1 && j == m-1)
				continue;

			int p0 = rt[i+1][j];
			mint v0 = sm[1][i+1][j] - sm[1][n-p0][j];

			int p1 = ct[i][j+1];
			mint v1 = sm[0][i][j+1] - sm[0][i][m-p1];

			// cerr << "info " << i << ' ' << j << ' ' << (int)v0 << ' ' << (int)v1 << '\n';

			wrt(0, i, j, v0);
			wrt(1, i, j, v1);
		}
	}

	cout << (int)(dp[0][0][0] + dp[1][0][0]) << '\n';
}