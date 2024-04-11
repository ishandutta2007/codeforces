#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<double, double> PDD;

const int maxlongint = 2147483647;
const int biglongint = 2139062143;

#define LL long long
#define ULL unsigned long long
#define w1 first
#define w2 second
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

const int maxn = 800005;

int N;
int l[maxn], r[maxn], sm1[maxn], sm2[maxn];

int main()
{
	//freopen("E.in", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d", &l[i], &r[i]);
	
	map<int, int> lsh;
	map<int, int>::iterator lsg, lsg2;
	lsh.clear();
	for (int i = 1; i <= N; i++)
		lsh[l[i]] = 1, lsh[r[i]] = 1;
	int tt = 0;
	for (lsg = lsh.begin(); lsg != lsh.end(); lsg2 = lsg, lsg++)
	{
		tt++;
		if (tt != 1)
			if (lsg2 -> w1 + 1 != lsg -> w1) tt++;
		lsg -> w2 = tt;
	}

	for (int i = 1; i <= N; i++) l[i] = lsh[l[i]], r[i] = lsh[r[i]];

	//for (int i = 1; i <= N; i++) printf("%d %d\n", l[i], r[i]);

	memset(sm1, 0, sizeof(sm1));
	memset(sm2, 0, sizeof(sm2));
	for (int i = 1; i <= N; i++)
		sm1[l[i]]++, sm1[r[i] + 1]--;
	for (int i = 1; i <= N * 4; i++)
		sm1[i] += sm1[i - 1];
	for (int i = 1; i <= N * 4; i++)
		if (sm1[i] == 1) sm2[i]++;
	for (int i = 1; i <= N * 4; i++)
		sm2[i] += sm2[i - 1];

	for (int i = 1; i <= N; i++)
		if (sm2[r[i]] == sm2[l[i] - 1])
		{
			printf("%d\n", i);
			return 0;
		}
	printf("-1\n");

	return 0;
}