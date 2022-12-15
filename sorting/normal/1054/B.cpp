#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N];

set<int> Set;

int curr_mex = 0;

void update_mex()
{
	while(Set.find(curr_mex) != Set.end())
		curr_mex++;
}

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
	{
		if(a[i] > curr_mex)
		{
			cout << i+1 << "\n";
			return 0;
		}

		if(a[i] == 0)
		{
			Set.insert(a[i]);
			update_mex();
			continue;
		}

		if(Set.find(a[i]-1) == Set.end())
		{
			cout << i+1 << "\n";
			return 0;
		}

		Set.insert(a[i]);
		update_mex();
	}

	cout << "-1\n";

	return 0;
}