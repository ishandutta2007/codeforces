#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	string str;
	cin >> str;
	int loc = str.length() - 1;
	for (int i = str.length() - 1; i >= 0; i--)
		if (str[i] == '0')
			loc = i;
	
	for (int i = 0; i < str.length(); i++)
		if (i != loc)
			cout << str[i];
	cout << "\n";
	return 0;
}