// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#include<vector>

const int MAXN = 100010;

int F[MAXN];

int Find(int x)
{
	return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

void Union(int x, int y)
{
	F[Find(x)] = Find(y);
}

vector<int> TOS[MAXN];

int N, M;
int RIDG[MAXN];

#include<queue>

queue<int> Q;

bool FREE[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	int i, j;
	fortodo(i, 1, N)
		{
			F[i] = i;
			TOS[i].clear();
			RIDG[i] = 0;
		}
	fortodo(i, 1, M)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			TOS[u].push_back(v);
			Union(u, v);
			RIDG[v]++;
		}
	while (Q.size()) Q.pop();
	fortodo(i, 1, N)
		if (RIDG[i] == 0)
			Q.push(i);
	while (Q.size())
		{
			int u = Q.front();
			Q.pop();
			for (vector<int>::iterator it = TOS[u].begin(); it != TOS[u].end(); it++)
				if ((--RIDG[*it]) == 0)
					Q.push(*it);
		}
	fortodo(i, 1, N)
		FREE[i] = true;
	fortodo(i, 1, N)
		FREE[Find(i)] &= (RIDG[i] == 0);
	int ANS = N;
	fortodo(i, 1, N)
		if ((FREE[i]) && (F[i] == i))
			ANS--;
	printf("%d\n", ANS);
}