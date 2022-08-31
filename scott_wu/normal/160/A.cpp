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
	int sum = 0;
	int arr[110];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort (arr, arr + N);
	
	for (int i = 0; i < N; i++)
		sum += arr[i];
	int csum = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		csum += arr[i];
		if (csum * 2 > sum)
		{
			cout << N - i << "\n";
			return 0;
		}
	}
}