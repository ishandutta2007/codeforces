#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string toCheck = "aeiou13579";
	string s; cin >> s;
	int ans = 0;
	for (char c : s) {
		for (char mightBe : toCheck) {
			if (c == mightBe) {
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}