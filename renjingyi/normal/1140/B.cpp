#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i ++)
	{
		int n;
		string s;
		cin >> n >> s;
		int get1 = n + 1, get2 = n + 1;
		for(int j = 0; j < s.size(); j ++)
			if(s[j] == '>')
			{
				get1 = j;
				break;
			}
		for(int j = (int)s.size() - 1; j >= 0; j --)
			if(s[j] == '<')
			{
				get2 = (int)s.size() - 1 - j;
				break;
			}
		cout << min(get1, get2) << endl;
	}
	
	return 0;
}