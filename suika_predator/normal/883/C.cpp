#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int f,T,t0,a1,t1,p1,a2,t2,p2;
inline long long calc1(int x,int y)
{
	int tmp=(long long)x*a1+(long long)y*a2;
	if(tmp<=f)return (long long)x*a1*t1+(long long)y*a2*t2+(long long)(f-tmp)*t0;
	else return (long long)x*a1*t1+(long long)(f-(x*a1))*t2;
}
inline long long calc2(int x,int y)
{
	int tmp=(long long)x*a1+(long long)y*a2;
	if(tmp<=f)return (long long)x*a1*t1+(long long)y*a2*t2+(long long)(f-tmp)*t0;
	else return (long long)(f-(y*a2))*t1+(long long)y*a2*t2;
}
int main()
{
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(scanf("%d%d%d%d%d%d%d%d%d",&f,&T,&t0,&a1,&t1,&p1,&a2,&t2,&p2)!=EOF){
	if((long long)min(t0,min(t1,t2))*f>T){printf("-1\n");continue;}
	if(t1>=t0&&t2>=t0)
	{
		printf("0\n");
		continue;
	}
	if(t1>=t0)
	{
		int y=10000000;
		while(y>0&&(long long)t0*f+(long long)(t2-t0)*(y-1)<=T)y--;
		printf("%I64d\n",(long long)((y+a2-1)/a2)*p2);
		continue;
	}
	if(t2>=t0)
	{
		int x=10000000;
		while(x>0&&(long long)t0*f+(long long)(t1-t0)*(x-1)<=T)x--;
		printf("%I64d\n",(long long)((x+a1-1)/a1)*p1);
		continue;
	}
	long long minn=0x3f3f3f3f3f3f3f3fll;
	{
		int y=10000000/a2+1;
		for(int x=0;x<=10000000;x++)
		{
			if(calc1(x,y)>T)continue;
			while(y>0&&calc1(x,y-1)<=T)y--;
			minn=min(minn,(long long)x*p1+(long long)y*p2);
			if(y==0)break;
		}
	}
	{
		int x=10000000/a1+1;
		for(int y=0;y<=10000000;y++)
		{
			if(calc2(x,y)>T)continue;
			while(x>0&&calc2(x-1,y)<=T)x--;
			minn=min(minn,(long long)x*p1+(long long)y*p2);
			if(x==0)break;
		}
	}
	printf("%I64d\n",minn);
	}
	return 0;
}