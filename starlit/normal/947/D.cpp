#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,q,sum[N<<1],lst[N<<1];
char S[N<<1];
int l,r,b1,a1,b2,a2;
int main()
{
	scanf("%s",S+1);
	n=strlen(S+1);
	scanf("%s%d",S+n+1,&q);
	m=strlen(S+1);
	for(int i=1;i<=m;i++)
	sum[i]=sum[i-1]+(S[i]!='A'),
	lst[i]=S[i]=='A'?lst[i-1]+1:0;
	while(q--)
	{
		scanf("%d%d",&l,&r),a1=min(lst[r],r-l+1),b1=sum[r]-sum[l-1];
		scanf("%d%d",&l,&r),l+=n,r+=n,
		a2=min(r-l+1,lst[r]),b2=sum[r]-sum[l-1];
		if(b1>b2||((b2-b1)&1)){putchar('0');continue;}
		if(b1==b2)
		putchar(a1-a2>=0&&(a1-a2)%3==0?'1':'0');
		else if(b1)
		putchar(a2>a1?'0':'1');
		else
		putchar(a1>a2?'1':'0');
	}
}