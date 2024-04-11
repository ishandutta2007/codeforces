#include<stdio.h>
using namespace std;
bool big(long x)
{
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)return true;
	return false;
}
bool run(long x)
{
	return ((x%100!=0)&&(x%4==0))||(x%400==0);
}
struct date
{
	long y,m,d;
	void getafter()
	{
		d++;
		if(d>28)
		{
			if(m==2)
			{
				if(d==29&&!run(y))
				{
					m=3;d=1;
				}
				else
				if(d==30&&run(y))
				{
					m=3;d=1;
				}
			}
			else
			if(big(m))
			{
				if(d>31)
				{
					d=1;m++;
					if(m==13)
					{
						m=1;y++;
					}
				}
			}
			else
			if(d>30)
			{
				d=1;m++;
				if(m==13)
				{
					m=1;y++;
				}
			}
		}
	}
	bool same(date k)
	{
		return (k.y==y)&&(k.d==d)&&(k.m==m);
	}
	bool biger(date k)
	{
		if(k.y!=y)return y>k.y;
		if(k.m!=m)return m>k.m;
		if(k.d!=d)return d>k.d;
	}			
};
int main()
{
	date st;date ed;long ans=0;
	scanf("%ld:%ld:%ld",&st.y,&st.m,&st.d);
	scanf("%ld:%ld:%ld",&ed.y,&ed.m,&ed.d);
	if(st.biger(ed))
	{
		long tmp;
		tmp=st.y;st.y=ed.y;ed.y=tmp;
		tmp=st.m;st.m=ed.m;ed.m=tmp;
		tmp=st.d;st.d=ed.d;ed.d=tmp;
	}
	while(!st.same(ed))
	{
		ans++;st.getafter();
	}
	printf("%ld\n",ans);
	return 0;
}