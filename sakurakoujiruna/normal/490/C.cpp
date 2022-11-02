#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
int suf[N];

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int a, b;
	cin >> a >> b;

	for(int i = n - 1, p = 1 % b; i >= 0; i --, p = p * 10 % b)
		suf[i] = (suf[i + 1] + p * (s[i] - '0')) % b;

	bool flag = false;
	int pre = (s[0] - '0') % a;
	for(int i = 1; i < n; i ++)
	{
		if(!pre && !suf[i] && s[i] != '0')
		{
			flag = true;
			cout << "YES\n";
			cout << s.substr(0, i) << '\n';
			cout << s.substr(i, n) << '\n';
			break;
		}
		pre = (pre * 10 + s[i] - '0') % a;
	}
	if(!flag)
		cout << "NO\n";
	return 0;
}