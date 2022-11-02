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

int N,x[maxn],y[maxn],maxyL[maxn],maxyR[maxn],minyL[maxn],minyR[maxn];
PII ls[maxn];

bool check(LL rad)
{
	int ee=0;
	for (int i=1;i<=N;i++)
	{
		while ((ee<N)&&((LL)(x[ee+1]-x[i])*(x[ee+1]-x[i])<=rad)) ++ee;
		int X0=x[i],X1=x[ee];
		int Y0=min(minyL[i-1],minyR[ee+1]);
		int Y1=max(maxyL[i-1],maxyR[ee+1]);
		//cout<<i<<" "<<ee<<" "<<X0<<" "<<X1<<" "<<Y0<<" "<<Y1<<endl;
		if (Y0==maxlongint) return true;
		if ((LL)(Y0-Y1)*(Y0-Y1)<=rad)
		{
			int X2=max(abs(X0),abs(X1));
			int Y2=max(abs(Y0),abs(Y1));
			if ((LL)X2*X2+(LL)Y2*Y2<=rad) return true;
		}
	}
	int e1=N,e2=0;
	for (int i=1;i<=N;i++)
	{
		if (x[i]<=0)
		{
			while ((e1>0)&&(x[e1]>(-x[i]))) --e1;
			while ((e2<N)&&((LL)(x[e2+1]-x[i])*(x[e2+1]-x[i])<=rad)) ++e2;
		}
		else break;
		ee=min(e1,e2);
		int Y0=min(minyL[i-1],minyR[ee+1]);
		int Y1=max(maxyL[i-1],maxyR[ee+1]);
		if (Y0==maxlongint) return true;
		if ((LL)(Y0-Y1)*(Y0-Y1)<=rad)
		{
			int X2=x[i];
			int Y2=max(abs(Y0),abs(Y1));
			if ((LL)X2*X2+(LL)Y2*Y2<=rad) return true;
		}
	}
	e1=1,e2=N+1;
	for (int i=N;i>=1;i--)
	{
		if (x[i]>0)
		{
			while ((e1<=N)&&((-x[e1])>x[i])) ++e1;
			while ((e2>0)&&((LL)(x[e2-1]-x[i])*(x[e2-1]-x[i])<=rad)) --e2;
		}
		else break;
		ee=max(e1,e2);
		int Y0=min(minyL[ee-1],minyR[i+1]);
		int Y1=max(maxyL[ee-1],maxyR[i+1]);
		if (Y0==maxlongint) return true;
		if ((LL)(Y0-Y1)*(Y0-Y1)<=rad)
		{
			int X2=x[i];
			int Y2=max(abs(Y0),abs(Y1));
			if ((LL)X2*X2+(LL)Y2*Y2<=rad) return true;
		}
	}
	return false;
}

int main()
{
	// freopen("C.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d %d",&x[i],&y[i]);
	for (int i=1;i<=N;i++) ls[i]=m_p(x[i],y[i]);
	sort(ls+1,ls+N+1);
	for (int i=1;i<=N;i++) x[i]=ls[i].w1,y[i]=ls[i].w2;
	maxyL[0]=-maxlongint,minyL[0]=maxlongint;
	for (int i=1;i<=N;i++)
		maxyL[i]=max(maxyL[i-1],y[i]),
		minyL[i]=min(minyL[i-1],y[i]);
	maxyR[N+1]=-maxlongint,minyR[N+1]=maxlongint;
	for (int i=N;i>=1;i--)
		maxyR[i]=max(maxyR[i+1],y[i]),
		minyR[i]=min(minyR[i+1],y[i]);

	LL left=0,right=1000000000000000000LL,mid;
	while (left<=right)
	{
		mid=(left+right)/2;
		if (check(mid)) right=mid-1; else left=mid+1;
	}
	LL ans=left;
	int y0=-maxlongint,y1=maxlongint;
	for (int i=1;i<=N;i++)
		y0=max(y0,y[i]),
		y1=min(y1,y[i]);
	ans=min(ans,(LL)(y0-y1)*(y0-y1));
	printf("%I64d\n",ans);

	return 0;
}