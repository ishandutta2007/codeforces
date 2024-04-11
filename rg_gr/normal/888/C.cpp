#include <stdio.h>
char c[114514];
#include <string.h>
inline int max(int a,int b)
{
	return a>b?a:b;
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int d[26],l[26],minn=1919810;//d[i] 
int main()//l[i] 
{
	scanf("%s",c);int i;memset(d,-1,sizeof(d));
	for(i=0;c[i];i++)
	{
		l[c[i]-97]=max(l[c[i]-97],i-d[c[i]-97]);
		d[c[i]-97]=i;
//		printf("l[%c]=%d\n",c[i],l[c[i]-97]);
	}
	for(int ij=0;ij<26;ij++)
		if(l[ij])minn=min(minn,max(l[ij],i-d[ij]));
	printf("%d\n",minn==1919810?1:minn);
	return 0;
}