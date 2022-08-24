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
	int N = str.length();
	
	bool check = true;
	for (int i = 1; i < N; i++)
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			check = false;
	
	if (check)
	{
		for (int i = 0; i < N; i++)
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] += 'A' - 'a';
			else
				str[i] += 'a' - 'A';
	}
	cout << str << "\n";
}