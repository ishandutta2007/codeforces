#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;



int main()
{
	int n, m;

	cin >> n >> m;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string s(m, ' ');
		v.push_back(s);
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	int r = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			string a = string("")+v[i][j]+v[i][j+1]+v[i+1][j]+v[i+1][j+1];
			sort(a.begin(), a.end());
			r += a == "acef";
		}
	}
	cout << r << endl;
	return 0;
}