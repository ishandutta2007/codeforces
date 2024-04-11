#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 110;

bool edge[MAXN][MAXN];

int main()
{
	int T; cin >> T;
	for (int test = 0; test < T; test++)
	{
	
	int N, P;
	cin >> N >> P;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			edge[i][j] = false;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			int k = (j + i) % N;
			edge[i][k] = edge[k][i] = true;
		}
	}
	
	int cnt = P;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (cnt > 0 && i != j && !edge[i][j])
			{
				cnt--;
				edge[i][j] = edge[j][i] = true;
			}
		}
	
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (edge[i][j])
				cout << i + 1 << " " << j + 1 << "\n";
	}
	
	return 0;
}