#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

long long now;
int n,a,b,sqrtn,f[30010][30];

bool check(int a,int b)
{
	now=1;
	for(int i=1;i<=b;i++)
	{
		now=now*a;
		if(now>=n)return 1;
	}
	return 0;
}

//0  1 
int work(int a,int b)
{
	if(a>=sqrtn&&b==1)
		return (n-a)&1;
	if(f[a][b]!=-1)return f[a][b];
	if(a==1&&check(2,b))return f[a][b];
	f[a][b]=1;
	if(!check(a+1,b)&&work(a+1,b))f[a][b]=0;
	if(!check(a,b+1)&&work(a,b+1))f[a][b]=0;
	return f[a][b]; 
}

int main()
{
	scanf("%d%d%d",&a,&b,&n);
	sqrtn=(int)sqrt(n);
	if(sqrtn*sqrtn<n)sqrtn++;
	if(a==1)
	{
		now=1;
		for(int i=1;i<=b;i++)
		{
			now=now*2;
			if(now>=n)return puts("Missing"),0;
		}
	}
	memset(f,-1,sizeof(f));
	f[a][b]=work(a,b);
	if(f[a][b]==0)puts("Masha");
	else puts("Stas"); 
}