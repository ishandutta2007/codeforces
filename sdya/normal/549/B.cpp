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

const int maxN = 110;
string s[maxN];
int a[maxN];
int n;

vector < int > remove(vector < int > a, int index) {
	vector < int > b;
	for (int i = 0; i < a.size(); ++i) {
		if (i != index) {
			b.push_back(a[i]);
		}
	}
	return b;
}

vector < int > solve(vector < int > allowed) {
	if (allowed.size() == 1) {
		if (a[allowed[0]] != 0) {
			return vector < int > ();
		}
		return vector < int > (1, allowed[0]);
	}

	int n = allowed.size();
	int hasMax = -1;
	int hasMin = -1;
	for (int i = 0; i < n; ++i) {
		if (a[allowed[i]] == n) {
			hasMax = i;
		}
		if (a[allowed[i]] == 0) {
			hasMin = i; 
		}
	}
	if (hasMax != -1) {
		return solve(remove(allowed, hasMax));
	}

	if (hasMin != -1) {
		for (int j = 0; j < n; ++j) {
			if (s[allowed[hasMin]][allowed[j]] == '1') {
				--a[allowed[j]];
			}
		}
		vector < int > res = solve(remove(allowed, hasMin));
		res.push_back(allowed[hasMin]);
		sort(res.begin(), res.end());
		return res;
	}

	return vector < int > ();
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector < int > allowed;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		allowed.push_back(i);
	}

	vector < int > res = solve(allowed);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");

	return 0;
}