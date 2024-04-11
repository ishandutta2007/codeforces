#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

int dp[30][30];
int next[30][30];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			dp[i][j] = next[i][j] = -100000000;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		char beg = s[0], end = s[s.length()-1];
		int b = beg - 'a', e = end - 'a';
		next[b][e] = max (next[b][e], (int) s.length());
		for (int j = 0; j < 26; j++)
			next[j][e] = max (next[j][e], dp[j][b] + (int) s.length());
		for (int j = 0; j < 30; j++)
			for (int k = 0; k < 30; k++)
				dp[j][k] = next[j][k];
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max (ans, dp[i][i]);
	cout << ans << "\n";
	return 0;
}