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

#include <string.h>

using namespace std;



int main()
{
	int n, s;

	cin >> n >> s;
	map<int,int> B, S;

	for (int i = 0; i < n; i++)
	{
		string dir;
		int p, q;
		cin >> dir >> p >> q;
		if (dir == "B")
			B[p] += q;
		else
			S[p] += q;
	}
	int num = s;
	vector<pair<int,int>> v;
	for (auto x : S)
	{
		if (num > 0)
			v.push_back(make_pair(x.first,x.second));
		else
			break;
		num--;
	}
	reverse(v.begin(), v.end());
	for (auto x : v)
		cout << "S " << x.first << " " << x.second << endl;
	v.resize(0);
	num = s;
	for (auto x : B)
	{
		v.push_back(make_pair(x.first, x.second));
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < num && i < v.size(); i++)
	{
		cout << "B " << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}