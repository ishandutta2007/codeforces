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
	int N; cin >> N;
	
	if (N % 2)
	{
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		cout << (i ^ 1) + 1 << " ";
	cout << "\n";
	return 0;
}