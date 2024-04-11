#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
string s1, s2;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s1 >> s2;
	int a = s1.size(), b = s2.size();
	int x = 0, y = 0;
	for (int i = 0; i < a * b; ++i) {
		int u = i % a, v = i % b;
		if (s1[u] == s2[v]) continue; else
		if (s1[u] == 'R' && s2[v] == 'S') ++x; else
		if (s1[u] == 'S' && s2[v] == 'P') ++x; else
		if (s1[u] == 'P' && s2[v] == 'R') ++x; else ++y;
	}

	int t = n / (a * b);
	x *= t, y *= t;
	for (int i = t * a * b; i < n; ++i) {
		int u = i % a, v = i % b;
		if (s1[u] == s2[v]) continue; else
		if (s1[u] == 'R' && s2[v] == 'S') ++x; else
		if (s1[u] == 'S' && s2[v] == 'P') ++x; else
		if (s1[u] == 'P' && s2[v] == 'R') ++x; else ++y;
	}
	cout << y << " " << x << endl;
	return 0;
}