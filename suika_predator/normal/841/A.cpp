#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,maxx;
char buf[233];
int cnt[1000];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",buf);
	for(int i=0;i<n;i++)
	{
		cnt[buf[i]]++;
		if(cnt[buf[i]]>maxx)maxx=cnt[buf[i]];
	}
	if(maxx>m)printf("NO\n");
	else printf("YES\n");
	return 0;
}