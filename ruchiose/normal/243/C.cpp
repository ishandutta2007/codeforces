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

int N;
int X[1010], Y[1010];

#include<vector>
#include<queue>
#define x0 x233333333
#define y0 y233333333
vector<int> Xs, Ys;
int x0, y0;

bool def[2010][2010], vis[2010][2010];
typedef pair<int,int> PII;
queue<PII> Q;

int main()
{
	scanf("%d", &N);
	X[0] = Y[0] = 0;
	int i, j;
	fortodo(i, 1, N)
		{
			X[i] = X[i - 1];
			Y[i] = Y[i - 1];
			char d[4];
			int p;
			scanf("%s%d", d, &p);
			if (d[0] == 'L') X[i] -= p;
			if (d[0] == 'R') X[i] += p;
			if (d[0] == 'U') Y[i] -= p;
			if (d[0] == 'D') Y[i] += p;
		}
	Xs.clear(); Xs.push_back(-1233333333);
	fortodo(i, 0, N)
		{
			Xs.push_back(X[i]);
			Xs.push_back(X[i] + 1);
		}
	sort(Xs.begin(), Xs.end());
	Xs.resize(unique(Xs.begin(), Xs.end()) - Xs.begin());
	Ys.clear(); Ys.push_back(-1233333333);
	fortodo(i, 0, N)
		{
			Ys.push_back(Y[i]);
			Ys.push_back(Y[i] + 1);
		}
	sort(Ys.begin(), Ys.end());
	Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());
	x0 = Xs.size(); y0 = Ys.size();
	fortodo(i, 0, x0 - 1)
		fortodo(j, 0, y0 - 1)
			def[i][j] = vis[i][j] = false;
	fortodo(i, 1, N)
		if (X[i] == X[i - 1])
			{
				int u  = lower_bound(Xs.begin(), Xs.end(), X[i]) - Xs.begin();
				int vs = lower_bound(Ys.begin(), Ys.end(), min(Y[i], Y[i - 1])) - Ys.begin();
				int ve = upper_bound(Ys.begin(), Ys.end(), max(Y[i], Y[i - 1])) - Ys.begin();
				fortodo(j, vs, ve - 1) def[u][j] = true;
			}
		else
			{
				int us = lower_bound(Xs.begin(), Xs.end(), min(X[i], X[i - 1])) - Xs.begin();
				int ue = upper_bound(Xs.begin(), Xs.end(), max(X[i], X[i - 1])) - Xs.begin();
				int v  = lower_bound(Ys.begin(), Ys.end(), Y[i]) - Ys.begin();
				fortodo(j, us, ue - 1) def[j][v] = true;
			}
	/*
	fortodo(i, 0, x0 - 1) printf("Xs[%d] = %d\n", i, Xs[i]);
	fortodo(i, 0, y0 - 1) printf("Ys[%d] = %d\n", i, Ys[i]);
	fortodo(i, 0, x0 - 1)
		fortodo(j, 0, y0 - 1)
			printf("%s%s", (def[i][j]) ? "#" : " ", (j == y0 - 1) ? "\n" : "");
	*/
	while (Q.size()) Q.pop();
	vis[0][0] = true;
	Q.push(make_pair(0, 0));
	while (Q.size())
		{
			#define _F first
			#define _S second
			PII h = Q.front();
			Q.pop();
			if ((h._F - 1 >= 0) && (!def[h._F - 1][h._S]) && (!vis[h._F - 1][h._S]))
				{
					vis[h._F - 1][h._S] = true;
					Q.push(make_pair(h._F - 1, h._S));
				}
			if ((h._F + 1 < x0) && (!def[h._F + 1][h._S]) && (!vis[h._F + 1][h._S]))
				{
					vis[h._F + 1][h._S] = true;
					Q.push(make_pair(h._F + 1, h._S));
				}
			if ((h._S - 1 >= 0) && (!def[h._F][h._S - 1]) && (!vis[h._F][h._S - 1]))
				{
					vis[h._F][h._S - 1] = true;
					Q.push(make_pair(h._F, h._S - 1));
				}
			if ((h._S + 1 < y0) && (!def[h._F][h._S + 1]) && (!vis[h._F][h._S + 1]))
				{
					vis[h._F][h._S + 1] = true;
					Q.push(make_pair(h._F, h._S + 1));
				}
		}
	i64 ans = 0;
	fortodo(i, 1, x0 - 2)
		fortodo(j, 1, y0 - 2)
			if (!vis[i][j])
				ans += 1LL * (Xs[i + 1] - Xs[i]) * (Ys[j + 1] - Ys[j]);
	cout << ans << endl;
}