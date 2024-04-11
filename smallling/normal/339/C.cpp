#include<cstdio>

using namespace std;

int i,j,bo,a[101],jl[100001],m,b[10];
char s[101];

void ss(int x,int o)
{
	if(x==m)
	{
		bo=1;
		return;
	}
	if(bo)return;
	for(int i=1;i<=10;i++)
	if(a[i]&&(o!=i)&&(b[x&1]+i>b[(x-1)&1]))
	{
		b[x&1]+=i;
		jl[x]=i;
		ss(x+1,i);
		if(bo)return;
		b[x&1]-=i;
	}
}

int main()
{
	scanf("%s",s+1);
	scanf("%d",&m);
	for(i=1;i<=10;i++)
	a[i]=s[i]-'0';
	ss(0,0);
	if(bo==1){printf("YES\n");for(i=0;i<m;i++)printf("%d ",jl[i]);}
	else printf("NO");
}