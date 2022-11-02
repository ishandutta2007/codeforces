#include <bits/stdc++.h>
using namespace std;

string ntos(int n)
{
	n --;
	int l = 1, mul = 26;
	while(mul <= n)
	{
		l ++;
		n -= mul;
		mul *= 26;
	}
	string ret = "";
	for(int i = 0; i < l; i ++, n /= 26)
		ret += (char)(n % 26 + 'A');
	reverse(ret.begin(), ret.end());
	return ret;
}
int ston(string s)
{
	int ret = 0;
	for(auto c : s)
		ret = ret * 26 + (c - 'A');
	for(int i = 1, mul = 26; i < s.size(); i ++, mul *= 26)
		ret += mul;
	return ret + 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int T; cin >> T;
	while(T --)
	{
		string s;
		cin >> s;
		int n = s.size();
		int cpos = -1;
		for(int i = 0; i < n; i ++)
			if(s[i] == 'C')
				cpos = i;
		if(cpos != -1 && s[0] == 'R' && isdigit(s[1]))
		{
			string s1 = s.substr(1, cpos - 1);
			string s2 = s.substr(cpos + 1, n);
			cout << ntos(stoi(s2)) << s1 << '\n';
		}
		else
		{
			int split = -1;
			for(int i = 0; i < n; i ++)
				if(isdigit(s[i]))
				{
					split = i;
					break;
				}
			string s1 = s.substr(0, split);
			string s2 = s.substr(split, n);
			cout << 'R' << s2 << 'C' << ston(s1) << '\n';
		}
	}
	return 0;
}