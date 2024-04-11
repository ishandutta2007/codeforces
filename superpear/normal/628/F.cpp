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

int N,B,Q,flag;
int sum[5][10005],up[10005],nm[10005];
PII ls[10005];

int main()
{
	//freopen("F.in","r",stdin);

	scanf("%d %d %d",&N,&B,&Q);
	memset(sum,0,sizeof(sum));
	for (int i=0;i<=4;i++)
		for (int j=1;j<=B;j++)
			if (j%5==i) sum[i][j]=sum[i][j-1]+1; else sum[i][j]=sum[i][j-1];
	up[0]=nm[0]=0;
	for (int i=1;i<=Q;i++)
	{
		scanf("%d %d",&up[i],&nm[i]);
		ls[i]=m_p(up[i],nm[i]);
	}
	++Q;
	ls[Q]=m_p(B,N);
	sort(ls+1,ls+Q+1);
	for (int i=1;i<=Q;i++) up[i]=ls[i].w1,nm[i]=ls[i].w2;

	flag=1;
	for (int i=0;i<=31;i++)
	{
		int et=0;
		for (int j=1;j<=Q;j++)
		{
			if (nm[j]<nm[j-1])
			{
				flag=0;
				break;
			}
			int sm=0;
			for (int k=0;k<=4;k++)
				if ((i>>k)%2==1) sm+=sum[k][up[j]]-sum[k][up[j-1]];
			et+=min(sm,nm[j]-nm[j-1]);
		}
		int ee=0;
		for (int k=0;k<=4;k++) ee+=((i>>k)%2);
		//cout<<ee<<" "<<et<<endl;
		if (et<(N/5*ee))
		{
			flag=0;
			break;
		}
	}
	if (flag==1) cout<<"fair"<<endl; else cout<<"unfair"<<endl;

	return 0;
}