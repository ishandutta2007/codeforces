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

//-----------------------------------------------------------------------
// TEMPLATE BEGIN HERE

typedef int flow_size_type;
const int MAXFN = 220;
const int MAXFE = 3000;
const flow_size_type INF = 0x3FFFFFFF;

int NS, NE, NC, S, T;
int head[MAXFN], e[MAXFE], enxt[MAXFE], ec;
flow_size_type cp[MAXFE];
int tag[MAXFN], lyr[MAXFN], Nid, cur[MAXFN], pre[MAXFN], prn[MAXFN];
flow_size_type supp[MAXFN], comp[MAXFN], ans;
bool Gap; 

void regi(int u, int v, flow_size_type w)
{
	ec++;
	e[ec] = v; cp[ec] = w;
	enxt[ec] = head[u]; head[u] = ec;
}

void directed(int u, int v, flow_size_type w)
{
	regi(u, v, w);
	regi(v, u, 0);
}

void undirected(int u, int v, flow_size_type w)
{
	regi(u, v, w);
	regi(v, u, w);
}

void sap_graph_init()
{
	NC = NE - NS + 1;
	ec = 0;
	int i;
	fortodo(i, NS, NE) head[i] = 0; 
}

void push(int Eid, flow_size_type fs)
{
	cp[Eid] -= fs;
	cp[((Eid - 1) ^ 1) + 1] += fs;
}

void relabel(int x)
{
	int ol = tag[x];
	int nl = NC;
	for (int E = head[x]; E; E = enxt[E])
		if ((cp[E]) && (tag[x] <= tag[e[E]] + 1))
			nl = min(nl, tag[e[E]] + 1);
	lyr[nl]++; lyr[ol]--; tag[x] = nl;
	Gap |= (lyr[ol] == 0);
	cur[x] = head[x];
}

void sap_initialize()
{
	int i;
	fortodo(i, NS, NE)
		{
			tag[i] = lyr[i] = 0;
			cur[i] = head[i];
		}
	lyr[0] = NC;
	Nid = S; Gap = false;
	supp[Nid] = INF; comp[Nid] = 0;
}

flow_size_type sap()
{
	flow_size_type ans = 0;
	while ((tag[S] != NC) && (!Gap))
		{
			if (Nid == T)
				{
					flow_size_type increment = supp[Nid] - comp[Nid];
					ans += increment;
					for (int x = T; x != S; x = prn[x])
						{
							comp[x] += increment;
							push(pre[x], increment);
						}
				}
			bool Aug = false;
			if (supp[Nid] > comp[Nid])
				for (; cur[Nid]; cur[Nid] = enxt[cur[Nid]])
					{
						int E = cur[Nid];
						if ((cp[E]) && (tag[Nid] == tag[e[E]] + 1))
							{
								Aug = true;
								supp[e[E]] = min(cp[E], supp[Nid] - comp[Nid]);
								comp[e[E]] = 0;
								prn[e[E]] = Nid;
								pre[e[E]] = E;
								Nid = e[E];
								break;
							}
					}
			if (!Aug)
				{
					if (Nid != T) relabel(Nid);
					if (Nid == S)
						comp[Nid] = 0;
					else
						Nid = prn[Nid];
				}
		}
	return ans;
}

// TEMPLATE END HERE
//-----------------------------------------------------------------------

#include<bitset>
#include<vector>
#include<queue>

const int MAXN = 210;
const int MAXM = 1010;

typedef bitset<MAXN> Bitset;

int N, M;
int A[MAXM], B[MAXM], C[MAXM];

int Cut(int s, int t)
{
	NS = 1; NE = N;
	S = s; T = t;
	sap_graph_init();
	int i;
	fortodo(i, 1, M)
		undirected(A[i], B[i], C[i]);
	sap_initialize();
	return sap();
}

int P[MAXN], Q[MAXN], W[MAXN], P0;

Bitset G;

Bitset BFS(int src)
{
	Bitset ret;
	queue<int> Q;
	ret.reset();
	while (Q.size()) Q.pop();
	Q.push(src); ret.set(src);
	while (Q.size())
		{
			int u = Q.front(); Q.pop();
			for (int E = head[u]; E; E = enxt[E])
				if ((cp[E]) && (!ret.test(e[E])))
					{
						ret.set(e[E]);
						Q.push(e[E]);
					}
		}
	return ret;
}

void Run()
{
	if (G.count() == 1) return;
	Bitset tmpG = G;
	vector<int> list;
	list.clear();
	int i;
	fortodo(i, 1, N) if (G.test(i)) list.push_back(i);
	P0++;
	P[P0] = list[0];
	Q[P0] = list[1];
	W[P0] = Cut(P[P0], Q[P0]);
	Bitset HAHA = BFS(P[P0]);
	G = tmpG & HAHA;
	Run();
	G = tmpG & ~HAHA;
	Run();
}

vector<int> Route[MAXN];

int F[MAXN];

int Find(int x)
{
	return F[x] = ((F[x] == x) ? x : Find(F[x]));
}

int SEQ[MAXN];

bool cmp_Waz(int a, int b)
{
	return W[a] < W[b];
}

int main()
{
	scanf("%d%d", &N, &M);
	int i;
	fortodo(i, 1, M)
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
	P0 = 0;
	G.reset();
	fortodo(i, 1, N) G.set(i);
	Run();
	int ans = 0;
	fortodo(i, 1, N - 1)
		ans += W[i];
	printf("%d\n", ans);
	fortodo(i, 1, N)
		{
			F[i] = i;
			Route[i].clear();
			Route[i].push_back(i);
		}
	fortodo(i, 1, N - 1) SEQ[i] = i;
	sort(SEQ + 1, SEQ + N, cmp_Waz);
	for (i = N - 1; i; i--)
		{
			int u = SEQ[i];
			int p = Find(P[u]), q = Find(Q[u]);
			Route[p].insert(Route[p].end(), Route[q].begin(), Route[q].end());
			F[q] = p;
		} 
	fortodo(i, 1, N)
		printf("%d%s", Route[1][i - 1], (i == N) ? "\n" : " ");
}