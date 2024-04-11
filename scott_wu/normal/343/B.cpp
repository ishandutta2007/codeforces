#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
char arr[MAXN];

int main()
{
	string str;
	cin >> str;
	
	int narr = 0;
	for (int i = 0; i < str.length(); i++)
	{
		arr[narr] = str[i];
		narr++;
		
		if (narr >= 2 && arr[narr-1] == arr[narr-2])
			narr -= 2;
	}
	
	if (narr)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
	}