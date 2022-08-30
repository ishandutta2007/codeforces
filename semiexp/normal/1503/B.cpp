#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
vector<pair<int, int>> evens, odds;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i % 2 == j % 2) evens.push_back({i + 1, j + 1});
			else odds.push_back({i + 1, j + 1});
		}
	}

	for (int i = 0; i < N * N; ++i) {
		int a;
		scanf("%d", &a);
		if (a != 1) {
			if (!evens.empty()) {
				pair<int, int> pt = evens.back(); evens.pop_back();
				printf("1 %d %d\n", pt.first, pt.second);
				goto nxt;
			}
		} else if (a != 2) {
			if (!odds.empty()) {
				pair<int, int> pt = odds.back(); odds.pop_back();
				printf("2 %d %d\n", pt.first, pt.second);
				goto nxt;
			}
		}
		if (!evens.empty()) {
			pair<int, int> pt = evens.back(); evens.pop_back();
			printf("%d %d %d\n", a == 1 ? 3 : 1, pt.first, pt.second);
		} else if (!odds.empty()) {
			pair<int, int> pt = odds.back(); odds.pop_back();
			printf("%d %d %d\n", a == 2 ? 3 : 2, pt.first, pt.second);
		}

		nxt:
		fflush(stdout);
		continue;
	}
	return 0;
}