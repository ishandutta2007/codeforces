#include <iostream>
using namespace std;

int c[2][3];

int main()
{
	ios :: sync_with_stdio(false);
	for(int i = 0; i < 3; i ++)
		cin >> c[0][i] >> c[1][i];

	int cnt[2] = {0, 0};
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 3; j ++)
			for(int k = j + 1; k < 3; k ++)
				if(c[i][j] == c[i][k])
					cnt[i] ++;

	if(cnt[0] == 3 || cnt[1] == 3)
	{
		cout << 1 << '\n';
		return 0;
	}
	
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 3; j ++)
			for(int k = j + 1; k < 3; k ++)
				if(c[i][j] == c[i][k])
				{
					int tmin = min(c[i ^ 1][j], c[i ^ 1][k]);
					int tmax = max(c[i ^ 1][j], c[i ^ 1][k]);
					int acc = 0;
					for(int t = 0; t < 3; t ++)
						if(c[i ^ 1][t] <= tmin || c[i ^ 1][t] >= tmax)
							acc ++;
					if(acc == 3)
					{
						cout << 2 << '\n';
						return 0;
					}
				}
	cout << 3 << '\n';
	return 0;
}