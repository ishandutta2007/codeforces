#include <stdio.h>
#include <string.h>
#include <stdlib.h>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int query(int l,int r)
{
	if(l==r)return 0;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}
int main()
{
	int n=read();
	int pos=query(1,n);
	int x=query(1,pos);
	if(x==pos)
	{
		int l=1,r=pos-1,ans=pos-1;
		while(l<=r)
		{
			int m=l+r>>1;
			if(query(m,pos)==pos)ans=m,l=m+1;
			else r=m-1;
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
	else
	{
		int l=pos+1,r=n,ans=pos+1;
		while(l<=r)
		{
			int m=l+r>>1;
			if(query(pos,m)==pos)ans=m,r=m-1;
			else l=m+1;
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
}