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
	int N, M;
	cin >> N >> M;
	int lo = 0;
	int hi = N + 1;
	
	for (int i = 0; i < M; i++)
	{
		string str;
		bool left; int val;
		cin >> str >> str >> str;
		left = (str[0] == 'l');
		cin >> str >> val;
		
		if (left)
			hi = min (hi, val);
		else
			lo = max (lo, val);
	}
	
	if (hi - lo - 1 > 0)
		cout << hi - lo - 1 << "\n";
	else
		cout << "-1\n";
	return 0;
}