#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int n, x;
int t[maxN], h[maxN], m[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> h[i] >> m[i];
	}

	int res = 0;
	for (int start = 0; start < 2; ++start) {
		int s = x;
		vector < bool > used(n, false);
		int current = start;

		int score = 0;
		while (true) {
			int best = -1, index = -1;
			for (int i = 0; i < n; ++i) {
				if (!used[i] && t[i] == current && h[i] <= s && s + m[i] > best) {
					best = s + m[i];
					index = i;
				}
			}
			if (index == -1) {
				break;
			}
			++score;
			used[index] = true;
			s += m[index];
			current = 1 - current;
		}
		res = max(res, score);
	}
	cout << res << endl;

	return 0;
}