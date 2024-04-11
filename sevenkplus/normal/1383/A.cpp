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

int a[20][20];

int main() {
	int _;
	cin >> _;
	while (_--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		memset(a, 0, sizeof a);
		bool F = true;
		for (int i = 0; i < n; i ++)
			if (s[i] > t[i]) F = false;
		if (!F) {
			puts ("-1");
			continue;
		}
		for (int i = 0; i < n; i ++)
			a[s[i]-'a'][t[i]-'a']++;
		int S = 0;
		for (int i = 0; i < 20; i ++) {
			int bj = -1;
			for (int j = i+1; j < 20; j ++) if (a[i][j]) {
				bj = j; break;
			}
			if (bj == -1) continue;
			S++;
			for (int k = 0; k < 20; k ++) if (k != i) {
				a[bj][k] += a[i][k];
			}
		}
		cout << S << endl;
	}
	return 0;
}