#include<cstdio>
#include<map>

using namespace std;

map<int,int>a;

int t,n,sum[5],b[5],pow[5];
char s[10010];

int work(char ch)
{
	if(ch=='G')return 1;
	if(ch=='H')return 2;
	if(ch=='R')return 3;
	if(ch=='S')return 4;
}

void dfs(int x,long long y)
{
	if(a[y])return;
	a[y]=1;
	if(x==n)
	{
		int Min=0x7f7f7f7f;
		for(int i=1;i<=4;i++)
			if(sum[i]<Min)Min=sum[i];
		for(int i=1;i<=4;i++)
			if(sum[i]==Min)
				b[i]=1;
		return;
	}
	int Min;
	int i=x+1;
	if(s[i]!='?')
	{
		sum[work(s[i])]++;
		dfs(i,y+pow[work(s[i])]);
		sum[work(s[i])]--;
	}
	else
	{
		Min=0x7f7f7f7f;
		for(int j=1;j<=4;j++)
			if(sum[j]<Min)Min=sum[j];
		for(int j=1;j<=4;j++)
			if(sum[j]==Min)
			{
				sum[j]++;
				dfs(i,y+pow[j]);
				sum[j]--;
			}
	}
}

int main()
{
	pow[1]=1;
	for(int i=2;i<=4;i++)pow[i]=pow[i-1]*2333333ll;
		scanf("%d",&n);
		scanf("%s",s+1);
		dfs(0,0);
		for(int i=1;i<=4;i++)
			if(b[i])
			{
				if(i==1)puts("Gryffindor");
				if(i==2)puts("Hufflepuff");
				if(i==3)puts("Ravenclaw");
				if(i==4)puts("Slytherin");
				b[i]=0;
			}
}