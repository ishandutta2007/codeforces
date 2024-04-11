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


bool isAnagram(string a, string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

bool isAutomaton(string s, string t)
{
	int n = s.size(), m = t.size();
	int p = 0;
	for (int i = 0; i < m; i++)
	{
		while (p < n && s[p] != t[i])
			p++;
		if (p == n)
			return false;
		p++;
	}
	return true;
}

bool isBoth(string a, string b)
{
	int n = a.size(), m = b.size();
	for (int i = 0; i < m; i++)
	{
		if (a.find(b[i]) == -1)
			return false;
	}
	for (int i = 0; i < m; i++)
	{
		int x = count(a.begin(), a.end(), b[i]);
		int y = count(b.begin(), b.end(), b[i]);
		if (y > x)
			return false;
	}
	return true;
}

int main()
{
	string s, t;
	cin >> s >> t;

	if (isAutomaton(s, t))
	{
		cout << "automaton";
	}
	else if (isAnagram(s, t))
	{
		cout << "array";
	}
	else if (isBoth(s, t))
	{
		cout << "both";
	}
	else
	{
		cout << "need tree";
	}
	cout << endl;
}