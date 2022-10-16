#include <stdio.h>
#include <string.h> 
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		int ans=n-k+ (k -  (k+1)/2);
		printf("%d\n",ans);
		for(int i=(k+1)/2;i<=n;i++)
			if(i!=k)printf("%d ",i);
		puts("");
	}
}