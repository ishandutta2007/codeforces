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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
char s[maxN];
int n;

vector < pair < int, int > > solve() {
	int start = 0;
	vector < pair < int, int > > res;
	while (start < n) {
		while (start < n && s[start] == '0') {
			++start;
		}
		if (start == n) {
			break;
		}

		int finish = start;
		for (int i = start; i < n; ++i) {
			if (s[i] == '1') {
				finish = i;
			} else {
				break;
			}
		}
		if (start != finish) {
			res.push_back(make_pair(start, -1));
			res.push_back(make_pair(finish + 1, 1));
		} else {
			res.push_back(make_pair(start, 1));
		}

		start = finish + 1;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	n = strlen(s);
	reverse(s, s + n);
	s[n] = '0';
	s[n + 1] = '0';

	vector < pair < int, int > > res;
	int last = 0;
	for (int i = 0; i < n + 1; ++i) {
		if (s[i] == 1 - last + '0') {
			last = s[i + 1] - '0';
			res.push_back(make_pair(i, last == 0 ? 1 : -1));
		}
	}

	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		if (res[i].second < 0) {
			printf("-2^%d\n", res[i].first);
		} else {
			printf("+2^%d\n", res[i].first);
		}
	}

	return 0;
}