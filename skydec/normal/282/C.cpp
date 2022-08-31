#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
char str[1100000],stt[1100000];
int main()
{
	scanf("%s",str+1);
	scanf("%s",stt+1);
	if(strlen(str+1)!=strlen(stt+1))
	{
		printf("NO\n");return 0;
	}
	int n=strlen(str+1);
	if(n==1&&str[1]!=stt[1]){printf("NO\n");return 0;}
	int f=0;int f2=0;
	for(int i=1;i<=n;i++)f|=(str[i]=='1'),f2|=(stt[i]=='1');
	if(f==f2)printf("%YES\n");else printf("NO\n");
	return 0;
}