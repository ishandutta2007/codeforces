#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000000;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1000000000000000000;

char str[6000];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	map<char, int> charSet;
	for (int i = 0; str[i]; ++i) charSet[str[i]]++;
	vector<char> strVec(n);
	for (int i = 0; i < n; ++i) strVec[i] = str[i];
	if (charSet.size() == 1) {
		printf("Impossible\n");
		return 0;
	} else if (charSet.size() == 2 && n % 2 == 1) {
		vector<int> counts;
		for (auto x : charSet) counts.push_back(x.second);
		sort(begin(counts), end(counts));
		if (counts[0] == 1) {
			printf("Impossible\n");
			return 0;
		}
	}
	for (int i = 1; i < n; ++i) {
		vector<char> newString(n);
		int ptr = 0;
		for (int j = i; j < n; ++j) {
			newString[ptr++] = str[j];
		}
		for (int j = 0; j < i; ++j) {
			newString[ptr++] = str[j];
		}
		bool isPalindrome = true;
		for (int j = 0; j < n; ++j) {
			if (newString[j] != newString[n-1-j]) {
				isPalindrome = false;
			}
		}
		if (isPalindrome && newString != strVec) {
			// printf("IPT %d\n", i);
			// for (char c : newString) printf("%c", c);
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
	return 0;
}