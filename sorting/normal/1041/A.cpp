#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n, x, maxi, mini;

	cin >> n;

	cin >> maxi;
	mini = maxi;

	for(int i = 1; i < n; i++)
	{
		cin >> x;

		mini = min(x, mini);
		maxi = max(x, maxi);
	}

	cout << maxi-mini+1 - n << endl;

	return  0;
}