#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n;
int a[maxN];

int d[3][maxN];
int p[3][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	//n = 100000;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		//a[i] = rand() % 2 + 1;
		d[a[i]][i] = 1;
		if (i > 0) {
			d[1][i] += d[1][i - 1];
			d[2][i] += d[2][i - 1];
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < maxN; ++j) {
			p[i][j] = -1;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 1; j <= 2; ++j) {
			p[j][d[j][i]] = i;
		}
	}

	vector < pair < int, int > > res;

	for (int s = 1; s <= n; ++s) {
		bool good = true;
		int w1 = 0, w2 = 0;
		int i = 0;
		int lastwinner = -1;
		while (i < n) {
			int winsa = (i == 0 ? 0 : d[1][i - 1]);
			int winsb = (i == 0 ? 0 : d[2][i - 1]);

			int posa = p[1][winsa + s];
			int posb = p[2][winsb + s];
			if (posa == -1 && posb == -1) {
				good = false;
				break;
			}
			if (posa == -1) {
				++w2;
				i = posb + 1;
				lastwinner = 2;
			} else if (posb == -1) {
				++w1;
				i = posa + 1;
				lastwinner = 1;
			} else if (posa < posb) {
				++w1;
				i = posa + 1;
				lastwinner = 1;
			} else {
				++w2;
				i = posb + 1;
				lastwinner = 2;
			}
		}

		if (!good) {
			continue;
		}

		if (w1 == w2) {
			continue;
		}
		if (w1 > w2 && lastwinner == 1) {
			res.push_back(make_pair(w1, s));
			continue;
		}
		if (w2 > w1 && lastwinner == 2) {
			res.push_back(make_pair(w2, s));
			continue;
		}
	}

	sort(res.begin(), res.end());

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d\n", res[i].first, res[i].second);
	}


	cerr << clock() << endl;


	return 0;
}