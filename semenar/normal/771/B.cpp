#define _CRT_SECURE_NO_WARNINGS 

#include <iostream> 
#include <fstream> 
#include <vector> 
#include <cmath> 
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k;
string s, s2;
vector <int> v;
vector <string> ss;

void main()
{
	cin >> n >> k;
	m = 0;
	for (int i = 0; i < k - 1; i++)
	{
		if (m <= 25)
		{
			char c = 'A' + m;
			s = "";
			s += c;
			ss.push_back(s);
		}
		else
		{
			char c = 'A' + m - 26;
			s = "";
			s += c;
			c = 'a' + m - 26;
			s += c;
			ss.push_back(s);
		}
		m++;
	}
	for (int i = k; i <= n; i++)
	{
		cin >> s2;
		if (s2 == "NO")
		{
			ss.push_back(ss[i - k]);
		}
		else
		{
			if (m < 25)
			{
				char c = 'A' + m;
				s = "";
				s += c;
				ss.push_back(s);
			}
			else
			{
				char c = 'A' + m - 25;
				s = "";
				s += c;
				c = 'a' + m - 25;
				s += c;
				ss.push_back(s);
			}
			m++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ss[i] << " ";
	}

}