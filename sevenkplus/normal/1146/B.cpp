#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int a[N];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i ++)
		a[i+1] = a[i] + (s[i] != 'a');
	bool F = true;
	if (a[n] % 2 == 1) F = false;
	if (F) {
		int pos = -1;
		for (int i = n; i >= 0; i--)
			if (a[i] == a[n] - a[i]) {
				pos = i;
				break;
			}
		string s1, s2;
		for (int i = 0; i < pos; i ++)
			if (s[i] != 'a') s1 += s[i];
		for (int i = pos; i < n; i ++) {
			if (s[i] == 'a') F = false;
			else s2 += s[i];
		}
		if (s1 != s2) F = false;
		if (F) cout << s.substr(0, pos) << endl;
	}
	if (!F) puts(":(");
	return 0;
}