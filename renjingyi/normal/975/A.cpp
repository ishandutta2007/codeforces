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
map<char, bool> asd;
string getroot(const string &s)
{
	asd.clear();
	for(int i = 0; i < s.size(); i ++)\
		asd[s[i]] = 1;
	string ans = "";
	for(map<char, bool>::iterator it = asd.begin(); it != asd.end(); it ++)
		ans += it->first;
	return ans;
}
map<string, bool> appear;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		string s;
		cin >> s;
		string now = getroot(s);
		appear[now] = 1;
	}
	cout << appear.size() << endl;
	
	return 0;
}