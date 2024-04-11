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

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

vector < int > d[5000];
vector < int > a;

int rec(int maxSteps, int index, int value, int bound, const set < int > &used) {
	if (value > bound) {
		return -1;
	}
	if (maxSteps == index) {
		if (used.count(value) == 0) {
			return value;
		}
		return -1;
	}

	int res = -1;
	for (int i = 0; i < 5; ++i) {
		int buf = rec(maxSteps, index + 1, value, bound, used);
		if (buf != -1) {
			return buf;
		}
		value *= a[index];
		if (value > bound) {
			break;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	
	for (int i = 2; i <= 20000; ++i) {
		if (isPrime(i)) {
			a.push_back(i);
		}
	}

	while (true) {
		for (int steps = 1; steps <= 6; ++steps) {
			//cerr << steps << endl;
			for (int i = 0; i < steps; ++i) {
				d[i] = vector < int > (n, 0);
				for (int j = 0; j < (n + 1) / 2; ++j) {
					d[i][j] = 1;
				}
				random_shuffle(d[i].begin(), d[i].end());
			}

			set < int > used;
			int bound = 2 * n * n;
			vector < int > res;
			for (int i = 0; i < n; ++i) {
				int value = 1;
				for (int j = 0; j < steps; ++j) {
					if (d[j][i]) {
						value *= a[j];
					}
				}
				if (value > bound) {
					break;
				}
				if (used.count(value) == 0) {
					used.insert(value);
					res.push_back(value);
					continue;
				}
				int score = rec(steps, 0, value, bound, used);
				if (score == -1) {
					break;
				}
				used.insert(score);
				res.push_back(score);
			}
			if (res.size() == n) {
				sort(res.begin(), res.end());
				for (int i = 0; i < n; ++i) {
					printf("%d ", res[i]);
				}
				/*for (int i = 0; i < steps; ++i) {
					int cnt = 0;
					for (int j = 0; j < n; ++j) {
						if (res[j] % a[i] == 0) {
							++cnt;
						}
					}
					cerr << cnt << endl;
				}*/
				printf("\n");
				return 0;
			}
		}
	}

	

	return 0;
}