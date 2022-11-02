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

int N,K;
int sum[4005][4005],W[4005][4005],dp[4005][4005],a[4005][4005];

void doit(int s,int L,int R,int opl,int opr)
{
	if (L>R) return;
	int M=(L+R)/2;
	int k=opl;
	for (int i=opl;i<=min(M-1,opr);i++)
		if (dp[s-1][i]+W[i+1][M]<dp[s][M])
		{
			dp[s][M]=dp[s-1][i]+W[i+1][M];
			k=i;
		}
	if (L==R) return;
	doit(s,L,M-1,opl,k);
	doit(s,M+1,R,k,opr);
}

int getnumber()
{
	char ch;
	int cs=0;
	while (true)
	{
		ch=getchar();
		if ((ch>='0')&&(ch<='9'))
		{
			cs=ch-48;
			break;
		}
	}
	while (true)
	{
		ch=getchar();
		if ((ch<'0')||(ch>'9')) break;
		cs*=10,cs+=ch-48;
	}
	return cs;
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d %d",&N,&K);
	for (int i=1;i<=N;i++)
	{
		sum[i][0]=0;
		for (int j=1;j<=N;j++)
		{
			a[i][j]=getnumber();
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	memset(W,0,sizeof(W));
	for (int i=1;i<=N;i++)
	{
		W[i][i]=0;
		for (int j=i+1;j<=N;j++)
			W[i][j]=W[i][j-1]+(sum[j][j]-sum[j][i-1]);
	}
	for (int i=0;i<=K;i++)
		for (int j=0;j<=N;j++)
			dp[i][j]=maxlongint/2;
	for (int i=1;i<=N;i++) dp[1][i]=W[1][i];
	for (int i=2;i<=K;i++)
		doit(i,1,N,1,N);

	printf("%d\n",dp[K][N]);
    return 0;
}