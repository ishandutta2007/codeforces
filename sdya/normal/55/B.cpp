#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long res = 1000000000000000000LL;
string s[5];

void rec(vector < long long > a)
{
	if (a.size() == 1)
	{
		res = min(res, a[0]);
		return ;
	}

	int d = 0;
	if (a.size() == 4) d = (s[1] == "+" ? 1 : 2); else
		if (a.size() == 3) d = (s[2] == "+" ? 1 : 2); else
			d = (s[3] == "+" ? 1 : 2);

	for (int i = 0; i < a.size(); i ++)
		for (int j = i + 1; j < a.size(); j ++)
		{
			vector < long long > b; b.clear();
			for (int k = 0; k < a.size(); k ++)
				if (k != i && k != j)
					b.push_back(a[k]);
			if (d == 1) b.push_back(a[i] + a[j]); else
				b.push_back(a[i] * a[j]);
			rec(b);
		}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long x1, x2, x3, x4;
	cin >> x1 >> x2 >> x3 >> x4;
	cin >> s[1];
	cin >> s[2];
	cin >> s[3];
	vector < long long > a;
	a.push_back(x1);
	a.push_back(x2);
	a.push_back(x3);
	a.push_back(x4);
	rec(a);
	cout << res << endl;
	return 0;
}