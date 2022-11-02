#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(string s, int k)
{
	ll n = s.size();
	s = '\0' + s;
	if(k == 0)
		return n * (n + 1) / 2;
	ll ret = 0;
	queue <int> q;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == '1')
			q.push(i);
		while(q.size() > k)
			q.pop();
		if(q.size() == k)
			ret += q.front();
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int k;
	cin >> k;
	string s;
	cin >> s;
	cout << solve(s, k) - solve(s, k + 1) << '\n';
	return 0;
}