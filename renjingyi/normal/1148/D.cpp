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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<pair<int, int>, int > pp;
const int maxn = 3e5 + 5;
pp a[maxn];
vector<pp> asd1, asd2;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(a[i].first.first < a[i].first.second)
			asd1.push_back(a[i]);
		else
			asd2.push_back(a[i]);
	}
	if(asd1.size() > asd2.size())
	{
		sort(asd1.begin(), asd1.end());
		cout << asd1.size() << endl;
		for(int i = (int)asd1.size() - 1; i >= 0; i --)
			cout << asd1[i].second << " ";
		cout << endl;
	}
	else
	{
		sort(asd2.begin(), asd2.end());
		cout << asd2.size() << endl;
		for(int i = 0; i < asd2.size(); i ++)
			cout << asd2[i].second << " ";
		cout << endl;
	}
	
	return 0;
}