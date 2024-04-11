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

const int maxN = 5100;
int n;
int a[maxN], b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}

	vector < pair < int, int > > p;
	for (int i = 0; i < n; ++i) {
		p.push_back(make_pair(a[i], b[i]));
	}
	sort(p.begin(), p.end());

	int t = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i].second >= t) {
			t = p[i].second;
		} else {
			t = p[i].first;
		}
	}

	cout << t << endl;

	return 0;
}