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

const int Step=1000000;

int N,a[105];
double p[105];

int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	for (int i=1;i<=N;i++) p[i]=1;
	double ans=0,lastp=0;
	for (int i=1;i<=Step;i++)
	{
		double maxc=-1;
		int maxk=0;
		for (int j=1;j<=N;j++)
		{
			double cc=(1-p[j]*(1-double(a[j])/100))/(1-p[j]);
			if (cc>maxc) maxc=cc,maxk=j;
		}
		p[maxk]*=1-double(a[maxk])/100;
		double nowp=1;
		for (int j=1;j<=N;j++)
			nowp*=(1-p[j]);
		ans+=(nowp-lastp)*i;
		lastp=nowp;
	}
	printf("%.10f\n",ans);

	return 0;
}