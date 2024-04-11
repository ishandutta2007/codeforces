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

const int maxn=100005;

bool cmp(PII a,PII b)
{
	return a>b;
}

LL sum[maxn];
int N,A,Cf,Cm;
LL M;
int a[maxn];
PII ls[maxn];

int main()
{
	scanf("%d %d %d %d %I64d",&N,&A,&Cf,&Cm,&M);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		ls[i]=m_p(a[i],i);
	}
	sort(ls+1,ls+N+1,cmp);

	sum[0]=0;
	for (int i=1;i<=N;i++) sum[i]=sum[i-1]+ls[i].w1;

	LL ans=-1;
	int ansi,ansk;
	for (int i=0;i<=N;i++)
	{
		//set prefix 1~i to A
		LL now=(LL)A*i-sum[i];
		if (now>M) continue;
		int left=1,right=A,mid;
		while (left<=right)
		{
			mid=(left+right)/2;
			int ll=i+1,rr=N,mm;
			while (ll<=rr)
			{
				mm=(ll+rr)/2;
				if (ls[mm].w1<=mid) rr=mm-1; else ll=mm+1;
			}
			LL nk=(LL)mid*(N-ll+1)-(sum[N]-sum[ll-1]);
			if (nk+now<=M) left=mid+1; else right=mid-1;
		}
		LL lss=(LL)right*Cm+(LL)i*Cf;
		if (lss>ans) ans=lss,ansi=i,ansk=right;
	}
	printf("%I64d\n",ans);
	for (int i=1;i<=N;i++)
		if (i<=ansi) a[ls[i].w2]=A;
	for (int i=1;i<=N;i++)
		if (a[i]<ansk) a[i]=ansk;
	for (int i=1;i<N;i++) printf("%d ",a[i]); printf("%d\n",a[N]);

    return 0;
}