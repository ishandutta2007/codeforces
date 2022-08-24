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
	cin >> N;
	
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < N - i; j++)
			cout << "  ";
		for (int j = 0; j <= i; j++)
		{
			cout << j;
			if (i + j) cout << " ";
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << j;
			if (j) cout << " ";
		}
		cout << "\n";
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < N - i; j++)
			cout << "  ";
		for (int j = 0; j <= i; j++)
		{
			cout << j;
			if (i + j) cout << " ";
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << j;
			if (j) cout << " ";
		}
		cout << "\n";
	}
	return 0;
}