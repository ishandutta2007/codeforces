#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define mp make_pair

int main()
{
	int pos[26], mx[26];
	for (int i = 0; i < 26; ++i)
		mx[i] = pos[i] = -1;
	int n;
	string s;
	cin >> s;
	n = s.length();
	int ans = 1e9;
	for (int i = 0; i < n; ++i)
	{
		mx[s[i] - 'a'] = max(mx[s[i] - 'a'], i - pos[s[i] - 'a']);
		pos[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i)
		mx[i] = max(mx[i], n - pos[i]);
	for (int i = 0; i < 26; ++i)
		ans = min(ans, mx[i]);
	cout << ans << endl;
}