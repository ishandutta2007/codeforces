#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	cin >> S;
	long long ans = 0;
	for (char c = 'a'; c <= 'z'; ++c) {
		long long occ = 0;
		for (char d: S) {
			if (d == c) ++occ;
		}
		ans = max(ans, occ);
	}
	for (char c = 'a'; c <= 'z'; ++c) {
		for (char d = 'a'; d <= 'z'; ++d) {
			long long occ = 0, occ2 = 0;
			for (char e: S) {
				if (e == d) occ2 += occ;
				if (e == c) ++occ;
			}
			ans = max(ans, occ2);
		}
	}
	cout << ans;
	return 0;
}