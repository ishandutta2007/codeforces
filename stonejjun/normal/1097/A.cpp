#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z; // 
	long long int ans=0;
	char aa[10],bb[10],cc[10],dd[10],ee[10],ff[10];
	scanf("%s",aa);
	scanf("%s %s %s %s %s",bb,cc,dd,ee,ff);
	if(aa[0]==bb[0]||aa[1]==bb[1])
	{
		printf("YES");
		return 0;
	}
	if(aa[0]==cc[0]||aa[1]==cc[1])
	{
		printf("YES");
		return 0;
	}
	if(aa[0]==dd[0]||aa[1]==dd[1])
	{
		printf("YES");
		return 0;
	}
	if(aa[0]==ee[0]||aa[1]==ee[1])
	{
		printf("YES");
		return 0;
	}
	if(aa[0]==ff[0]||aa[1]==ff[1])
	{
		printf("YES");
		return 0;
	}
	printf("NO");
	
	
}