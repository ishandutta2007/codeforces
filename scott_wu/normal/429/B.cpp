#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
ll board[MAXN][MAXN];

ll score[4][MAXN][MAXN][2];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	
	for (int s = 0; s < 4; s++)
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				for (int k = 0; k < 2; k++)
					score[s][i][j][k] = -1e11;
	
	score[0][2][1][0] = score[0][1][2][1] = board[1][1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (i > 1)
				score[0][i][j][0] = max (score[0][i][j][0], max (score[0][i-1][j][0], score[0][i-1][j][1]) + board[i-1][j]);
			if (j > 1)
				score[0][i][j][1] = max (score[0][i][j][1], max (score[0][i][j-1][0], score[0][i][j-1][1]) + board[i][j-1]);
		}
	
	score[1][N][2][0] = score[1][N-1][1][1] = board[N][1];
	for (int i = N; i >= 1; i--)
		for (int j = 1; j <= M; j++)
		{
			if (i < N)
				score[1][i][j][1] = max (score[1][i][j][1], max (score[1][i+1][j][0], score[1][i+1][j][1]) + board[i+1][j]);
			if (j > 1)
				score[1][i][j][0] = max (score[1][i][j][0], max (score[1][i][j-1][0], score[1][i][j-1][1]) + board[i][j-1]);
		}
	
	score[2][N-1][M][0] = score[2][N][M-1][1] = board[N][M];
	for (int i = N; i >= 1; i--)
		for (int j = M; j >= 1; j--)
		{
			if (i < N)
				score[2][i][j][0] = max (score[2][i][j][0], max (score[2][i+1][j][0], score[2][i+1][j][1]) + board[i+1][j]);
			if (j < M)
				score[2][i][j][1] = max (score[2][i][j][1], max (score[2][i][j+1][0], score[2][i][j+1][1]) + board[i][j+1]);
		}
	
	score[3][1][M-1][0] = score[3][2][M][1] = board[1][M];
	for (int i = 1; i <= N; i++)
		for (int j = M; j >= 1; j--)
		{
			if (i > 1)
				score[3][i][j][1] = max (score[3][i][j][1], max (score[3][i-1][j][0], score[3][i-1][j][1]) + board[i-1][j]);
			if (j < M)
				score[3][i][j][0] = max (score[3][i][j][0], max (score[3][i][j+1][0], score[3][i][j+1][1]) + board[i][j+1]);
		}
	
	ll ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			ans = max (ans, score[0][i][j][0] + score[1][i][j][0] + score[2][i][j][0] + score[3][i][j][0]);
			ans = max (ans, score[0][i][j][1] + score[1][i][j][1] + score[2][i][j][1] + score[3][i][j][1]);
		}
	
	cout << ans << "\n";
	return 0;
}