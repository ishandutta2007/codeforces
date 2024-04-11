#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,i,j,k,l;
char s[100005],ch;
bool del[100005];
unsigned long long Hash[100005],power[100005];

unsigned long long get(int l,int r){return Hash[r]-Hash[l-1]*power[r-l+1];}

bool check(int len)
{
	int i,l1,l2,l,r,mid;
	for(i=len;i+len<=n;i+=len)
	if(s[i]==s[i+len])
	{
		l1=l2=0;
		l=1;r=len;
		while(l<=r)
		{
			mid=l+r>>1;
			if(mid<=i&&get(i-mid+1,i)==get(i-mid+1+len,i+len))l1=mid,l=mid+1;
			else r=mid-1;
		}
		l=1;r=len;
		while(l<=r)
		{
			mid=l+r>>1;
			if(i+mid-1+len<=n&&get(i,i+mid-1)==get(i+len,i+mid-1+len))l2=mid,l=mid+1;
			else r=mid-1;
		}
		if(l1+l2-1>=len)return true;
	}
	return false;
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	power[0]=1;
	for(i=1;i<=n;++i)power[i]=power[i-1]*233;
	for(i=1;i<=n;++i)Hash[i]=Hash[i-1]*233+s[i];
	for(l=1;l+l<=n;++l)
	if(check(l))
	{
		for(i=1;i+l<=n;++i)del[i]=s[i]==s[i+l];
		for(i=1;i+l<=n;++i)
		if(del[i])
		{
			for(j=i;j+l<n&&del[j+1];++j);
			for(k=j-(j-i+1)%l+1;k<=j;++k)
			del[k]=false;
			i=j;
		}
		k=n;n=0;
		for(i=1;i<=k;++i)
		if(!del[i])
		{
			ch=s[i];s[++n]=ch;
		}else del[i]=false;
		for(i=1;i<=n;++i)Hash[i]=Hash[i-1]*233+s[i];
	}
	for(i=1;i<=n;++i)putchar(s[i]);printf("\n");
}