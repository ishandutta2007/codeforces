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
	
	int nout = 0, nin = 0;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			if (nout > 0)
				nout--;
			nin++;
		}
		else
		{
			if (nin > 0)
				nin--;
			nout++;
		}
	}
	cout << nin + nout << "\n";
	return 0;
}