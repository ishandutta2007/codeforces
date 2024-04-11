#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int bigp=1000000007;
const int maxn=1005;

int N;
int a[maxn];
int F[10][maxn][maxn / 8 + 5];
int dp[maxn][260];

int main()
{
//	freopen("E.in", "r", stdin);
	scanf("%d", &N);
	int Maxk = N / 8;
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	memset(F, -1, sizeof(F));
	// F[i][j][k] indicates that if we count number i from position j for k times,
	// where will we end up at
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= N; j++)
		{
			F[i][j][0] = j;
			int cnt = 0;
			for (int k = j; k <= N; k++)
				if (a[k] == i)
				{
					++cnt;
					F[i][j][cnt] = k + 1;
				}
		}

	int Ans = 0;
	for (int ans = 0; ans <= Maxk; ans++)
    {
		memset(dp, -1, sizeof(dp));
		// dp[i][j] indicates that if we have used first i - 1 numbers with pattern j,
		// what's the maximum length we get
		dp[1][0] = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j <= 255; j++)
			{
				if (dp[i][j] == -1) continue;
				for (int k = 1; k <= 8; k++)
					if ((j >> (k - 1)) % 2 == 0)
					{
						int jc = j | (1 << (k - 1));
						// check the case of ans
						if (F[k][i][ans] != -1)
							dp[F[k][i][ans]][jc] = max(dp[F[k][i][ans]][jc], dp[i][j] + ans);
						// check the case of ans + 1
						if (F[k][i][ans + 1] != -1)
							dp[F[k][i][ans + 1]][jc] = max(dp[F[k][i][ans + 1]][jc], dp[i][j] + ans + 1);

					}
			}
		for (int i = 1; i <= N + 1; i++)
			Ans = max(Ans, dp[i][255]);
    }
    cout << Ans << endl;

	return 0;
}