#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int K, N;
bool edge[MAXN][MAXN];

void draw (int a, int b)
{
	edge[a][b] = edge[b][a] = true;
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			edge[i][j] = false;
	
	cin >> K;
	
	N = 95;
	for (int i = 0; i < 30; i++)
		for (int j = 2 * i + 2; j < 2 * i + 4; j++)
			for (int k = 2 * i + 4; k < 2 * i + 6; k++)
				draw (j, k);
	//draw (60, 1);
	//draw (61, 1);
	for (int i = 64; i < 94; i++)
		draw (i, i + 1);
	draw (94, 1);
	draw (0, 2);
	draw (0, 3);
	
	for (int i = 0; i < 30; i++)
		if (K & (1 << i))
			draw (2 * i + 2, 64 + i + 1);
	
	ios_base::sync_with_stdio (0);
	
	cout << N << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ((edge[i][j]) ? 'Y' : 'N');
		cout << "\n";
	}
	return 0;
}