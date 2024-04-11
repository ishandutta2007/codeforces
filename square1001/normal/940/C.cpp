#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s; int N, K;
int main() {
	cin >> N >> K >> s;
	if (N < K) {
		char c = *min_element(s.begin(), s.end());
		cout << s + string(K - N, c) << "\n";
	}
	else {
		string res = s.substr(0, K);
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		for (int i = K - 1; i >= 0; i--) {
			int ptr = s.find(res[i]);
			if (ptr + 1 != s.size()) {
				res[i] = s[ptr + 1];
				break;
			}
			else res[i] = s[0];
		}
		cout << res << "\n";
	}
	return 0;
}