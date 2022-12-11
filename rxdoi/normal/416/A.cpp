#include<cstdio>
#include<iostream>
using namespace std;

const int oo=2e9;
char c[20],Ans[5];
int n,x,L,R;

int main()
{
	scanf("%d",&n);
	L=-oo;R=oo;
	for (int i=0;i<n;i++)
	{
		scanf("%s%d%s",c,&x,Ans);
		if (c[0]=='>'&&c[1]!='=')
			{if (Ans[0]=='Y') L=max(L,x+1);else R=min(R,x);} else
		if (c[0]=='<'&&c[1]!='=')
			{if (Ans[0]=='Y') R=min(R,x-1);else L=max(L,x);} else
		if (c[0]=='>'&&c[1]=='=')
			{if (Ans[0]=='Y') L=max(L,x);else R=min(R,x-1);} else
		if (c[0]=='<'&&c[1]=='=')
			{if (Ans[0]=='Y') R=min(R,x);else L=max(L,x+1);}
	}
	if (L>R) printf("Impossible\n");else printf("%d\n",L);
	return 0;
}