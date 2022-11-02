#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <queue>

using namespace std;

char s[110];

bool used[300][300];
int d[300][300];

int main()
{
	gets(s);
	int x = 150, y = 150;
	for (int i = 0; i < strlen(s); i ++)
	{
		used[x][y] = true;
		if (s[i] == 'R') x ++; else
			if (s[i] == 'L') x --; else
				if (s[i] == 'U') y ++; else y --;
	}
	used[x][y] = true;
	queue < pair < int, int > > q;
	q.push(make_pair(150, 150));
	for (int i = 0; i < 300; i ++)
		for (int j = 0; j < 300; j ++)
			d[i][j] = 1000000000;
	d[150][150] = 0;
	while (!q.empty())
	{
		pair < int, int > t = q.front(); q.pop();
		int u = t.first, v = t.second;
		if (used[u + 1][v] && d[u + 1][v] > d[u][v] + 1) q.push(make_pair(u + 1, v)), d[u + 1][v] = d[u][v] + 1;
		if (used[u - 1][v] && d[u - 1][v] > d[u][v] + 1) q.push(make_pair(u - 1, v)), d[u - 1][v] = d[u][v] + 1;
		if (used[u][v + 1] && d[u][v + 1] > d[u][v] + 1) q.push(make_pair(u, v + 1)), d[u][v + 1] = d[u][v] + 1;
		if (used[u][v - 1] && d[u][v - 1] > d[u][v] + 1) q.push(make_pair(u, v - 1)), d[u][v - 1] = d[u][v] + 1;
	}

	if (d[x][y] != strlen(s)) cout << "BUG" << endl; else cout << "OK" << endl;
	return 0;
}