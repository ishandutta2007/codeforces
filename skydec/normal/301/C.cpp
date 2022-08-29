#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int main()
{
	rep(i,0,9)printf("??%d>>%d??\n",i,i);
	printf("??>>?\n");
	rep(i,0,8)printf("%d?<>%d\n",i,i+1);
	printf("9?>>?0\n");
	printf("?<>1\n");
	printf(">>??\n");
	return 0;
}