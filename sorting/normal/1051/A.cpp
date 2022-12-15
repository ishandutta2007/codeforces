#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

bool valid(string s)
{
	bool digit = false, big = false, small = false;

	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			digit = 1;
		if(s[i] >= 'a' && s[i] <= 'z')
			small = 1;
		if(s[i] >= 'A' && s[i] <= 'Z')
			big = 1; 
	}

	int cnt = (int)(digit + big + small);

	if(cnt == 3)
		return 1;

	return 0;
}

int main ()
{
	int t;
	string dict = "1aA";

	cin >> t;

	for(t; t > 0; t--)
	{
		string s, x;

		cin >> s;

		if(valid(s))
		{
			cout << s << "\n";

			continue;
		}

		bool sol = false;

		for(int i = 0; i < s.size() && !sol; i++)
		{
			x = s;

			for(int j = 0; j < 3 && !sol; j++)
				{
					x = s;
					x[i] = dict[j];
					if(valid(x))
					{
						cout << x << "\n";
						sol = true;
						break;
					}
				}
		}

		if(sol)
			continue;

		sol = false;

		for(int i = 0; i < s.size() -1 && !sol; i++)
		{
			x = s;

			for(int j = 0; j < 3 && !sol; j++)
				for(int j2 = 0; j2 < 3 && !sol; j2++)
				{
					x = s;
					x[i] = dict[j];
					x[i+1] = dict[j2];

					if(valid(x))
					{
						cout << x << "\n";
						sol = true;
						break;
					}
				}
		}

		if(!sol)
		{
			for(int i = 0; i < s.size() -2 && !sol; i++)
			{
				for(int j = 0; j < 3 && !sol; j++)
					for(int j2 = 0; j2 < 3 && !sol; j2++)
						for(int j3 = 0; j3 < 3 && !sol; j3++)
						{
							x = s;
							x[i] = dict[j];
							x[i+1] = dict[j2];
							x[i+2] = dict[j3];

							if(valid(x))
							{
								cout << x << "\n";
								sol = true;
								break;
							}
						}
			}
		}
	}
}