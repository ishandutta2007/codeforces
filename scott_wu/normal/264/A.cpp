#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

vector <int> lans;
vector <int> rans;
string str;

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'l')
			rans.push_back (i + 1);
		else
			lans.push_back (i + 1);
	}
	
	for (int i = 0; i < lans.size(); i++)
		cout << lans[i] << "\n";
	for (int i = 0; i < rans.size(); i++)
		cout << rans[rans.size() - 1 - i] << "\n";
	return 0;
}