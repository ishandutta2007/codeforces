#include <bits/stdc++.h>
using namespace std;

const int N = 5011;
int pre[N];

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i ++)
		if(s.substr(i, 4) == "bear")
			pre[i + 1] = 1;
	for(int i = 1; i < N; i ++)
		pre[i] += pre[i - 1];

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i + 3; j <= n; j ++)
			if(pre[j - 3] - pre[i - 1] > 0)
				ans ++;
	cout << ans << '\n';
	return 0;
}