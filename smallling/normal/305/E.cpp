#include<cstdio>
#include<cstring>

#define N 5010

using namespace std;

char s[N];
int n,f[N],mex[N];

int check(int l,int r)
{
	int now=0,sg=0;
	for(int i=l;i<=r;i++)
		if(s[i-1]==s[i+1])now++;
		else sg^=f[now],now=0;
	return sg^f[now];
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int now=0;
			if(j-2>=0)now^=f[j-2];
			if(i-j-1>=0)now^=f[i-j-1];
			mex[now]=i;
		}
		int now=0;
		while(mex[now]==i)now++;
		f[i]=now;
	}
	for(int i=2;i<n;i++)
		if(s[i-1]==s[i+1]&&((check(2,i-2)^check(i+2,n-1))==0))return printf("First\n%d",i),0;
	puts("Second");
}