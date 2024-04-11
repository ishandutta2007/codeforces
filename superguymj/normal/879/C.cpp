#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,bin[20],x,ans_or,ans_and,ans_xor;
char s[10];

int main()
{
	scanf("%d",&n);
	rep(i,0,9) bin[i]=-1;
	rep(i,1,n)
	{
		scanf("%s%d",s,&x);
		if(s[0]=='|')
			rep(j,0,9) if(x&(1<<j)) bin[j]=1;
		if(s[0]=='&')
			rep(j,0,9) if(!(x&(1<<j))) bin[j]=0;
		if(s[0]=='^')
			rep(j,0,9)
				if(x&(1<<j))
				{
					if(bin[j]==-1) bin[j]=2;
					else if(bin[j]==2) bin[j]=-1;
					else if(bin[j]==0) bin[j]=1;
					else bin[j]=0;
				}
	}
	rep(i,0,9)
	{
		if(bin[i]==1) ans_or|=(1<<i);
		if(bin[i]!=0) ans_and|=(1<<i);
		if(bin[i]==2) ans_xor|=(1<<i);
	}
	puts("3");
	printf("| %d\n",ans_or);
	printf("& %d\n",ans_and);
	printf("^ %d\n",ans_xor);
	return 0;
}