#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

int sums[N][3];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, res = 0;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string s;

		cin >> s;

		int curr_sum = 0, min_sum = 0;

		for(int j = 0; j < s.size(); j++)
		{ 
			if(s[j] == '(')
				curr_sum++;
			else
				curr_sum--;

			min_sum = min(curr_sum, min_sum);
		}

		if(min_sum >= min(curr_sum, 0) )
		{
			if(curr_sum < 0)
				sums[abs(curr_sum)][0]++;
			else
			{
				if(curr_sum == 0)
					sums[curr_sum][1]++;
				else
					sums[curr_sum][2]++; 
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		res += min(sums[i][0], sums[i][2]);
		res += sums[i][1] / 2;
	}

	cout << res << "\n";

	return 0;
}