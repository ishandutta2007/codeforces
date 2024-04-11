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
char str[305];int peo=0;int n;
int main()
{
	scanf("%s",str+1);n=strlen(str+1);int all=0;
	rep(i,1,n){if(str[i]=='+')peo++;else peo--;if(peo<0)all=max(all,-peo);}
	peo=all;int res=peo;
	rep(i,1,n)
	{
		if(str[i]=='+')peo++;else peo--;
		res=max(res,peo);
	}
	printf("%d\n",res);
	return 0;
}