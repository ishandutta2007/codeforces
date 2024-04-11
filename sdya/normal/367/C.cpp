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

int getN(int k) {
	if (k == 1) {
		return 1;
	}
	if (k == 2) {
		return 2;
	}
	if (k == 3) {
		return 4;
	}

	int res = 1000000000;
	{
		int add = (k - 3) % 2;
		add += (k - 1) * ((k - 1) % 2);
		res = min(res, k * (k - 1) / 2 + (add + 1) / 2);
	}
	{
		int add = 2 * ((k - 2) % 2);
		add += (k - 2) * ((k - 1) % 2);
		res = min(res, k * (k - 1) / 2 + (add + 1) / 2);
	}
	return res + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector < int > w;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		w.push_back(v);
	}
	sort(w.rbegin(), w.rend());
	long long score = 0;
	for (int i = 0; i < m; ++i) {
		if (getN(i + 1) > n) {
			break;
		}
		score += w[i];
	}
	cout << score << endl;

	return 0;
}