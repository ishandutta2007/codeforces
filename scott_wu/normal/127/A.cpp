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
	int n, k;
	int x[110], y[110];
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	double dist = 0.0;
	for (int i = 0; i < n - 1; i++)
		dist += sqrt ((x[i] - x[i+1]) * (x[i] - x[i+1]) + (y[i] - y[i+1]) * (y[i] - y[i+1]));
		
	cout << fixed << setprecision (7);
	cout << dist * k / 50.0 << "\n";
	return 0;
}