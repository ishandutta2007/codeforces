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
	int x; cin >> x;
	for (int i = 0; i < 100; i++)
		if ((i * (i + 1)) / 2 == x){
			cout << "YES\n";
			return 0;}
	cout << "NO\n";
	return 0;
	}