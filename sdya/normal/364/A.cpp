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

const int maxN = 5000;
const int maxL = 500000;
int a;
char s[maxN];
int sum[maxN];

int cnt[maxL];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &a);
	scanf("%s", &s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		sum[i] = s[i] - '0';
		if (i > 0) {
			sum[i] += sum[i - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int t = sum[j] - (i == 0 ? 0 : sum[i - 1]);
			++cnt[t];
		}
	}

	long long res = 0;
	for (int i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			int j = a / i;
			long long value = 0;
			if (i < maxL && j < maxL) {
				value = (long long)(cnt[i]) * (long long)(cnt[j]);
			}
			if (i != j) {
				value *= 2LL;
			}
			res += value;
		}
	}

	if (a == 0) {
		for (int j = 1; j < maxL; ++j) {
			res += 2LL * (long long)(cnt[j]) * (long long)(cnt[0]);
		}
		res += (long long)(cnt[0]) * (long long)(cnt[0]);
	}

	cout << res << endl;
	return 0;
}