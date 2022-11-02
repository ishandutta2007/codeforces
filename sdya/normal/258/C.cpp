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

const int maxN = 110000;
int cnt[maxN];
int n;

vector < int > d[maxN];

const long long P = 1000000007LL;

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 1) {
		b = (b * a) % P;
	}
	return b;
}

long long ways[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}

	for (int i = maxN - 2; i >= 0; --i) {
		cnt[i] += cnt[i + 1];
	}

	for (int i = 1; i < maxN; ++i) {
		for (int j = i; j < maxN; j += i) {
			d[j].push_back(i);
		}
	}

	for (int i = 1; i < maxN; ++i) {
		{
			vector < int > c(d[i].size());
			for (int j = 0; j < d[i].size(); ++j) {
				c[j] = cnt[d[i][j]];
			}
			for (int j = 0; j + 1 < c.size(); ++j) {
				c[j] -= c[j + 1];
			}

			long long res = 1LL;
			for (int j = 0; j < c.size(); ++j) {
				res *= powmod(j + 1, c[j]);
				res %= P;
			}
			ways[i] = res;
		}
		{
			vector < int > c(d[i].size() - 1);
			for (int j = 0; j + 1 < d[i].size(); ++j) {
				c[j] = cnt[d[i][j]];
			}
			for (int j = 0; j + 1 < c.size(); ++j) {
				c[j] -= c[j + 1];
			}

			long long res = 1LL;
			for (int j = 0; j < c.size(); ++j) {
				res *= powmod(j + 1, c[j]);
				res %= P;
			}
			ways[i] -= res;
		}
		ways[i] = ((ways[i] % P) + P) % P;
	}

	long long ans = 0;
	for (int i = 1; i < maxN; ++i) {
		ans += ways[i];
		ans %= P;
	}
	ans = ((ans % P) + P + 1) % P;
	cout << ans << endl;


	return 0;
}