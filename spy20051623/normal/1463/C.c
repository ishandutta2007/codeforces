#include<stdio.h>
#include<math.h>
main()
{
	long long t,x,st,et,sx,ex,lt,lx;
	int m,n,move,cnt,flag,head;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		flag=0;
		ex=0;
		cnt=0;
		scanf("%lld%lld",&t,&x);
		st=t;
		sx=ex;
		ex=x;
		et=st+abs(ex-sx);
		if(sx<ex)head=1;
		else head=-1;
		n--;
		while(n--)
		{
			lt=t;
			lx=x;
			scanf("%lld%lld",&t,&x);
			if(t<et)move=1;
			else move=0;
			if(move)
			{
				if((lx-sx-(lt-st)*head)*(lx-sx-(t-st)*head)<=0)cnt++;
			}
			else
			{
				if((lx-sx-(lt-st)*head)*(lx-ex)<=0)cnt++;
			}
			if(move)
			{
				continue;
			}
			else
			{
				st=t;
				sx=ex;
				ex=x;
				et=st+abs(ex-sx);
				if(sx<ex)head=1;
				else head=-1;
			}
		}
		lt=t;
		lx=x;
		if((lx-sx-(lt-st)*head)*(lx-ex)<=0)cnt++;
		printf("%d\n",cnt);
	}
}