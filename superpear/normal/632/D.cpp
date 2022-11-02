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

const int maxn=1000005;

int N,M,maxc,er,a[maxn],sm[maxn],ss[maxn];

int main()
{
	scanf("%d %d",&N,&M);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	
	memset(sm,0,sizeof(sm));
	for (int i=1;i<=N;i++) 
		if (a[i]<=M) sm[a[i]]++;
	memset(ss,0,sizeof(ss));
	for (int i=1;i<maxn;i++)
		for (int j=i;j<maxn;j+=i)
			ss[j]+=sm[i];
	
	maxc=1;
	for (int i=2;i<=M;i++)
		if (ss[i]>ss[maxc]) maxc=i;
	er=0;
	for (int i=1;i<=N;i++)
		if (maxc%a[i]==0) ++er;
	printf("%d %d\n",maxc,er);
	for (int i=1;i<=N;i++)
		if (maxc%a[i]==0) printf("%d ",i);
	printf("\n");
		
	return 0;
}