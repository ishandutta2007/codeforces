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

const int maxN = 2000000;
const int maxD = 25;
bool used[maxN];

int n, a[maxN];
vector < int > bits[maxD];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 0; j < maxD; ++j) {
			if (a[i] & (1 << j)) {
				bits[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int value = a[i];
		int pos = i;
		used[value] = true;
		while (true) {
			int npos = n + 1;
			for (int j = 0; j < maxD; ++j) {
				if (value & (1 << j)) {
					continue;
				}
				int index = upper_bound(bits[j].begin(), bits[j].end(), pos) - bits[j].begin();
				if (index != bits[j].size()) {
					npos = min(npos, bits[j][index]);
				}
			}
			if (npos == n + 1) {
				break;
			}
			value |= a[npos];
			used[value] = true;
			pos = npos;
		}
	}

	printf("%d\n", (int)(count(used, used + maxN, true)));

	return 0;
}