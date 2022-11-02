#include<cstdio>

#define mo 1000000007

using namespace std;

struct lhy{
	int x,y,time;
}q[4000010],v;

int b[2010][2010],n,x,y,l,h,newx,newy,cha,ans[510],Ans;
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
long long k;

int pow(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%mo;
		x=1ll*x*x%mo;
		m>>=1;
	}
	return nowans;
}

int main()
{
	scanf("%I64d%d",&k,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		b[x+1000][y+1000]=1;
	}
	q[1]=(lhy){0,0,0};
	b[1000][1000]=1;
	l=1;
	h=0;
	while(h<=l)
	{
		v=q[++h];
		if(v.time==k)continue;
		if(v.time==500)continue;
		for(int i=0;i<8;i++)
		{
			newx=v.x+dx[i];
			newy=v.y+dy[i];
			if(b[newx+1000][newy+1000])continue;
			b[newx+1000][newy+1000]=1;
			q[++l]=(lhy){newx,newy,v.time+1};
		}
	}
	if(k<=500)return printf("%d",l),0;
	for(int i=1;i<=l;i++)
		ans[q[i].time]++;
	if(!ans[500])return printf("%d",l),0;
	cha=ans[500]-ans[499];
	k-=500ll;
	k%=mo;
	Ans=(l+1ll*ans[500]*k%mo+1ll*cha*k%mo*(k+1ll)%mo*pow(2,mo-2)%mo)%mo;
	printf("%d",Ans);
}