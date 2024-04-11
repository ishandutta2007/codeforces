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

const int maxN = 1100000;
const long long P = 1000000007LL;
long long n, l, k;
int a[maxN];

int b[maxN], c[maxN];

vector < vector < long long > > dp;
vector < vector < long long > > cp;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> l >> k;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	long long u = l / n;
	long long v = l % n;

	vector < int > p;
	for (int i = 0; i < n; ++i) {
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
		++b[a[i]];
		if (i < v) {
			++c[a[i]];
		}
	}

	dp.assign(n + 1, vector < long long > (k + 1, 0));
	cp.assign(n + 1, vector < long long > (k + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (i + 1 <= n) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % P;
				cp[i + 1][j] = (cp[i + 1][j] + cp[i][j]) % P;
			}
			if (j + 1 <= k) {
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * (long long)(b[i])) % P;
				cp[i][j + 1] = (cp[i][j + 1] + dp[i][j] * (long long)(c[i])) % P;
			}
		}
	}

	long long res = 0;
	for (long long i = 1; i <= k; ++i) {
		if (i <= u) {
			long long cnt = (u - i + 1LL) % P;
			res = (res + cnt * dp[n][i]) % P;
		}
		if (i <= u + 1LL) {
			res = (res + cp[n][i]) % P;
		}
	}

	res %= P;
	cout << res << endl;


	return 0;
}