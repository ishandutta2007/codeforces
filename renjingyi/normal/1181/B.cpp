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
vector<int> add(string s1, string s2)
{
	if(s1.size() < s2.size())
		swap(s1, s2);
	int n = s1.size(), m = s2.size();
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	vector<int> ret;
	ret.resize(n);
	for(int i = 0; i < m; i ++)
		ret[i] = s1[i] - '0' + s2[i] - '0';
	for(int i = m; i < n; i ++)
		ret[i] = s1[i] - '0';
	for(int i = 0; i < n - 1; i ++)
	{
		ret[i + 1] += ret[i] / 10;
		ret[i] %= 10;
	}
	if(ret[n - 1] >= 10)
	{
		ret.push_back(ret[n - 1] / 10);
		ret[n - 1] %= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void print(vector<int> ans)
{
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i];
	cout << endl;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ok1 = 0, ok2 = 0;
	vector<int> ans1, ans2;
	for(int i = n / 2; i >= 1; i --)
		if(s[i] != '0')
		{
			ans1 = add(s.substr(0, i), s.substr(i));
			ok1 = 1;
			break;
		}
	for(int i = (n + 1) / 2; i < n; i ++)
		if(s[i] != '0')
		{
			ans2 = add(s.substr(0, i), s.substr(i));
			ok2 = 1;
			break;
		}
	if(!ok1 && !ok2)
		cout << "boom" << endl;
	else if(!ok1)
		print(ans2);
	else if(!ok2)
		print(ans1);
	else
	{
		if(ans1.size() < ans2.size())
			print(ans1);
		else if(ans1.size() > ans2.size())
			print(ans2);
		else
		{
			bool get = 0;
			for(int i = 0; i < ans1.size(); i ++)
			{
				if(ans1[i] < ans2[i])
				{
					print(ans1);
					get = 1;
					break;
				}
				else if(ans1[i] > ans2[i])
				{
					print(ans2);
					get = 1;
					break;
				}
			}
			if(!get)
				print(ans1);
		}
	}
	
	return 0;
}