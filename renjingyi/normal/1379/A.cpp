#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
bool gao(const string &s, const int &pos)
{
	if(pos + 7 > s.size())
		return 0;
	if(s[pos] != 'a' && s[pos] != '?')
		return 0;
	if(s[pos + 1] != 'b' && s[pos + 1] != '?')
		return 0;
	if(s[pos + 2] != 'a' && s[pos + 2] != '?')
		return 0;
	if(s[pos + 3] != 'c' && s[pos + 3] != '?')
		return 0;
	if(s[pos + 4] != 'a' && s[pos + 4] != '?')
		return 0;
	if(s[pos + 5] != 'b' && s[pos + 5] != '?')
		return 0;
	if(s[pos + 6] != 'a' && s[pos + 6] != '?')
		return 0;
	return 1;
}
bool check(const string &s)
{
	int cnt = 0;
	for(int i = 0; i < s.size(); i ++)
		if(i + 7 <= s.size() && s.substr(i, 7) == "abacaba")
			cnt ++;
	return cnt == 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		string s;
		cin >> n >> s;
		bool get = 0;
		for(int i = 0; i < s.size(); i ++)
			if(gao(s, i))
			{
				string t = s;
				t[i] = 'a';
				t[i + 1] = 'b';
				t[i + 2] = 'a';
				t[i + 3] = 'c';
				t[i + 4] = 'a';
				t[i + 5] = 'b';
				t[i + 6] = 'a';
				for(int j = 0; j < t.size(); j ++)
					if(t[j] == '?')
						t[j] = 'z';
				if(check(t))
				{
					cout << "Yes" << endl << t << endl;
					get = 1;
					break;
				}
			}
		if(!get)
			cout << "No" << endl;
	}
	
	return 0;
}