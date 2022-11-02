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
		cin >> a[i].second >> a[i].first;
	}
	sort(a.rbegin(), a.rend());

	int res = 0;
	int cnt = 1;
	for (int i = 0; i < a.size(); ++i) {
		if (cnt == 0) {
			break;
		}
		res += a[i].second;
		--cnt;
		cnt += a[i].first;
	}
	cout << res << endl;


	return 0;
}