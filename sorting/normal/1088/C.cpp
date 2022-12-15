#include<bits/stdc++.h>

using namespace std;

const int N = 2018;
const int inf = 1e5 + 7;

int a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int curr = 0;

	cout << n+1 <<"\n";

	for(int i = n-1; i >= 0; i--)
	{
		int x = i - (curr+a[i]) + 2*inf;

		cout << "1 " << i+1 << " " << x << "\n";

		curr += x;
		curr %= inf;  
	}

	cout << "2 " << n << " " << inf << "\n";

	return 0;
}