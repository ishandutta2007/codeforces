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
	bool check = false;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
			check = true;
	cout << ((check) ? "YES" : "NO") << "\n";
}