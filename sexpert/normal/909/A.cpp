#include <bits/stdc++.h>
using namespace std;

int main()
{
	int len = 0;
	char c;
	string first, last, name;
	cin >> first >> last;
	name = "";
	while(true)
	{
		if(len < first.length())
		{
			c = first[len];
			if(c < last[0] || len == 0) name += c;
			else
			{
				name += last[0];
				break;
			}
			len++;
		}
		else
		{
			name += last[0];
			break;
		}
	}
	cout << name;
}