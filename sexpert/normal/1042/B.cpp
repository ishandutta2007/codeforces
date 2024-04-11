#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> mp;
	for(int i = 0; i < n; i++)
	{
		int a;
		string s;
		cin >> a >> s;
		sort(s.begin(), s.end());
		//cout << s << endl;
		if(mp[s]) mp[s] = min(a, mp[s]);
		else mp[s] = a;
	}
	int ans = 100000000;
	string peeps[7] = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
	for(int i = 0; i < (2 << 7); i++)
	{
		bool can = true;
		set<char> st;
		for(int j = 0; j < 7; j++)
		{
			if((1 << j) & i)
			{
				for(char c : peeps[j]) st.insert(c);
				if(mp[peeps[j]] == 0)
				{
					can = false;
					break;
				}
			} 
		}
		if(!st.count('A') || !st.count('B') || !st.count('C')) continue;
		if(!can) continue;
		int x = 0;
		for(int j = 0; j < 7; j++)
		{
			if((1 << j) & i) x += mp[peeps[j]];
		}
		ans = min(ans, x);
	}
	if(ans == 100000000) cout << -1 << endl;
	else cout << ans << endl;
}