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

const int VERYBIG = 314000000;
const int INF = VERYBIG + 1;

const int MAXN = 100010;
const int MAXM = 100010;
const int TUNVISITED = 0;
const int TVISITING = 1;
const int TVISITED = 2;

int N, M;

#include<vector>
#include<set>
vector<int> DEPOS[MAXM];
int RID[MAXM], CDIA[MAXM];
int minsdia[MAXN], cntpend[MAXM], cntnowsum[MAXM];
vector<int> OCCUR[MAXN], WAYS[MAXN];

set<pair<int,int> > SPII;

int maxsdia[MAXN];
int Statu[MAXN];

void DFS(int x)
{
	maxsdia[x] = 0;
	Statu[x] = TVISITING;
	for (vector<int>::iterator it = WAYS[x].begin(); it != WAYS[x].end(); it++)
		{
			int S = CDIA[*it];
			bool REMOVED = false;
			for (vector<int>::iterator iit = DEPOS[*it].begin(); iit != DEPOS[*it].end(); iit++)
				{
					if (minsdia[*iit] == INF)
						{
							REMOVED = true;
							break;
						}
					if (Statu[*iit] == TVISITING)
						S = INF;
					else
						{
							if (Statu[*iit] == TUNVISITED)
								DFS(*iit);
							if ((S == INF) || (maxsdia[*iit] == INF))
								S = INF;
							else
								S = min(VERYBIG, S + maxsdia[*iit]);
						}
				}
			if (!REMOVED)
				maxsdia[x] = max(maxsdia[x], S);
		}
	Statu[x] = TVISITED;
}

int main()
{
	scanf("%d%d", &M, &N);
	int i;
	fortodo(i, 1, M)
		{
			int u, l;
			scanf("%d%d", &u, &l);
			RID[i] = u; CDIA[i] = 0;
			DEPOS[i].clear();
			for (; l; l--)
				{
					int s;
					scanf("%d", &s);
					if (s == -1)
						CDIA[i]++;
					else
						DEPOS[i].push_back(s);
				}
		}
	fortodo(i, 1, N)
		minsdia[i] = INF;
	fortodo(i, 1, M)
		{
			cntpend[i] = DEPOS[i].size();
			cntnowsum[i] = CDIA[i];
			if (cntpend[i] == 0)
				minsdia[RID[i]] = min(minsdia[RID[i]], cntnowsum[i]);
		}
	SPII.clear();
	fortodo(i, 1, N)
		{
			OCCUR[i].clear();
			SPII.insert(make_pair(minsdia[i], i));
		}
	fortodo(i, 1, M)
		for (vector<int>::iterator it = DEPOS[i].begin(); it != DEPOS[i].end(); it++)
			OCCUR[*it].push_back(i);
	fortodo(i, 1, N)
		{
			pair<int,int> PII = *SPII.begin();
			SPII.erase(SPII.begin());
			if (PII.first == INF) break;
			for (vector<int>::iterator it = OCCUR[PII.second].begin(); it != OCCUR[PII.second].end(); it++)
				{
					cntpend[*it]--;
					cntnowsum[*it] = min(cntnowsum[*it] + PII.first, VERYBIG);
					if ((cntpend[*it] == 0) && (cntnowsum[*it] < minsdia[RID[*it]]))
						{
							SPII.erase(make_pair(minsdia[RID[*it]], RID[*it]));
							minsdia[RID[*it]] = cntnowsum[*it];
							SPII.insert(make_pair(minsdia[RID[*it]], RID[*it]));
						}
				}
		}
	fortodo(i, 1, N) WAYS[i].clear();
	fortodo(i, 1, M) WAYS[RID[i]].push_back(i);
	fortodo(i, 1, N) Statu[i] = TUNVISITED;
	fortodo(i, 1, N)
		if ((Statu[i] == TUNVISITED) && (minsdia[i] < INF))
			DFS(i);
	fortodo(i, 1, N)
		if (minsdia[i] == INF)
			printf("-1 -1\n");
		else
			if (maxsdia[i] == INF)
				printf("%d -2\n", minsdia[i]);
			else
				printf("%d %d\n", minsdia[i], maxsdia[i]);
}