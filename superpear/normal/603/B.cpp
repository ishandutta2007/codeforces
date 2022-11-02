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

int P,K,ans,ic;
int use[1000005];

int main()
{
	scanf("%d %d",&P,&K);
	if (K==0)
	{
		ans=1;
		for (int i=1;i<P;i++) ans=(LL)ans*P%bigp;
		printf("%d\n",ans);
		return 0;
	}
	if (K==1)
	{
		ans=1;
		for (int i=0;i<P;i++) ans=(LL)ans*P%bigp;
		printf("%d\n",ans);
		return 0;
	}
	ans=1;
	memset(use,0,sizeof(use));
	for (int i=1;i<P;i++)
		if (use[i]==0)
		{
			ans=(LL)ans*P%bigp;
			use[i]=1;
			ic=(LL)i*K%P;
			while (ic!=i) use[ic]=1,ic=(LL)ic*K%P;
		}
	printf("%d\n",ans);

    return 0;
}