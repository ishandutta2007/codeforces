#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>


using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

char chars_s[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char chars_B[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char chars_num[10] = { '1','2','3','4','5','6','7','8','9','0' };

int print(string str)
{
	int col_s = 0, col_b = 0, col_num = 0;
	bool s = false, b = false, num = false;
	for (auto j : str)
	{
		for (int k = 0; k < 26; k++)
		{
			if (j == chars_s[k])
			{
				s = true;
				col_s++;
			}
			if (j == chars_B[k])
			{
				b = true;
				col_b++;
			}
		}
		for (int k = 0; k < 10; k++)
		{
			if (j == chars_num[k])
			{
				num = true;
				col_num++;
			}
		}
	}


	if (s == false && b && num)
	{
		if (col_b > col_num)
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (str[j] == chars_B[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << 'a';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (str[j] == chars_num[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << 'a';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
	}

	if (s && b == false && num)
	{
		if (col_s > col_num)
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (str[j] == chars_s[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << 'A';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (str[j] == chars_num[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << 'A';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
	}

	if (s && b && num == false)
	{
		if (col_b > col_s)
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (str[j] == chars_B[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << '1';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < str.length(); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (str[j] == chars_s[k])
					{
						for (int m = 0; m < j; m++)
						{
							cout << str[m];
						}
						cout << '1';
						for (int m = j + 1; m < str.length(); m++)
						{
							cout << str[m];
						}
						return 0;
					}
				}
			}
		}
	}

	if (s && b && num)
	{
		cout << str;
		return 0;
	}

	if (s == b)
	{
		cout << "aA";
		for (int i = 2; i < str.length(); i++)
		{
			cout << str[i];
		}
		return 0;
	}

	if (s == num)
	{
		cout << "a1";
		for (int i = 2; i < str.length(); i++)
		{
			cout << str[i];
		}
		return 0;
	}
	if (num == b)
	{
		cout << "1A";
		for (int i = 2; i < str.length(); i++)
		{
			cout << str[i];
		}
		return 0;
	}



}


signed main()
{
	FAST;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		print(str);
		cout << endl;
	}

	
	return 0;
}