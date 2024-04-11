#include <iostream>

using namespace std;
const int MAXN = 100100;
const int MAXA = 1100;

int N, M;
int cnt[MAXA][MAXA];
int dcnt[MAXA];

int main()
{
	for (int i = 0; i < MAXA; i++)
	{
		for (int j = 0; j < MAXA; j++)
			cnt[i][j] = 0;
		dcnt[i] = 0;
	}
	
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		
		cnt[x][y]++;
		dcnt[y]++;
	}
	
	int u = 0, v = 0;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if (dcnt[y])
		{
			dcnt[y]--;
			u++;
		}
		if (cnt[x][y])
		{
			cnt[x][y]--;
			v++;
		}
	}
	
	cout << u << " " << v << "\n";
	return 0;
}