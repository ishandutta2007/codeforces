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

int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector < int > divisors;
	for (int i = 0; i < 4; ++i) {
		cout << p[i] << endl;
		
		string s;
		cin >> s;
		if (s == "yes") {
			divisors.push_back(p[i]);
		}
	}
	
	if (divisors.size() > 1) {
		cout << "composite" << endl;
		return 0;
	}
	if (divisors.size() == 0) {
		cout << "prime" << endl;
		return 0;
	}

	cout << divisors[0] * divisors[0] << endl;
	string s;
	cin >> s;
	if (s == "yes") {
		cout << "composite" << endl;
		return 0;
	}

	for (int i = 4; i < 15; ++i) {
		cout << p[i] << endl;

		string s;
		cin >> s;
		if (s == "yes") {
			cout << "composite" << endl;
			return 0;
		}
	}

	cout << "prime" << endl;
	return 0;
}