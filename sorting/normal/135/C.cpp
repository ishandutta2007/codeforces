#include<bits/stdc++.h>

using namespace std;

int zero, one, both;

vector<pair<int, int> > v;

int main ()
{
	string s;

	cin >> s;

	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '0')
			zero++;
		else
		{
			if(s[i] == '1')
				one++;
			else
				both++;
		}
	}

	if(zero + both > one)
		cout << "00\n";

	if(s.back() == '?')
	{
		both--;
		one++;
	}

	if(s.back() != '0')
		if( (both + one - zero) % 2 ==  s.size() % 2)
		{
			int tmp = (both + one - zero - (s.size() % 2)) / 2;

			if(tmp >= 0 && tmp <= both)
				cout << "01\n";
		}

	if(s.back() == '?')
	{
		both++;
		one--;
		both--;
		zero++;
	}

	if(s.back() != '1')
		if( (both + one - zero) % 2 ==  s.size() % 2)
		{
			int tmp = (both + one - zero - (s.size() % 2)) / 2;

			if(tmp >= 0 && tmp <= both)
				cout << "10\n";
		}

	if(s.back() == '?')
	{
		both++;
		zero--;
	}

	if(zero + 1 < one + both)
		cout << "11\n";

	return 0;
}