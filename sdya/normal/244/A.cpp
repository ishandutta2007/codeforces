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

	int n, k;
	cin >> n >> k;
	set < int > s;
	for (int i = 1; i <= n * k; ++i) {
		s.insert(i);
	}
	vector < vector < int > > res(k, vector < int > (n, 0));
	for (int i = 0; i < k; ++i) {
		cin >> res[i][0];
		s.erase(res[i][0]);
	}
	for (int i = 0; i < k; ++i) {
		cout << res[i][0];
		for (int j = 1; j < n; ++j) {
			cout << " " << *s.begin();
			s.erase(s.begin());
		}
		cout << endl;
	}

	return 0;
}