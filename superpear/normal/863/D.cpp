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

int N, Q, M;
int a[maxn], b[105], t[maxn], l[maxn], r[maxn];

int main()
{
	scanf("%d %d %d", &N, &Q, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= Q; i++) scanf("%d %d %d", &t[i], &l[i], &r[i]);
	for (int i = 1; i <= M; i++) scanf("%d", &b[i]);
	for (int i = Q; i >= 1; i--)
	{
		if (t[i] == 1)
		{
			// Rotate
			for (int j = 1; j <= M; j++)
			{
				if (b[j] == l[i]) b[j] = r[i]; else
				if ((b[j] > l[i]) && (b[j] <= r[i])) --b[j];
			}
		}
		else
		{
			// Reverse
			for (int j = 1; j <= M; j++)
				if ((b[j] >= l[i]) && (b[j] <= r[i]))
					b[j] = l[i] + r[i] - b[j];
		}
	}
	for (int i = 1; i <= M; i++) printf("%d ", a[b[i]]); printf("\n");

	return 0;
}