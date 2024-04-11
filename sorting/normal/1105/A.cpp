#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
const int inf = 1e9;


int a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}

	int t, res = inf;

	for(int i = 1; i <= 100; i++)
	{
		int cost = 0;

		for(int j = 0; j < n; j++)
			cost += max(abs(a[j] - i) - 1, 0);

		if(cost < res)
		{
			res = cost;
			t =i;
		}
	}

	cout << t << " " << res << "\n";

	return 0; 
}