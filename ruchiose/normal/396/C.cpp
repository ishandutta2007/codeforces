#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, P[300010], snr[300010], sib[300010];
int dep[300010], f[300010], c[300010], stamp;

const int MOD = 1000000007;
#define pii pair<int,int>
#define mp make_pair
inline int modplus(int a, int b) {return (a + b) % MOD;}
inline int modmulti(i64 a, int b){return int((a * b) % MOD);}

pii operator + (pii fir, pii snd)
{return mp(modplus(fir.first, snd.first), modplus(fir.second, snd.second));}

pii v[300010];

void att(int x, pii d)
{
	for (; x <= N; x += x & (-x)) v[x] = v[x] + d;
}

pii qry(int x)
{
	pii r = mp(0, 0);
	for (; x; x -= x & (-x)) r = r + v[x];
	return r;
}

int Orz, Xu, Yin, Zhan;

void DFS(int Nid)
{
	f[Nid] = ++stamp;
	for (int i = snr[Nid]; i; i = sib[i]) DFS(i);
	c[Nid] = stamp;
}

int main()
{
	scanf("%d", &N);
	fortodo(i, 2, N) scanf("%d", &P[i]);
	dep[1] = 0;
	fortodo(i, 2, N) dep[i] = dep[P[i]] + 1;
	fortodo(i, 1, N) snr[i] = 0;
	fortodo(i, 2, N)
		{
			sib[i] = snr[P[i]];
			snr[P[i]] = i;
		}
	stamp = 0;
	DFS(1);
	fortodo(i, 1, N) v[i] = mp(0, 0);
	scanf("%d", &M);
	fortodo(i, 1, M)
		{
			scanf("%d", &Orz);
			if (Orz == 1)
				{
					scanf("%d%d%d", &Xu, &Yin, &Zhan); swap(Xu, Yin);
					pii u = mp(modplus(Xu, modmulti(dep[Yin], Zhan)), (Zhan) ? (MOD - Zhan) : 0);
					att(f[Yin], u);
					att(c[Yin] + 1, mp((u.first) ? (MOD - u.first) : 0, (u.second) ? (MOD - u.second) : 0));
				}
			else
				{
					scanf("%d", &Xu);
					pii q = qry(f[Xu]);
					printf("%d\n", modplus(q.first, modmulti(dep[Xu], q.second)));
				}
		}
}