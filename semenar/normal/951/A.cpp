#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

long long gcd(long long a, long long b) {
	return (a < b) ? gcd(b, a) : (b == 0 ? a : gcd(b, a % b));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string zebra;
	cin >> zebra;

	int max_ans = zebra.size();

	int ans = 0;
	int cur_ans = 0;

	for (int i = 0; i < 2 * zebra.size(); i++) {
		if (cur_ans == 0) cur_ans = 1;
		else {
			if (zebra[i % max_ans] == zebra[(i - 1) % max_ans]) cur_ans = 1;
			else cur_ans++;
		}
		if (cur_ans > ans) ans = cur_ans;
	}

	cout << min(max_ans, ans) << endl;

	return 0;
}