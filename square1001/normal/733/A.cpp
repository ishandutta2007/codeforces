#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
string s;
int main() {
	cin >> s;
	vector<int> v = { -1 };
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') v.push_back(i);
	}
	v.push_back(s.size());
	int ret = 0;
	for (int i = 1; i < v.size(); i++) ret = max(ret, v[i] - v[i - 1]);
	cout << ret << endl;
	return 0;
}