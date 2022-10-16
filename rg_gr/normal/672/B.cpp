#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#define int long long
inline int max(int a,int b){return a>b?a:b;
}
//#define __int128 long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57)f=(c=='-'?-1:f),c=getchar();
	while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num*f;
}
char a[100005],b[26];
signed main()
{
	int n=read();
	if(n>26)return puts("-1")&0;
	scanf("%s",a);
	int ans=0;
	for(int i=0;i<n;i++)b[a[i]-97]++;
	for(int i=0;i<26;i++)if(b[i]>1)ans+=b[i]-1;
	printf("%lld\n",ans);
}