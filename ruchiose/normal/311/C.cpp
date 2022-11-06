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
#include<set>

typedef pair<int,int> PII;
const int MAXN = 100010;

i64 H;
int N, M;
vector<i64> K;
i64 A[MAXN];
int C[MAXN];

struct cmp_PII
{
	bool operator () (PII lhs, PII rhs)
	{
		return (lhs.first != rhs.first) ? (lhs.first > rhs.first) : (lhs.second < rhs.second); 
	}
};

const i64 BigLL = ((i64)(1e+18) + 1);

set<PII,cmp_PII> tList;
i64 ig[10010];
#include<queue>
bool inq[10010];
queue<int> Q;

void maketList()
{
	sort(K.begin(), K.end());
	int i;
	fortodo(i, 0, K[0] - 1)
		{
			inq[i] = false;
			ig[i] = BigLL;
		}
	while (Q.size()) Q.pop();
	Q.push(1 % K[0]);
	ig[1 % K[0]] = 1;
	inq[1 % K[0]] = true;
	while (Q.size())
		{
			int g = Q.front(); Q.pop();
			inq[g] = false;
			for (vector<i64>::iterator it = K.begin() + 1; it != K.end(); it++)
				if (ig[(ig[g] + *it) % K[0]] > ig[g] + *it)
					{
						ig[(ig[g] + *it) % K[0]] = ig[g] + *it;
						if (!inq[(ig[g] + *it) % K[0]])
							{
								inq[(ig[g] + *it) % K[0]] = true;
								Q.push((ig[g] + *it) % K[0]);
							}
					}
		}
	tList.clear();
	fortodo(i, 1, N)
		if (ig[A[i] % K[0]] <= A[i])
			tList.insert(make_pair(C[i], i));
}

void decreaseTreasure(int x, int v)
{
	if (ig[A[x] % K[0]] <= A[x]) tList.erase(make_pair(C[x], x));
	C[x] -= v;
	if (ig[A[x] % K[0]] <= A[x]) tList.insert(make_pair(C[x], x));
}

int main()
{
	int K0;
	scanf("%I64d%d%d%d", &H, &N, &M, &K0);
	K.clear(); K.push_back(K0);
	int i;
	fortodo(i, 1, N) scanf("%I64d%d", &A[i], &C[i]);
	maketList();
	fortodo(i, 1, M)
		{
			int t;
			scanf("%d", &t);
			if (t == 1)
				{
					i64 ki;
					scanf("%I64d", &ki);
					K.push_back(ki);
					maketList();
				}
			if (t == 2)
				{
					int id, delta;
					scanf("%d%d", &id, &delta);
					decreaseTreasure(id, delta);
				}
			if (t == 3)
				{
					if (tList.size() == 0)
						{
							printf("0\n");
							continue;
						}
					//for (set<PII,cmp_PII>::iterator it = tList.begin(); it == tList.begin(); it++);
					printf("%d\n", tList.begin()->first);
					decreaseTreasure(tList.begin()->second, tList.begin()->first);
				}
		}
}