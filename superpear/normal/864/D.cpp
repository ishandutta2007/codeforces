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

const int maxn = 200005;
int N, s, last, a[maxn], f[maxn], c[maxn];
deque<int> F[maxn];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
	{
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	s = 0;
	for (int i = 1; i <= N; i++)
		if (f[i] == 0) s++;
	printf("%d\n", s);

	memset(c, 0, sizeof(c));
	for (int i = 1; i <= N; i++)
		if (f[a[i]] != 1)
		{
			c[i] = 1;
			F[a[i]].push_back(i);
		}

	last = 0;
	for (int i = 1; i <= N; i++)
	{
		if (f[i] == 0)
		{
			for (int j = last + 1; j <= N; j++)
				if ((c[j] == 1) && (f[a[j]] > 1))
				{
					f[a[j]]--;
					F[a[j]].pop_front();
					a[j] = i;
					last = j;
					break;
				}
			continue;
		}
		if (f[i] > 1)
		{
			int cc = F[i][0];
			F[i].pop_front();
			c[cc] = 0;
		}
	}

	for (int i = 1; i < N; i++) printf("%d ", a[i]); printf("%d\n", a[N]);

	return 0;
}