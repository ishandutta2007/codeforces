#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int n,sum=0,tot=0,cnt,h1,h2,h;
char s[N];
int val[N],w[N];
int main()
{
	int i;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='?') val[i]=-1,tot++;
		else val[i]=s[i]-'0';
	}
	sum=0;cnt=0;h1=0;h2=0;
	for(i=1;i<=n;i++)
	{
		w[i]=val[i];
		if(w[i]==-1) 
		{
			if(cnt<(tot>>1))
			{
				cnt++;
				if(i<=(n>>1)) w[i]=0;
				else w[i]=9;
			}
			else if(i<=(n>>1)) h1++;
			else h2++;
		}
		if(w[i]!=-1)
		{
			if(i<=(n>>1)) sum+=w[i];
			else sum-=w[i];
		}
	}
	if(sum<0)
	{
		sum=-sum;h=h1;
		if(abs(sum)>h*9)
		{
			puts("Monocarp");
			return 0;
		}
	}
	sum=0;cnt=0;h1=h2=0;
	for(i=1;i<=n;i++)
	{
		w[i]=val[i];
		if(w[i]==-1) 
		{
			if(cnt<(tot>>1))
			{
				cnt++;
				if(i<=(n>>1)) w[i]=9;
				else w[i]=0;
			}
			else if(i<=(n>>1)) h1++;
			else h2++;
		}
		if(w[i]!=-1)
		{
			if(i<=(n>>1)) sum+=w[i];
			else sum-=w[i];
		}
	}
	//printf("P%d %d\n",sum,tot);
	if(sum>0)
	{
		h=h2;
		if(abs(sum)>h*9)
		{
			puts("Monocarp");
			return 0;
		}
	}
	puts("Bicarp");
	return 0;
}