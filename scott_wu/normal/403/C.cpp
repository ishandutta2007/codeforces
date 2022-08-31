#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N;
bool seen[MAXN];
int edge[MAXN][MAXN];
int tot;

void flood (int cloc)
{
	if (seen[cloc]) return;
	seen[cloc] = true;
	tot++;
	
	for (int i = 0; i < N; i++)
		if (edge[cloc][i] && !seen[i])
			flood (i);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int c;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			edge[i][j] = (c > 0);
		}
	
	tot = 0;
	for (int i = 0; i < N; i++)
		seen[i] = false;
	
	flood (0);
	
	for (int i = 0; i < N; i++)
	{
		seen[i] = false;
		for (int j = i + 1; j < N; j++)
			swap (edge[i][j], edge[j][i]);
	}
	
	flood (0);
	
	if (tot < 2 * N)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}