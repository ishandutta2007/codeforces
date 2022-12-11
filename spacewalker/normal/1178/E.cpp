#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000010;

char str[NMAX];
vector<char> ans;

void buildAnswer(int i, int j) {
	if (j - i < 0) return;
	else if (j - i <= 2) {
		ans.push_back(str[i]);
		return;
	} else {
		vector<int> occs(3, 0);
		occs[str[i] - 'a']++;
		occs[str[i+1] - 'a']++;
		occs[str[j] - 'a']++;
		occs[str[j-1] - 'a']++;
		for (char toAdd = 'a'; toAdd <= 'c'; ++toAdd) {
			if (occs[toAdd - 'a'] >= 2) {
				ans.push_back(toAdd);
				buildAnswer(i + 2, j - 2);
				ans.push_back(toAdd);
				return;
			}
		}
		return;
	}
}

int main() {
	scanf("%s", str);
	int n = strlen(str);
	buildAnswer(0, n - 1);
	for (char c : ans) printf("%c", c);
	printf("\n");
	return 0;
}