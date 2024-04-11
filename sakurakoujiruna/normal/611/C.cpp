#include <iostream>
using namespace std;

const int N = 511;

int sumr[N][N];
int sumc[N][N];
string str[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> str[i];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(str[i - 1][j - 1] == '.' && i != n && str[i][j - 1] == '.')
				sumc[i][j] ++;
			if(str[i - 1][j - 1] == '.' && j != m && str[i - 1][j] == '.')
				sumr[i][j] ++;
			sumr[i][j] += sumr[i - 1][j] + sumr[i][j - 1] - sumr[i - 1][j - 1];
			sumc[i][j] += sumc[i - 1][j] + sumc[i][j - 1] - sumc[i - 1][j - 1];
		}

	int q;
	cin >> q;
	while(q --)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ansr = sumr[r2][c2 - 1] - sumr[r1 - 1][c2 - 1] - sumr[r2][c1 - 1] + sumr[r1 - 1][c1 - 1];
		int ansc = sumc[r2 - 1][c2] - sumc[r1 - 1][c2] - sumc[r2 - 1][c1 - 1] + sumc[r1 - 1][c1 - 1];
		cout << ansr + ansc << '\n';
	}
	return 0;
}