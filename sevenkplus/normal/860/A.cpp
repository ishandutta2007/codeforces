#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

string s;
int n;

int main() {
	cin >> s;
	n = (int) s.length();
	int t = 0;
	char c = 0;
	bool pure = true;
	for (int i = 0; i < n; i ++) {
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
			t ++;
			if (t == 1) c = s[i];
			if (s[i] != c) pure = false;
		}
		else {
			t = 0;
			pure = true;
		}
		if (!pure && t >= 3) {
			putchar(' ');
			putchar(s[i]);
			t = 1;
			c = s[i];
			pure = true;
		} else {
			putchar(s[i]);
		}
	}
	puts ("");
	return 0;
}