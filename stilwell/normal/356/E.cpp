#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H 2333
using namespace std;

int n,i,j,k;
char s[100005],pre;
unsigned long long hash[100005],power[100005];
long long ans,Ans,tmp,cal[100005];
int sum[100005][30],h[100005];

unsigned long long calc(int l,int r){return hash[r]-hash[l-1]*power[r-l+1];}
int count(int l,int r,int ch){return sum[r][ch]-sum[l-1][ch];}

void dfs(int l,int r,unsigned long long now)
{
	int k=r-l+1,x;
	if(k>1)tmp+=(long long)k*k;
	x=l-1;
	if(x-k>=1&&calc(x-k,x-1)==now&&count(x-k,x-1,s[x])==0)
	dfs(x-k,x+k,(calc(x-k,x-1)*H+s[x])*power[k]+now);
	x=r+1;
	if(x+k<=n&&calc(x+1,x+k)==now&&count(x+1,x+k,s[x])==0)
	dfs(x-k,x+k,(now*H+s[x])*power[k]+calc(x+1,x+k));
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;++i)s[i]-='a'-1;
	for(i=1;i<=n;++i)hash[i]=hash[i-1]*H+s[i];
	power[0]=1;
	for(i=1;i<=n;++i)power[i]=power[i-1]*H;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=26;++j)sum[i][j]+=sum[i-1][j];
		++sum[i][s[i]];
	}
	for(k=1;k<n;k=k*2+1)
	for(i=1;i<=n;++i)
	if(i-k>=1&&i+k<=n)
	if(h[i-k/2-1]>=k/2&&h[i+k/2+1]>=k/2)
	if(calc(i-k,i-1)==calc(i+1,i+k)&&count(i-k,i+k,s[i])==1)
	{
		h[i]=k;j=2*k+1;
		ans+=(long long)j*j;
		cal[i-k]+=(long long)j*j;
		cal[i+k+1]-=(long long)j*j;
	}
	for(i=1;i<=n;++i)cal[i]+=cal[i-1];
	Ans=ans;
	for(i=1;i<=n;++i)
	{
		pre=s[i];
		for(s[i]=1;s[i]<=26;++s[i])
		{
			tmp=ans-cal[i];
			dfs(i,i,s[i]);
			for(k=1;k<=n;k=k*2+1)
			if(i-k>=1&&i+k<=n&&calc(i-k,i-1)==calc(i+1,i+k)&&count(i-k,i-1,s[i])+count(i+1,i+k,s[i])==0&&h[i-k/2-1]>=k/2&&h[i+k/2+1]>=k/2)
			dfs(i-k,i+k,(calc(i-k,i-1)*H+s[i])*power[k]+calc(i+1,i+k));else break;
			if(tmp>Ans)Ans=tmp;
		}
		s[i]=pre;
	}
	printf("%I64d\n",Ans+n);
}