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

struct RG
{
	int S, E, Id;
	RG() {}
	RG(int t)
	{
		S = E = t; Id = 0;
	} 
	RG(int s, int e, int id)
	{
		S = s; E = e; Id = id;
	}
};

#include<set>

bool operator < (RG L, RG R)
{
	return L.S < R.S;
}

int operator * (RG L, RG R)
{
	return max(0, min(R.E, L.E) - max(R.S, L.S));
}

set<RG> Sw;

const int MAXN = 100010;

int N, T;
int H[MAXN], X[MAXN], Y[MAXN], E[MAXN];
RG rg[MAXN];

bool cmp_Haz(int i, int j)
{
	return H[i] < H[j];
}

const int halfA = int(1e+9);

int dp[MAXN];

void splitAt(int x)
{
	set<RG>::iterator it = Sw.upper_bound(RG(x)); it--;
	RG rg = *it;
	if (rg.S == x) return;
	Sw.erase(it);
	Sw.insert(RG(rg.S, x, rg.Id));
	Sw.insert(RG(x, rg.E, rg.Id));
}

int main()
{
	scanf("%d%d", &N, &T);
	int i;
	fortodo(i, 1, N)
		{
			scanf("%d%d%d", &H[i], &X[i], &Y[i]);
			rg[i] = RG(X[i], Y[i], i);
		}
	rg[0] = RG(-halfA - 1, halfA + 1, 0); H[0] = 0;
	rg[N + 1] = RG(X[N + 1] = -halfA, Y[N + 1] = halfA, N + 1); H[N + 1] = T;
	fortodo(i, 0, N + 1) E[i] = i;
	sort(E, E + N + 2, cmp_Haz);
	Sw.clear();
	Sw.insert(rg[0]);
	dp[0] = rg[0] * rg[0];
	fortodo(i, 1, N + 1)
		{
			int u = E[i];
			dp[u] = 0;
			splitAt(X[u]);
			splitAt(Y[u]);
			for (set<RG>::iterator it = Sw.lower_bound(RG(X[u])); it->S < Y[u]; it++)
				if (((*it) * rg[u]) == (rg[it->Id] * rg[u]))
					dp[u] = max(dp[u], min(dp[it->Id], rg[it->Id] * rg[u]));
			Sw.erase(Sw.lower_bound(RG(X[u])), Sw.lower_bound(RG(Y[u])));
			Sw.insert(rg[u]);
		}
	printf("%d\n", dp[N + 1]);
}