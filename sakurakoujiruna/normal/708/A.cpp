#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);

	string s;
	cin >> s;
	bool f0 = false, f1 = false;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] != 'a')
		{
			if(!f0)
			{
				f0 = true;
				s[i] = (char)(s[i] - 1);
			}
			else if(!f1)
				s[i] = (char)(s[i] - 1);
		}
		else if(!f1 && f0)
			f1 = true;
	}

	if(!f0)
		s[s.size() - 1] = 'z';
	cout << s << '\n';

	return 0;
}