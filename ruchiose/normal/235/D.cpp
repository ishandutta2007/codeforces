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

const int MAXN = 3010;
const int MAXE = MAXN << 1;

int N;
int e[MAXE], enxt[MAXE], head[MAXN], ec;

void regi(int u, int v)
{
	e[++ec] = v; enxt[ec] = head[u]; head[u] = ec;
}

int visId[MAXN];
vector<int> Loop, stk;

bool FindLoop(int ths, int prev)
{
	if (visId[ths] != -1)
		{
			Loop = vector<int>(stk.begin() + visId[ths], stk.end());
			return true;
		}
	visId[ths] = stk.size();
	stk.push_back(ths);
	bool Flag = false;
	for (int E = head[ths]; E; E = enxt[E])
		if ((prev != e[E]) && (FindLoop(e[E], ths)))
			{
				Flag = true;
				break;
			}
	stk.pop_back();
	visId[ths] = -1;
	return Flag;
}

int Dist[MAXN], Color[MAXN], Father[MAXN], LoopAddress[MAXN];
int Ance[MAXN][13];

void dfs(int cur, int color, int dist, int father)
{
	Dist[cur] = dist;
	Color[cur] = color;
	Father[cur] = father;
	Ance[cur][0] = father;
	for (int i = 1; i <= 12; i++) Ance[cur][i] = Ance[Ance[cur][i - 1]][i - 1];
	for (int E = head[cur]; E; E = enxt[E])
		if (Dist[e[E]] > dist + 1)
			dfs(e[E], color, dist + 1, cur);
}

int lca(int u, int v)
{
	if (Dist[u] > Dist[v]) swap(u, v);
	while (Dist[u] != Dist[v])
		v = Ance[v][__builtin_ctz(Dist[v] - Dist[u])];
	if (u == v) return u;
	for (int lv = 31 - __builtin_clz(Dist[u]); lv >= 0; lv--)
		if (Ance[u][lv] != Ance[v][lv])
			{
				u = Ance[u][lv];
				v = Ance[v][lv];
			}
	return Father[u];
}

void MakeDistance()
{
	int i;
	fortodo(i, 0, 12) Ance[0][i] = 0;
	fortodo(i, 1, N) Dist[i] = 2333333;
	for (vector<int>::iterator it = Loop.begin(); it != Loop.end(); it++)
		Dist[*it] = 0;
	for (vector<int>::iterator it = Loop.begin(); it != Loop.end(); it++)
		dfs(*it, *it, 0, 0);
}

int main()
{
	scanf("%d", &N);
	int i, j;
	fortodo(i, 1, N) head[i] = 0; ec = 0;
	fortodo(i, 1, N)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			regi(u + 1, v + 1); regi(v + 1, u + 1);
		}
	fortodo(i, 1, N) visId[i] = -1;
	stk.clear();
	FindLoop(1, 0);
	fortodo(i, 1, N) LoopAddress[i] = -1;
	fortodo(i, 0, Loop.size() - 1)
		LoopAddress[Loop[i]] = i;
	MakeDistance();
	double Ans = 0;
	fortodo(i, 1, N)
		fortodo(j, 1, N)
			if (Color[i] == Color[j])
				Ans += 1.0 / (Dist[i] + Dist[j] - 2 * Dist[lca(i, j)] + 1);
			else
				{
					int MS, B1, B2;
					MS = Dist[i] + Dist[j] + 2;
					B1 = abs(LoopAddress[Color[i]] - LoopAddress[Color[j]]) - 1;
					B2 = Loop.size() - 2 - B1;
					Ans += 1.0 / (MS + B1);
					Ans += 1.0 / (MS + B2);
					Ans -= 1.0 / (MS + B1 + B2);
				}
	printf("%.14f\n", Ans);
}