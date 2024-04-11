#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	string s;

	cin >> s;

	int sum = 0;

	for(int i = 0; i < n; i++)
		sum += (bool)(s[i] == 'G');

	int best2 = 0, best1 = 0, best0 = 0;

	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'S')
		{
			best2 = max(best2, best1);
			best1 = best0+1;
			best0 = 0;
		}
		else
		{
			best1++;
			best0++;
		}
	}

	best2 = max(best2, best1);
	best1 = best0+1;
	best0 = 0;

	cout << min(sum, best2) << "\n";

	return 0;
}