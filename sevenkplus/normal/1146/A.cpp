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
	int n = s.length();
	int S = 0;
	for (int i = 0; i < n; i ++)
		if (s[i] == 'a') S++;
	S += min(S-1, n-S);
	cout << S << endl;
	return 0;
}