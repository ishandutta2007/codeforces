#include <iostream>
using namespace std;
#define MAX 200000
#define LL long long

LL int a[MAX];

bool canFinish(int length)
{
	LL int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += a[i];
	}
	if (sum != 0)
	{
		return false;
	}


	int lastNonZero = length - 1;
	while (lastNonZero != 0 && a[lastNonZero] == 0)
	{
		lastNonZero--;
	}
	if (a[lastNonZero] > 0)
	{
		return false;
	}
	a[0] -= 1;
	a[lastNonZero] += 1;
	LL int preSum = 0;

	for (int i = 0; i <= lastNonZero; i++)
	{
		preSum += a[i];
		if (preSum < 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		if (n == 0 || canFinish(n))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}