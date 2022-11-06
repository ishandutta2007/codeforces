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
#include<queue>

const int MAXN = 1010;
const int MAXM = 1010;

typedef pair<int,int> PII;
#define MP make_pair

int N, M, D;

char map[MAXN][MAXM];
vector<PII> allRats;

int lv[MAXN][MAXM];
int cnt[3];

PII anySpaceExcept(PII ths)
{
	int i, j;
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			if ((map[i][j] != 'X') && ((i != ths.first) || (j != ths.second)))
				return MP(i, j);
}

#define Y(x) (x).first][(x).second

bool vis[MAXN][MAXM];
int dist[MAXN][MAXM];
vector<PII> everIn;
queue<PII> Q;

inline PII operator + (PII lhs, PII rhs)
{
	return MP(lhs.first + rhs.first, lhs.second + rhs.second);
}

const PII dl[4] = {MP(1, 0), MP(-1, 0), MP(0, 1), MP(0, -1)};

void dBFS(PII src, int offset)
{
	everIn.clear();
	while (Q.size()) Q.pop();
	Q.push(src);
	vis[Y(src)] = true;
	dist[Y(src)] = 0;
	while (Q.size())
		{
			PII u = Q.front();
			everIn.push_back(u);
			Q.pop();
			if (map[Y(u)] == 'R') cnt[lv[Y(u)]]--;
			lv[Y(u)] += offset;
			if (map[Y(u)] == 'R') cnt[lv[Y(u)]]++;
			if (dist[Y(u)] == D) continue;
			for (int r = 0; r < 4; r++)
				if ((map[Y(u + dl[r])] != 'X') && (!vis[Y(u + dl[r])]))
					{
						vis[Y(u + dl[r])] = true;
						Q.push(u + dl[r]);
						dist[Y(u + dl[r])] = dist[Y(u)] + 1;
					}
		}
	for (vector<PII>::iterator it = everIn.begin(); it != everIn.end(); it++)
		vis[Y(*it)] = false;
}

vector<PII> firstCanditate, secondCanditate;

PII anyUndestroyedRat()
{
	for (vector<PII>::iterator it = allRats.begin(); it != allRats.end(); it++)
		if (lv[Y(*it)] == 0)
			return *it;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d", &N, &M, &D);
	int i, j;
	fortodo(i, 1, N)
		scanf("%s", map[i] + 1);
	allRats.clear();
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			if (map[i][j] == 'R')
				{
					allRats.push_back(MP(i, j));
					cnt[0]++;
				}
	PII firstRat = allRats[0];
	dBFS(firstRat, 0);
	firstCanditate = everIn;
	for (vector<PII>::iterator pfirst = firstCanditate.begin(); pfirst != firstCanditate.end(); pfirst++)
		{
			dBFS(*pfirst, 1);
			if (cnt[0] == 0)
				{
					PII snd = anySpaceExcept(*pfirst);
					printf("%d %d %d %d\n", pfirst->first, pfirst->second, snd.first, snd.second);
					return 0;
				}
			PII undestroyed = anyUndestroyedRat();
			dBFS(undestroyed, 0);
			secondCanditate = everIn;
			for (vector<PII>::iterator psecond = secondCanditate.begin(); psecond != secondCanditate.end(); psecond++)
				{
					dBFS(*psecond, 1);
					if (cnt[0] == 0)
						{
							printf("%d %d %d %d\n", pfirst->first, pfirst->second, psecond->first, psecond->second);
							return 0;
						}
					dBFS(*psecond,-1);
				}
			dBFS(*pfirst,-1);
		}
	printf("-1\n");
}