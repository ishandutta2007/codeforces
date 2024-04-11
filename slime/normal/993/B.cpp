#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 50
using namespace std;
int ns[maxn][2];
int intr[maxn][maxn];
int nr[2][maxn], n[2];
bool flag[maxn];
int main()
{
	int ncnt = 0;
	for(int i = 1; i <= 9; i++)
		for(int j = i + 1; j <= 9; j++)
			ns[ncnt][0] = i, ns[ncnt++][1] = j;
	for(int i = 0; i < ncnt; i++)
		for(int j = 0; j < ncnt; j++)
		{
			intr[i][j] = -1;
			for(int k = 0; k < 2; k++)
				for(int l = 0; l < 2; l++)
					if(ns[i][k] == ns[j][l])
						intr[i][j] = ns[i][k];
		}
	scanf("%d%d", &n[0], &n[1]);
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n[i]; j++)
		{
			int x[2];
			scanf("%d%d", &x[0], &x[1]);
			if(x[0] > x[1]) swap(x[0], x[1]);
			for(int l = 0; l < ncnt; l++)
				if(ns[l][0] == x[0] && ns[l][1] == x[1])
					nr[i][j] = l;
		}
	}
	for(int i = 0; i < ncnt; i++)
		for(int j = 0; j < ncnt; j++)
		{
			if(i == j) continue;
			if(intr[i][j] == -1) continue;
			bool nf = 0;
			for(int k = 0; k < n[0]; k++)
				if(nr[0][k] == i) nf = 1;
			if(!nf) continue;
			nf = 0;
			for(int k = 0; k < n[1]; k++)
				if(nr[1][k] == j) nf = 1;
			if(!nf) continue;
			flag[intr[i][j]] = 1;
		}
	int lpl, cnt = 0;
	for(int i = 1; i <= 9; i++)
		if(flag[i]) cnt++, lpl = i;
	if(cnt == 1)
	{
		printf("%d\n", lpl);
		return 0;
	}
	bool fl = 0;
	for(int t = 0; t < 2; t++)
		for(int i = 0; i < ncnt; i++)
		{
			bool flag[10];
			memset(flag, 0, sizeof(flag));
			for(int j = 0; j < ncnt; j++)
			{
				if(i == j) continue;
				if(intr[i][j] == -1) continue;
				bool nf = 0;
				for(int k = 0; k < n[t]; k++)
					if(nr[t][k] == i) nf = 1;
				if(!nf) continue;
				nf = 0;
				for(int k = 0; k < n[t ^ 1]; k++)
					if(nr[t ^ 1][k] == j) nf = 1;
				if(!nf) continue;
				flag[intr[i][j]] = 1;
			}
			int ncnt = 0;
			for(int k = 1; k <= 9; k++)
				if(flag[k]) ncnt++;
			if(ncnt >= 2) fl = 1;
		}
	if(fl) printf("-1\n");
	else printf("0\n");
	return 0;
}