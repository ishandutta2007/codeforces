#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int n,num,val,t,cs;
char s[N];
int a[N],b[N],p[N];
void act(int len)
{
	p[++num]=len;
	if(len!=1)
	{
		cs^=1;val+=t*(len+1);t*=-1;
	}
}
void Solve()
{
	int i,now;
	scanf("%d",&n);
	scanf("%s",s+1);for(i=1;i<=n;i++) a[i]=s[i]-48;
	scanf("%s",s+1);for(i=1;i<=n;i++) b[i]=s[i]-48;
	num=0;
	val=0;t=1;cs=0;
	for(i=n;i>=1;i--)
	{
		now=a[val+t*1]^cs;
		//printf("P %d %d  %d\n",val,t,cs);
		if(now!=(b[i]^1)) act(1);
		act(i);
	}
	printf("%d ",num);
	for(i=1;i<=num;i++) printf("%d ",p[i]);
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
}