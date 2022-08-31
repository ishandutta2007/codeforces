#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N, M;
int nlog;
string blog[MAXN];
int conv[MAXN];
int nmonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cconv (char ch)
{
	return (int) ch - '0';
}

int convert (string str)
{
	int month = 10 * cconv (str[5]) + cconv (str[6]);
	int day = 10 * cconv (str[8]) + cconv (str[9]);
	for (int i = 0; i < month - 1; i++)
		day += nmonth[i];
	
	int hour = 10 * cconv (str[11]) + cconv (str[12]);
	int minute = 10 * cconv (str[14]) + cconv (str[15]);
	int second = 10 * cconv (str[17]) + cconv (str[18]);
	
	return ((24 * day + hour) * 60 + minute) * 60 + second;
}

//2012-03-16 23:59:59

int main()
{
	cin >> N >> M;
	getline (cin, blog[nlog]);
	nlog = 0;
	
	int nlast = 0;
	
	while (true)
	{
		getline (cin, blog[nlog]);
		if (blog[nlog].length() < 5)
			break;
		
		conv[nlog] = convert (blog[nlog]);
		
		while (conv[nlast] <= conv[nlog] - N)
			nlast++;
		
		if (nlog - nlast + 1 >= M)
		{
			cout << blog[nlog].substr (0, 19) << "\n";
			return 0;
		}
		
		nlog++;
	}
	cout << "-1\n";
	return 0;
}