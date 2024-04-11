#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000
using namespace std;
typedef long long ll;
ll a,b;
int cnta,cntb;
int digit[10];
int ans[30];
int numa[30],numb[30];
bool valid(int len)
{
	int tmp[10];
	for(int i=0;i<=9;i++)
		tmp[i]=digit[i];	
	for(int i=len;i<cnta;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(tmp[j]>0)
			{
				tmp[j]--;
				if(j>numb[i]) return false;
				else if(j<numb[i]) return true;
				break;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%I64d%I64d",&a,&b);
	cnta=0,cntb=0;
	ll t=a;
	memset(digit,0,sizeof(digit));
	while(t>0)
	{
		digit[t%10]++;
		numa[cnta++]=t%10;
		t=t/10;
	}
	for(int i=0;i<cnta/2;i++)
		swap(numa[i],numa[cnta-1-i]);
	t=b;
	while(t>0)
	{
		numb[cntb++]=t%10;
		t=t/10;
	}
	for(int i=0;i<cntb/2;i++)
		swap(numb[i],numb[cntb-1-i]);
	if(cnta<cntb)
	{
		sort(numa,numa+cnta);
		for(int i=cnta-1;i>=0;i--)
			printf("%d",numa[i]);
		return 0;
	}
 
	bool f=true;
	for(int i=0;i<cnta;i++)
	{
		if(!f)
		{
			for(int j=9;j>=0;j--)
			while(digit[j]>0)
			{
				printf("%d",j);
				digit[j]--;
			}
			return 0;
		}
		for(int j=9;j>=0;j--)
		{
			if(digit[j]>0&&(j==numb[i]))
			{
				digit[j]--;
				if(valid(i+1)) {printf("%d",j);break;}
				digit[j]++;
			}
			else if(digit[j]>0&&j<numb[i])
			{
				digit[j]--;
				printf("%d",j);
				f=false;
				break;
			}
		}
	}
	return 0;
}