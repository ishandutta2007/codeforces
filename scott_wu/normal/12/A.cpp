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
	char ch[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> ch[i][j];
		
	bool check = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (ch[i][j] != ch[2-i][2-j])
				check = false;
	if (check) cout << "YES\n";
	else cout << "NO\n";
	}