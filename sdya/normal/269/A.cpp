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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	map < int, long long > M;
	set < int > S;
	for (int i = 1; i <= n; ++i) {
		int k, a;
		scanf("%d%d", &k, &a);
		M[k] += a;
		S.insert(k);
	}

	while (true) {
		pair < int, long long > start = *M.begin();
		M.erase(M.begin());
		if (start.second == 1 && M.size() == 0) {
			if (S.count(start.first)) {
				++start.first;
			}
			printf("%d\n", start.first);
			return 0;
		}

		if (start.second > 1) {
			M[start.first + 1] = max(M[start.first + 1], (start.second + 3) / 4);
		}
	}

	return 0;
}