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

/*
#include<map>
map<int,int> SG;
*/

const int SGtab[102 * 2 + 2] = 
{
1,0,
3,1,
4,2,
5,1,
7,2,
9,0,
13,1,
15,2,
19,0,
27,1,
39,2,
40,0,
57,2,
58,1,
81,2,
85,0,
120,2,
121,1,
174,2,
179,0,
255,2,
260,1,
363,2,
382,0,
537,2,
544,1,
780,2,
805,0,
1146,2,
1169,1,
1632,2,
1718,0,
2415,2,
2447,1,
3507,2,
3622,0,
5154,2,
5260,1,
7341,2,
7730,0,
10866,2,
11011,1,
15780,2,
16298,0,
23190,2,
23669,1,
33033,2,
34784,0,
48894,2,
49549,1,
71007,2,
73340,0,
104352,2,
106510,1,
148647,2,
156527,0,
220020,2,
222970,1,
319530,2,
330029,0,
469581,2,
479294,1,
668910,2,
704371,0,
990087,2,
1003364,1,
1437882,2,
1485130,0,
2113113,2,
2156822,1,
3010092,2,
3169669,0,
4455390,2,
4515137,1,
6470466,2,
6683084,0,
9509007,2,
9705698,1,
13545411,2,
14263510,0,
20049252,2,
20318116,1,
29117094,2,
30073877,0,
42790530,2,
43675640,1,
60954348,2,
64185794,0,
90221631,2,
91431521,1,
131026920,2,
135332446,0,
192557382,2,
196540379,1,
274294563,2,
288836072,0,
405997338,2,
411441844,1,
589621137,2,
608996006,0,
866508216,2,
884431705,1,
1000000001,-1
};

const i64 MOD = int(1e+9) + 7;

void LEG(i64 &x)
{
	x %= MOD;
	x += MOD;
	x %= MOD;
}

int N, P;

i64 tria(i64 x)
{
	i64 ret = (x * P) - (x * (x + 1) / 2);
	LEG(ret);
	return ret;
}

int main()
{
	/*
	SG.clear();
	SG.insert(make_pair(1, 0));
	int i;
	fortodo(i, 3, 1000000000)
		{
			int Q[2];
			Q[0] = (--SG.upper_bound(i / 3))->second;
			Q[1] = (--SG.upper_bound(i - i / 3))->second;
			if (Q[0] > Q[1]) swap(Q[0], Q[1]);
			int oldSG = (--SG.end())->second;
			int newSG = (Q[0] == 0) ? ((Q[1] == 1) ? 2 : 1) : 0;
			if (oldSG != newSG) SG.insert(make_pair(i, newSG));
		}
	for (map<int,int>::iterator it = SG.begin(); it != SG.end(); it++)
		printf("%d %d\n", it->first, it->second);
	*/
	scanf("%d%d", &N, &P);
	int it = 0;
	i64 cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	int i, j, k;
	fortodo(i, 0, 101)
		if (SGtab[i * 2] <= P)
			LEG(cnt[SGtab[i * 2 + 1]] += tria(min(P, SGtab[i * 2 + 2] - 1)) - tria(SGtab[i * 2] - 1));
	i64 dp[1010][4];
	fortodo(i, 0, N)
		fortodo(j, 0, 3)
			dp[i][j] = 0;
	dp[0][0] = 1;
	fortodo(i, 0, N - 1)
		fortodo(j, 0, 3)
			fortodo(k, 0, 2)
				LEG(dp[i + 1][j ^ k] += (dp[i][j] * cnt[k]));
	i64 ans = (dp[N][1] + dp[N][2] + dp[N][3]) % MOD;
	cout << ans << endl;
}