#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=1005;
int n,k;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	scanf("%d%d",&n,&k);
	int m=n-1,ans=0;
	while(m) ++ans,m/=k;
	printf("%d\n",ans);
	rep(i,0,n-1) rep(j,i+1,n-1)
	{
		int x=i,y=j,c=0;
		while(x!=y) x/=k,y/=k,++c;
		printf("%d ",c);
	}
	puts("");
	return 0;
}