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
int n,k;
int tmp[100000];
int main()
{
	scanf("%d%d",&n,&k);int u=1;
	for(int i=1;i<=n-1;i++)u+=6;
	printf("%d\n",(u+4)*k);
	for(int i=0;i<n;i++)
	printf("%d %d %d %d\n",(i*6+1)*k,(i*6+3)*k,k*(i*6+5),k*(i*6+2));
	return 0;
}