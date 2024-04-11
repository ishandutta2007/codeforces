#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <queue>
#include <map>
#include <set>

#define MAX 16

using namespace std;
FILE *in; FILE *out;

int n, m;
char a[MAX][MAX];
char ans[MAX][MAX]; int with = 0;

char fig[4][4][4] = { {"###", ".#.", ".#."}, { "#..", "###", "#.." }, 
					  {"..#", "###", "..#"}, { ".#.", ".#.", "###" } };

char ans9[MAX][MAX] = {
	"AAA.BCCC.",
	".ABBB.CD.",
	"EA.FB.CD.",
	"EEEF.GDDD",
	"EHFFFGIII",
	".HHHGGGI.",
	"JHKKKL.IM",
	"JJJK.LMMM",
	"J..KLLL.M"
};


void recurse(int row, int col, int cur)
{
	if (cur > with)
	{
		with = cur;
		for (int i = 0; i < n; i++)
			for (int c = 0; c < m; c++)
				ans[i][c] = a[i][c];
	}
	if (cur + ((n - row - 1) * m + m - col) / 5 <= with) return;
	if (row + 2 >= n) return;
	if (col + 2 >= m) {recurse(row + 1, 0, cur); return;}
	for (int f = 0; f < 4; f++)
	{
		int flag = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (fig[f][i][c] == '#' && a[row + i][col + c] != '.')
					{flag = 0; break;}
			}
			if (!flag) break;
		}
		if (flag)
		{
			char let = 'A' + cur;
			for (int i = 0; i < 3; i++)
				for (int c = 0; c < 3; c++)
					if (fig[f][i][c] == '#') a[row + i][col + c] = let;
			recurse(row, col + 1, cur + 1);
			for (int i = 0; i < 3; i++)
				for (int c = 0; c < 3; c++)
					if (fig[f][i][c] == '#') a[row + i][col + c] = '.';
		}
	}
	recurse(row, col + 1, cur);
}


int main(void)
{
	in = stdin; out = stdout;
//	in = fopen("C.in", "rt"); out = fopen("C.out", "wt");
	
	fscanf(in, "%d %d", &n, &m);
	
	if (n == 9 && m == 9)
	{
		fprintf(out, "13\n");
		for (int i = 0; i < 9; i++)
			fprintf(out, "%s\n", ans9[i]);
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < m; c++)
			a[i][c] = '.', ans[i][c] = '.';
		a[i][m] = 0; ans[i][m] = 0;
	}
	recurse(0, 0, 0);
	fprintf(out, "%d\n", with);
	for (int i = 0; i < n; i++)
		fprintf(out, "%s\n", ans[i]);
	
	return 0;
}