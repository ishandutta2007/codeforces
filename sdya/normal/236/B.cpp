#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct State {
	int x, y, z, index;
	State(int x, int y, int z, int index) : x(x), y(y), z(z), index(index) {
	}
	bool operator < (const State &other) const {
		return make_pair(make_pair(x, y), make_pair(z, index)) <
			make_pair(make_pair(other.x, other.y), make_pair(other.z, other.index));
	}
};

//map < State, int > M;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

const int maxP = 310;
const int maxN = 2100;
vector < int > primes;

int d[maxP][maxN];
int pw[maxP][maxP];

int start[maxN];

unordered_map < int, int > M[maxP][maxN];
int newV[14][maxP][maxN];

int calc(int x, int y, int z, int index) {
	if (x > y) {
		swap(x, y);
	}
	if (x > z) {
		swap(x, z);
	}
	if (y > z) {
		swap(y, z);
	}
	if (M[index][x].count(y * 2101 + z)) {
		return M[index][x][y * 2101 + z];
	}
	int res = 1;
	for (int i = min(index - 1, start[z]); i >= 0; --i) {
		for (int a = 0; a <= d[i][x]; ++a) {
			for (int b = 0; b <= d[i][y]; ++b) {
				for (int c = 0; c <= d[i][z]; ++c) {
					if (a + b + c == 0) {
						continue;
					}
					res += calc(newV[a][i][x], newV[b][i][y], newV[c][i][z], i) * (a + b + c + 1);
				}
			}
		}
	}
	return M[index][x][y * 2101 + z] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//memset(c, -1, sizeof(c));

	for (int i = 2; i <= 2000; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}

	for (int t = 0; t < primes.size(); ++t) {
		int p = primes[t];
		for (int i = 1; i <= 2000; ++i) {
			int cnt = 0, q = 1;
			while (q * p <= i) {
				++cnt;
				q *= p;
			}
			d[t][i] = cnt;
		}
		pw[t][0] = 1;
		for (int i = 1; i < maxP; ++i) {
			pw[t][i] = pw[t][i - 1] * p;
		}
	}
	for (int i = 1; i <= 2000; ++i) {
		int pos = upper_bound(primes.begin(), primes.end(), i) - primes.begin();
		start[i] = pos - 1;
	}

	for (int i = 1; i <= 2000; ++i) {
		for (int j = 0; j < primes.size(); ++j) {
			for (int k = 0; k < 14; ++k) {
				newV[k][j][i] = i / pw[j][k];
			}
		}
	}

	int a, b, c;
	cin >> a >> b >> c;
	unsigned int res = calc(a, b, c, primes.size());
	//cerr << M.size() << endl;
	res %= (1 << 30);
	cout << res << endl;
	cerr << clock() << endl;

	return 0;
}