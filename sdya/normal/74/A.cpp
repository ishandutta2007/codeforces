#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector < pair < int, string > > res;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int score = 0;
		int x, y;
		cin >> x >> y;
		score += 100 * x - 50 * y;
		for (int j = 0; j < 5; ++j) {
			int p;
			cin >> p;
			score += p;
		}
		res.push_back(make_pair(score, s));
	}
	sort(res.rbegin(), res.rend());
	cout << res[0].second << endl;

	return 0;
}