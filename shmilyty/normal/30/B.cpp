#include<bits/stdc++.h>
using namespace std;
int y,m,d;
int a,b,c;
bool judge(int Y,int M,int D)
{
	if(M>12)
		return 0;
	if((M==1||M==3||M==5||M==7||M==8||M==10||M==12)&&D>31)
		return 0;
	if((M==4||M==6||M==9||M==11)&&D>30)
		return 0;
	if(M==2)
	{
		if(Y%400==0||(Y%4==0&&Y%100!=0))
		{
			if(D>29)
				return 0;
		}	
		else
			if(D>28)
				return 0; 
	}
	if(y-Y>18)
		return 1; 
	if(y-Y==18)
	{
		if(m>M)
			return 1;
		if(m==M)
			if(d>=D)
				return 1;
	}
	return 0;
}
int main()
{
	scanf("%d.%d.%d",&d,&m,&y);
	scanf("%d.%d.%d",&a,&b,&c);
	if(judge(a,b,c)||judge(a,c,b)||judge(b,a,c)||judge(b,c,a)||judge(c,a,b)||judge(c,b,a))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}