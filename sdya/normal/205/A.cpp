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
	vector < pair < int, int > > a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	if (n > 1 && a[0].first == a[1].first) {
		cout << "Still Rozdil";
	} else {
		cout << a[0].second;
	}

	return 0;
}