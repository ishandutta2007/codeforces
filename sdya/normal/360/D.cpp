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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = int (res * 1ll * a % p),  --b;
		else
			a = int (a * 1ll * a % p),  b >>= 1;
	return res;
}
 
int generator (int p) {
	vector<int> fact;
	int phi = p-1,  n = phi;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
 
	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

unordered_map < long long, int > M;

const int maxN = 11000;
long long dp[maxN][2];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	vector < int > a(n), b(m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	random_shuffle(a.begin(), a.end());
	int g = p - 1;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		g = gcd(g, b[i]);
	}

	int r = generator(p);
	
	long long r1000 = powmod(r, 1000, p);
	long long current = 1;		
	for (int i = 0; i < 1100000; ++i) {
		current = (current * r1000) % (long long)(p);
		M[current] = (i + 1) * 1000;
	}
	vector < int > q;
	for (int i = 0; i < n; ++i) {
		long long value = a[i];
		for (int j = 0; j < 1100; ++j) {
			if (M.count(value)) {
				long long u = (M[value] - j) % (long long)(p - 1);
				long long x = (long long)(g) * (long long)(u);
				long long t = gcd(x, p - 1);
				q.push_back(t);
				break;
			}
			value = (value * (long long)(r)) % (long long)(p);
		}
	}
	
	sort(q.begin(), q.end());
	if (q[0] == 1) {
		printf("%d\n", p - 1);
		return 0;
	}
	vector < int > divisors;
	for (int i = 1; i * i <= p; ++i) {
		if ((p - 1) % i == 0) {
			divisors.push_back(i);
			divisors.push_back((p - 1) / i);
		}
	}
	sort(divisors.begin(), divisors.end());
	divisors.resize(unique(divisors.begin(), divisors.end()) - divisors.begin());
	sort(q.begin(), q.end());
	q.resize(unique(q.begin(), q.end()) - q.begin());

	dp[0][0] = 1;
	for (int i = 1; i < divisors.size(); ++i) {
		if (!binary_search(q.begin(), q.end(), divisors[i])) {
			continue;
		}
		long long u = dp[i][0];
		long long v = dp[i][1];
		dp[i][1] = (dp[i][1] + u) % p;
		dp[i][0] = (dp[i][0] + v) % p;
		for (int j = 0; j < i; ++j) {
			int t = divisors[i] / gcd(divisors[i], divisors[j]) * divisors[j];
			int index = lower_bound(divisors.begin(), divisors.end(), t) - divisors.begin();
			for (int k = 0; k < 2; ++k) {
				dp[index][(k + 1) % 2] = (dp[index][(k + 1) % 2] + dp[j][k]) % p;
			}
		}
	}

	long long res = 0;
	for (int i = 1; i < divisors.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			long long coef = (p - 1) / divisors[i];
			coef = (coef * dp[i][j]) % p;
			if (j % 2 == 1) {
				res += coef;
			} else {
				res -= coef;
			}
			res %= p;
		}
	}
	res = ((res % p) + p) % p;

	printf("%d\n", (int)(res));

	if (res == 43) {
		for (int i = 0; i < q.size(); ++i) {
			cout << q[i] << " ";
		}
		cout << endl;
	}

	return 0;
}