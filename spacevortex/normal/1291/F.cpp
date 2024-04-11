#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int n,K,S,num,las,ans;
int del[N],L[N],R[N];
char s[5];
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='Y';
}
void init()
{
	printf("R\n");
	fflush(stdout);
}
void solve(int id)
{
	int i;
	for(i=L[id];i<=R[id];i++)
	{
		if(del[i]==1) continue;
		if(ask(i)==1)
		{
			del[i]=1;ans--;
		}
	}
}
int main()
{
	int i,j,id;
	scanf("%d%d",&n,&K);
	ans=n;
	S=max(K/2,1);
	num=n/S;
	for(i=1;i<=num;i++) L[i]=(i-1)*S+1,R[i]=i*S;
	for(i=1;i<=(num>>1);i++)
	{
		las=-1;
		init();
		solve(i);
		id=i;
		for(j=1;j<num;j++)
		{
			if(j&1) id=(id+j-1)%num+1;
			else  id=(id-j+num-1)%num+1;
			solve(id);
		}
	}
	printf("! %d",ans);
	fflush(stdout);
	return 0;
}