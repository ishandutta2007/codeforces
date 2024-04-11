#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, f, p, d;
char s[110];
char s2[110];

int a[1100];
bool used[26];
char res[300];
char cur[300];

int pi[200];

int have()
{
	for (int i = 0; i < n + p + 1; i ++) pi[i] = 0;
	for (int i = 1; i < n + p + 1; i ++) 
	{
		int j = pi[i - 1];
		while (j > 0 && cur[i] != cur[j])
			j = pi[j - 1];
		if (cur[i] == cur[j]) j ++;
		pi[i] = j;
	}
	int res = 0;
	for (int i = 0; i < n + p + 1; i ++)
		if (pi[i] == p)
			res ++;
	return res;
}

void rec(int k)
{
	if (k == n + p + 1)
	{
		if (have() > d)
		{
			cout << "No solution" << endl;
			exit(0);
		}
		for (int i = p + 1; i < n + p + 1; i ++)
			printf("%c", cur[i]);
		printf("\n");
		exit(0);
	}

	if (cur[k] != 0) {rec(k + 1); return ;}

	for (int i = 0; i < f; i ++)
	{
		cur[k] = 'a' + i;
		if (have() > d) continue;
		rec(k + 1);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d%d\n", &n, &f);
	gets(s);
	gets(s2);
	p = strlen(s);
	for (int i = 0; i < strlen(s2); i ++)
	{
		a[i] = s2[i] - '0';
		if (a[i] == 1) d ++;
	}

	for (int j = 0; j < p; j ++)
		cur[j] = s[j];

	cur[p] = '#';
	for (int j = 0; j < n - p + 1; j ++)
		if (a[j] == 1)
		{
			for (int k = 0; k < p; k ++)
				if (cur[p + 1 + j + k] == 0 || cur[p + 1 + j + k] == s[k]) cur[p + 1 + j + k] = s[k]; else
				{
					cout << "No solution" << endl;
					return 0;
				}
		}

	rec(0);

	cout << "No solution" << endl;

	return 0;
}