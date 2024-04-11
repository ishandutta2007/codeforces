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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector < pair < int, int > > a;
	string s(n, '0'), t(n, '0');
	for (int i = 0; i < n / 2; ++i) {
		s[i] = t[i] = '1';
	}
	for (int i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		a.push_back(make_pair(u, i + 1));
		a.push_back(make_pair(v, -(i + 1)));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (a[i].second > 0) {
			s[a[i].second - 1] = '1';
		} else {
			t[-a[i].second - 1] = '1';
		}
	}
	puts(s.c_str());
	puts(t.c_str());

	return 0;
}