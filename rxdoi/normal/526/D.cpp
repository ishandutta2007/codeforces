#include<cstdio>
#include<cstring>
using namespace std;

const int N=1000000+19;
int n,k,A,B,C,Fail[N];
char s[N];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	
	for (int i=2,j=0;i<=n;i++)
	{
		while (j&&s[i]!=s[j+1]) j=Fail[j];
		if (s[i]==s[j+1]) j++;
		Fail[i]=j;
	}

	for (int i=1;i<=n;i++)
	{
		C=i/(i-Fail[i]);
		if (i%(i-Fail[i])==0) putchar((C-1LL*(C%k)*(k+1)>=0)+'0');
			else putchar(((C-k-1LL*(C%k)*(k+1))>=0)+'0');
	}
	puts("");
}