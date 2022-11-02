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
	string s;
	cin >> s;
	int b = count(s.begin(), s.end(), 'B');
	int g = count(s.begin(), s.end(), 'G');
	int r = count(s.begin(), s.end(), 'R');
	if (b > 0 && g > 0 && r > 0) {
		cout << "BGR" << endl;
		return 0;
	}
	if (b == n) {
		cout << "B" << endl;
		return 0;
	}
	if (g == n) {
		cout << "G" << endl;
		return 0;
	}
	if (r == n) {
		cout << "R" << endl;
		return 0;
	}
	if ((b > 1 && g > 1) || (b > 1 && r > 1) || (g > 1 && r > 1)) {
		cout << "BGR" << endl;
		return 0;
	}
	if (b > 1) {
		cout << "GR" << endl;
		return 0;
	}
	if (g > 1) {
		cout << "BR" << endl;
		return 0;
	}
	if (r > 1) {
		cout << "BG" << endl;
		return 0;
	}

	if (b == 0) {
		cout << "B" << endl;
		return 0;
	}
	if (g == 0) {
		cout << "G" << endl;
		return 0;
	}
	if (r == 0) {
		cout << "R" << endl;
		return 0;
	}
	return 0;
}