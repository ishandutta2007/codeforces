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
	cin >> n;
	pair < int, string > s[3];
	s[0].second = "chest";
	s[1].second = "biceps";
	s[2].second = "back";
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		s[i % 3].first += value;
	}
	sort(s, s + 3);
	cout << s[2].second;


	return 0;
}