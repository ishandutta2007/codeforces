#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

set<char> A;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < (int) s.length(); i ++) {
		for (char c = 'a'; c < s[i]; c++)
			if (A.find(c) == A.end()) {
				puts ("NO");
				return 0;
			}
		A.insert(s[i]);
	}
	puts ("YES");
	return 0;
}