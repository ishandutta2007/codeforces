#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	string str;
	cin >> str;
	int a, b, c = -1;
	if (str[0] == 'h')
		a = 3;
	else
		a = 2;
	
	for (int i = a + 2; i < str.length() - 1; i++)
	{
		if (str[i] == 'r' && str[i+1] == 'u')
		{
			b = i - 1;
			if (i < str.length() - 2)
				c = i + 1;
			break;
		}
	}
	
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		if (i == a)
			cout << "://";
		if (i == b)
			cout << ".";
		if (i == c)
			cout << "/";
	}
	cout << "\n";
	return 0;
}