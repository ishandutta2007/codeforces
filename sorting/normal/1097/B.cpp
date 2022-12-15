#include <bits/stdc++.h>

using namespace std;

const int K = 1000;

bool possible_prev[K];
bool possible_curr[K];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	possible_curr[0] = true;

	for(int i = 0; i < n; i++)
	{
		int a;

		cin >> a;

		swap(possible_curr, possible_prev);
		for(int j = 0; j < 360; j++)
			possible_curr[j] = false;

		for(int j = 0; j < 360; j++)
			if(possible_prev[j])
			{
				int x, y;

				x = (j + a) % 360;
				y = (j - a + 360) % 360;

				possible_curr[x] = true;
				possible_curr[y] = true;
			}
	}

	if(possible_curr[0])
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}