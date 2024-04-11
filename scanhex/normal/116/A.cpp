#include <iostream>
#include <stdio.h>
#define ll long long

using namespace std;

int main()
{
	int cur = 0;
	int n;
	cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; ++i) 
	{
		int a, b;
		cin >> a >> b;
		cur -= a;
		cur += b;
		if (cur > maxi)
			maxi = cur;
	}
	cout << maxi;
}