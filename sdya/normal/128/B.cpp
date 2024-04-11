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

string s;
int n, k;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s;
	cin >> k;
	n = s.size();
	long long t = (long long)(n) * (long long)(n + 1) / 2LL;
	if (t < (long long)(k)) {
		cout << "No such line." << endl;
		return 0;
	}

	multiset < pair < string, int > > S;
	for (int i = 0; i < n; ++i) {
		S.insert(make_pair(s.substr(i, 1), i));
	}

	pair < string, int > current;
	for (int i = 0; i < k; ++i) {
		current = *S.begin();
		S.erase(S.begin());
		if (current.second + current.first.size() < n) {
			S.insert(make_pair(current.first + s[current.second + current.first.size()], current.second));
		}
	}

	cout << current.first << endl;

	return 0;
}