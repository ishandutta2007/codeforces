#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
int n,m,k;
long long minn=0x3f3f3f3f3f3f3f3fll;
struct atom
{
	int d,p,c;
	inline bool operator<(const atom &x)const{return d<x.d;}
}starta[100010],enda[100010];
int tops,tope;
long long startt[1000010],endt[1000010];
int flag[100010];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int d,s,t,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&d,&s,&t,&c);
		if(s==0)
		{
			enda[tope].d=d;
			enda[tope].p=t;
			enda[tope].c=c;
			tope++;
		}
		else
		{
			starta[tops].d=d;
			starta[tops].p=s;
			starta[tops].c=c;
			tops++;
		}
	}
	sort(starta,starta+tops);sort(enda,enda+tope);
	memset(flag,-1,sizeof(flag));
	memset(startt,-1,sizeof(startt));
	int last=0,cnt=0,ok=0;
	long long sum=0;
	for(int i=0;i<tops;i++)
	{
		if(ok)
			for(int k=last;k<starta[i].d;k++)
				startt[k]=sum;
		int ct=starta[i].p;
		if(flag[ct]==-1)sum+=(flag[ct]=starta[i].c),++cnt;
		else if(starta[i].c<flag[ct])sum-=(flag[ct]-starta[i].c),flag[ct]=starta[i].c;
		if(cnt==n)
			ok=1;
		last=starta[i].d;
	}
	if(ok)for(int k=last;k<=1000000;k++)startt[k]=sum;
	memset(flag,-1,sizeof(flag));
	memset(endt,-1,sizeof(endt));
	last=1000000;
	ok=cnt=sum=0;
	for(int i=tope-1;i>=0;i--)
	{
		if(ok)
			for(int k=last;k>enda[i].d;k--)
				endt[k]=sum;
		int ct=enda[i].p;
		if(flag[ct]==-1)sum+=(flag[ct]=enda[i].c),++cnt;
		else if(enda[i].c<flag[ct])sum-=(flag[ct]-enda[i].c),flag[ct]=enda[i].c;
		if(cnt==n)
			ok=1;
		last=enda[i].d;
	}
	if(ok)for(int k=last;k>=0;k--)endt[k]=sum;
	for(int i=0;i+k+1<=1000000;i++)
	{
		//cout<<startt[i]<<' '<<endt[i]<<endl;
		if(startt[i]!=-1&&endt[i+k+1]!=-1&&startt[i]+endt[i+k+1]<minn)
		{
			minn=startt[i]+endt[i+k+1];
		}
	}
	if(minn==0x3f3f3f3f3f3f3f3fll)
		minn=-1;
	printf("%I64d\n",minn);
	return 0;
}