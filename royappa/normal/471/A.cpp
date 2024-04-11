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


//http://codeforces.com/contest/471/problem/0

using namespace std;


typedef long long LL;

int main()
{
	int x;
	vector<int> len(10, 0);
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		len[x]++;
	}
	bool found4 = false;
	int n4 = -1;
	for (int i = 0; i <= 9; i++)
	{
		if (len[i] >= 4)
		{
			int n4 = i;
			len[i] -= 4;
			found4 = true;
			break;
		}
	}
	if (!found4)
	{
		cout << "Alien";
	}
	else if (find(len.begin(), len.end(), 2) != len.end())
	{
		cout << "Elephant";
	}
	else
	{
		cout << "Bear";
	}
	cout << endl;
	exit(0);
}