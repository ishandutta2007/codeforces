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
const int maxn = 1e5 + 5;
bool mark[maxn];
char ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	int pos = (int)s.size();
	for(int i = (int)s.size() - 1; i >= 0; i --)
	{
		if(s[i] == '1')
			cnt ++;
		else if(s[i] == '2')
		{
			ans[i + cnt] = '2';
			mark[i + cnt] = 1;
			pos = i + cnt;
		}
	}
	for(int i = pos - 1; i >= pos - cnt; i --)
	{
		ans[i] = '1';
		mark[i] = 1;
	}
	for(int i = 0; i < s.size(); i ++)
		cout << (mark[i] ? ans[i] : '0');
	cout << endl;
	
	return 0;
}