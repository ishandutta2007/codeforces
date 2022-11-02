#include<cstdio>
#include<cstring>

#define mo 1000000007

using namespace std;

int n,length,N,ans,a[1000010],flag[1000010],p[1000010];
char s[1000010];

int getans(int len)
{
	int nowans=1;
	for(int i=1;i<=len;i++)nowans=1ll*nowans*26%mo;
	return nowans;
}

int main()
{
	scanf("%d%d",&length,&N);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[i]!=s[j+1])j=p[j];
		if(s[i]==s[j+1])j++;
		p[i]=j;
	}
	for(int now=p[n];now;now=p[now])flag[n-now+1]=1;
	if(N==0)return printf("%d",getans(length)),0;
	else
	{
		scanf("%d",&a[1]);
		ans=getans(a[1]-1);
		for(int i=2;i<=N;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]-a[i-1]<n)
			{
				if(!flag[a[i]-a[i-1]+1])return puts("0"),0;
			}
			else ans=(1ll*ans*getans(a[i]-a[i-1]-n))%mo;
		}
		ans=(1ll*ans*getans(length-a[N]-n+1))%mo;
		printf("%d",ans);
	}
}