#include <iostream>
using namespace std;
#define MAX_N 5001

int cChoice[MAX_N][MAX_N];
int bChoice[MAX_N][MAX_N];

long long int getTuple(int nums[], int numCount)
{
	for (int i = 0; i < numCount; i++)
	{
		int cnt = 0;
		for (int j = 0; j < i; j++)
		{
			cnt += nums[j] < nums[i];
			cChoice[i][j] = cnt;
		}
	}

	for (int i = 0; i < numCount; i++)
	{
		int cnt = 0;
		for (int j = numCount - 1; j > i; j--)
		{
			cnt += nums[j] < nums[i];
			bChoice[i][j] = cnt;
		}
	}

	long long int res = 0;
	for (int b = 1; b < numCount - 2; b++)
	{
		for (int c = b + 1; c < numCount - 1; c++)
		{
			res += cChoice[c][b - 1] * bChoice[b][c + 1];
		}
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int nums[MAX_N];
		int numCount;
		cin >> numCount;
		for (int j = 0; j < numCount; j++)
		{
			cin >> nums[j];
		}
		cout << getTuple(nums, numCount);
		if (i != n - 1)
		{
			cout << endl;
		}
	}

	return 0;
}