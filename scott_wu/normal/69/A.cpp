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
	int xsum = 0, ysum = 0, zsum = 0;
	int N; cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		xsum += x, ysum += y, zsum += z;
	}
	
	if (!xsum && !ysum && !zsum)
		cout << "YES\n";
	else
		cout << "NO\n";
}