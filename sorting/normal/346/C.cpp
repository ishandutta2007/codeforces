#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int x[N];
vector<int> v, arr[N];
int a, b;


int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> x[i];

	cin >> a >> b;

	if(a == b)
	{
		cout << "0\n";

		return 0;
	}

	sort(x+1, x+n+1);

	//v.push_back(1);

	for(int i = 1; i <= n; i++)
		if(x[i] != x[i-1])
			v.push_back(x[i]);

	n = v.size();

	int res = 0;

	while(a > b)
	{
		int max_possible = 1;

		for(int i = 0; i < n ; i++)
		{
			int curr = a % v[i];

			if(a - curr >= b)
				max_possible = max(curr, max_possible);
			else
			{
				v[i] = v[n-1];
				n--;
				i--;
			}
		}

		a -= max_possible;
		res++;
	}

	cout << res << "\n";

	return 0;
}