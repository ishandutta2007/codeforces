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

#define N 1000010
string s;
int n;
int pr[N][3];
int ne[N][3];

int main() {
	cin >> s;
	n = s.size();
	pr[0][0] = pr[0][1] = pr[0][2] = -1;
	pr[0][s[0]-'a'] = 0;
	for (int i = 1; i < n; i ++) {
		pr[i][0] = pr[i-1][0];
		pr[i][1] = pr[i-1][1];
		pr[i][2] = pr[i-1][2];
		pr[i][s[i]-'a'] = i;
	}

	ne[n-1][0] = ne[n-1][1] = ne[n-1][2] = -1;
	ne[n-1][s[n-1]-'a'] = n-1;
	for (int i = n-2; i >= 0; i--) {
		ne[i][0] = ne[i+1][0];
		ne[i][1] = ne[i+1][1];
		ne[i][2] = ne[i+1][2];
		ne[i][s[i]-'a'] = i;
	}
	string S;
	int le = 0, ri = n-1;
	while (le <= ri) {
		int c = -1;
		for (int j = 0; j < 3; j ++) {
			if (ne[le][j] == -1 || pr[ri][j] == -1) continue;
			if (ne[le][j] > pr[ri][j]) continue;
			if (c == -1 || ri - pr[ri][j] + ne[le][j] - le < ri - pr[ri][c] + ne[le][c] - le) {
				c = j;
			}
		}
		if (c == -1) {
			string T = S;
			reverse(T.begin(), T.end());
			S += T;
			break;
		}
		if (ne[le][c] == pr[ri][c]) {
			string T = S;
			reverse(T.begin(), T.end());
			S += (char)('a'+c);
			S += T;
			break;
		}
		S += (char)('a'+c);
		le = ne[le][c] + 1;
		ri = pr[ri][c] - 1;
	}
	cout << S << endl;
	return 0;
}