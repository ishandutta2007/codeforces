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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int index = find(s.begin(), s.end(), 'e') - s.begin();
	int b;
	sscanf(s.substr(index + 1).c_str(), "%d", &b);

	string t = s.substr(0, index);
	index = find(t.begin(), t.end(), '.') - t.begin();
	for (int i = 0; i < b; ++i) {
		if (index + 1 >= t.size()) {
			t += '0';
		}
		swap(t[index], t[index + 1]);
		++index;
	}

	while (t.back() == '0') {
		t.pop_back();
	}

	if (t.back() == '.') {
		t.pop_back();
	}

	cout << t << endl;

	return 0;
}