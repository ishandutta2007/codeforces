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

int main() {
	string s;
	cin >> s;
	int n = (int) s.length();
	int S = 0;
	for (int i = 0; i < n; i ++)
		for (int j = i+1; j <= n; j ++) {
			string t = s.substr(i, j-i);
			string u = t;
			reverse(u.begin(), u.end());
			if (t != u) S = max(S, j-i);
		}
	cout << S << endl;
	return 0;
}