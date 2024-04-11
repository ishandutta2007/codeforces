#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int n;
vector < string > c;

int main()
{
	cin >> s;
	cin >> n;
	c.resize(n);
	for (int i = 0; i < n; i ++)
		cin >> c[i];
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i ++)
		if (c[i].size() >= s.size())
		{
			bool good = true;
			for (int j = 0; j < s.size(); j ++)
				if (c[i][j] != s[j])
					good = false;
			if (good)
			{
				cout << c[i] << endl;
				return 0;
			}
		}

	cout << s << endl;
	return 0;
}