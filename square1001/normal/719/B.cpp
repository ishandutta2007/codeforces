#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(string s1, string s2) {
	// s1 -> s2
	int p1 = 0, p2 = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == 'b' && s2[i] == 'r') p1++;
		if (s1[i] == 'r' && s2[i] == 'b') p2++;
	}
	return max(p1, p2);
}
int n;  string s;
int main() {
	cin >> n >> s;
	string t1, t2;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			t1 += 'b';
			t2 += 'r';
		}
		else {
			t1 += 'r';
			t2 += 'b';
		}
	}
	cout << min(solve(s, t1), solve(s, t2)) << endl;
	return 0;
}