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
	int N;
	double tot = 0.0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double x; cin >> x;
		tot += x / N;
	}
	
	cout << fixed << setprecision (5);
	cout << tot << "\n";
	return 0;
}