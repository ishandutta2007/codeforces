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
	ll sum = 0;
	int N;
	int num[100100];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	for (int i = 0; i < N - 1; i++)
		if (num[i+1] < num[i])
			sum += num[i] - num[i+1];
	cout << sum << "\n";
	return 0;
}