#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	vector <int> slist;
	int count[27];
	
	string a, b;
	cin >> a >> b;
	
	for (int i = 0; i < 27; i++)
		count[i] = 0;
	
	if (a.length() != b.length())
	{
		cout << "NO\n";
		return 0;
	}
	
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			slist.push_back (i);
		
		count[a[i] - 'a']++;
	}
	
	if (slist.size() == 2)
	{
		swap(a[slist[0]], a[slist[1]]);
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != b[i])
			{
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		return 0;
	}
	else if (slist.size() == 0)
	{
		for (int i = 0; i < 26; i++)
			if (count[i] >= 2)
			{
				cout << "YES\n";
				return 0;
			}
		cout << "NO\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}