#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n, r;
int ans;
vector<int> best;

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &r);

	ans = 1000000000;
	for (int i = 0; i<=r; i++) {

		int a = r;
		int b = i;

		vector<int> divs;
		int sum = 0;
		while (b) {
			int q = a / b;
			if (a > b && a % b == 0) q--;
			divs.push_back(q);
			sum += q;
			a -= q * b;
			swap(a, b);
		}

		if (a != 1) continue;
		if (sum != n) continue;

		int tres = sum - divs.size();
		if (ans > tres) {
			ans = tres;
			best = divs;
		}
	}

	if (ans == 1000000000)
		printf("IMPOSSIBLE\n");
	else {
		printf("%d\n", ans);
		reverse(best.begin(), best.end());
		for (int i = 0; i<best.size(); i++)
			for (int j = 0; j<best[i]; j++)
				printf("%c", (i&1 ? 'B' : 'T'));
		printf("\n");
	}

	return 0;
}