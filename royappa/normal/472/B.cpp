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


//http://codeforces.com/contest/472/problem/B

using namespace std;


typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i]--;
	}
	sort(v.begin(), v.end());
	int last = v[v.size()-1];
	int t = 0;
	while (v.size() > 0)
	{
		int m = v[0];
		n = v.size();
		int b = (n+k-1)/k;
		t += m*(2*(b-1)+1);
		while (v.size() > 0 && v[0] == m)
		{
			v.erase(v.begin());
		}
		for (int i = 0; i < v.size(); i++)
		{
			v[i] -= m;
		}
	}
	t += last;
	cout << t << endl;
	exit(0);
}