#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

string s;
int N;

int lcount[27];

bool works (int x)
{
	int tot = 0;
	for (int i = 0; i < 26; i++)
	{
		if (lcount[i])
			tot += (lcount[i] - 1) / x + 1;
	}
	
	return tot <= N;
}

int main()
{
	cin >> s >> N;
	
	for (int i = 0; i < 27; i++)
		lcount[i] = 0;
	
	for (int i = 0; i < s.length(); i++)
		lcount[(int)s[i] - 'a']++;
	
	int ccount = 0;
	for (int i = 0; i < 26; i++)
		if (lcount[i])
			ccount++;
	
	if (ccount > N)
	{
		cout << "-1\n";
		return 0;
	}
	
	int lo = 1, hi = 10000;
	
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (works (mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	cout << lo << "\n";
	
	int tot = 0;
	for (int i = 0; i < 26; i++)
		if (lcount[i])
		{
			for (int j = 0; j < (lcount[i] - 1) / lo + 1; j++)
			{
				cout << (char) (i + 'a');
				tot++;
			}
		}
	for (int i = tot; i < N; i++)
		cout << 'a';
	cout << "\n";
	
	return 0;
}