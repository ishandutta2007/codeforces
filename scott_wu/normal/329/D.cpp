#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

char board[110][110];

int main()
{
	int N, X;
	cin >> N >> X;
	
	if (N == 5)
	{
		cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n";
		cout << "1 1\n";
		return 0;
	}
	if (N == 3)
	{
		cout << ">vv\n^<.\n^.<\n";
		cout << "1 3\n";
		return 0;
	}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = '.';
	
	board[0][0] = '>';
	for (int i = 1; i < 100; i++)
		board[i][0] = '^';
	
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 1; j <= 33; j++)
				board[i][j] = '>';
			for (int j = 35; j <= 99; j+=2)
				board[i][j] = '>';
			board[i][99] = 'v';
		}
		else
		{
			for (int j = 1; j <= 65; j+=2)
				board[i][j] = '<';
			for (int j = 67; j <= 99; j++)
				board[i][j] = '<';
			
			if (i < 99)
				board[i][1] = 'v';
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j];
		cout << "\n";
	}
	cout << "1 1\n";
	return 0;
}