#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < pair < pair < int, int >, pair < int, int > > > best;

vector < int > presented;
vector < pair < pair < int, int >, pair < int, int > > > ops;
const int maxSteps = 5;
int n;

bool isPresented(int x) {
	for (int i = 0; i < presented.size(); ++i) {
		if (presented[i] == x) {
			return true;
		}
	}
	return false;
}

void rec() {
	if (presented.back() == n) {
		if (ops.size() < best.size()) {
			best = ops;
			return;
		}
	}
	if (presented.size() >= best.size()) {
		return;
	}

	for (int i = -1; i < (int)(presented.size()); ++i) {
		for (int j = -1; j <= 3; ++j) {
			for (int k = 0; k < presented.size(); ++k) {
				int a = (i == -1 ? 0 : presented[i]);
				int b = (j == -1 ? 0 : ((1 << j) * presented[k]));
				if (a + b <= n && a + b > 0 && !isPresented(a + b)) {
					presented.push_back(a + b);
					ops.push_back(make_pair(make_pair(presented.size() - 1, i), make_pair(j == -1 ? j : (1 << j), k)));
					rec();
					presented.pop_back();
					ops.pop_back();
				}
			}
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < 6; ++i) {
		best.push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));
	}
	presented.push_back(1);
	rec();
	printf("%d\n", best.size());
	for (int i = 0; i < best.size(); ++i) {
		int x = best[i].first.first;
		int y = best[i].first.second;
		int z = best[i].second.first;
		int t = best[i].second.second;
		printf("lea e%cx, [", x + 'a');
		if (y != -1) {
			printf("e%cx + ", y + 'a');
		}
		if (z > 1) {
			printf("%d*", z);
		}
		if (z >= 1) {
			printf("e%cx", t + 'a');
		}
		printf("]\n");
	}

	
	return 0;
}