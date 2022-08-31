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
#define MAXN 5005
char str[MAXN];int n;int q;int sum[MAXN][MAXN];
void init()
{
	rep(i,1,n)
	{
		sum[i][i]=1;
		rep(j,1,min(i-1,n-i))
		if(str[i+j]==str[i-j])sum[i-j][i+j]=1;
		else break;
	}
	rep(i,1,n-1)
	if(str[i]==str[i+1])
	{
		sum[i][i+1]=1;
		rep(j,1,min(i-1,n-i-1))
		if(str[i-j]==str[i+1+j])sum[i-j][i+1+j]=1;
		else break;
	}
		
}
int main()
{
	scanf("%s",str+1);n=strlen(str+1);scanf("%d",&q);init();
	rep(len,2,n)rep(i,1,n-len+1)
	{
		sum[i][i+len-1]+=sum[i+1][i+len-1]+sum[i][i+len-2]-sum[i+1][i+len-2];
		//printf("%d %d %d\n",i,i+len-1,sum[i][i+len-1]);
	}
	while(q--){int l,r;scanf("%d%d",&l,&r);printf("%d\n",sum[l][r]);}
	return 0;
}